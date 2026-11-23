# *****************************************************************************
# Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/     *
#                                                                             *
# This program and the accompanying materials are made available under the    *
# terms of the MIT License which is available at                              *
# https://opensource.org/licenses/MIT.                                        *
#                                                                             *
# SPDX-License-Identifier: MIT                                                *
# *****************************************************************************/

import os
import re

from conan import ConanFile
from conan.tools.build import can_run
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.files import copy, load


class KeypopCalypsoCardCppApiConan(ConanFile):
    name = "keypop-calypso-card-cpp-api"
    license = "MIT"
    author = "Calypso Networks Association <https://calypsonet.org/>"
    url = "https://github.com/eclipse-keypop/keypop-calypso-card-cpp-api"
    homepage = "https://keypop.org/apis/calypso-layer/calypso-card-api/"
    description = "C++ API defining the Eclipse Keypop Terminal Calypso Card interfaces"
    topics = ("keypop", "calypso")

    package_type = "header-library"
    settings = "os", "arch", "compiler", "build_type"

    exports_sources = [
        "include/*",
        "src/*",
        "CMakeLists.txt",
        "LICENSE",
        "NOTICE.md"
    ]

    no_copy_source = True

    options = {
        "with_tests": [True, False]
    }

    default_options = {
        "with_tests": False
    }

    def set_version(self):
        cmake_lists = load(self, os.path.join(self.recipe_folder, "CMakeLists.txt"))
        match = re.search(r"VERSION\s+(\d+\.\d+\.\d+)", cmake_lists)
        self.version = match.group(1)

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("keypop-reader-cpp-api/2.1.1", transitive_headers=True)

    def build_requirements(self):
        if self.options.with_tests:
            # 1.12.1 is the last GoogleTest release still compiling as C++11,
            # matching this project's CMAKE_CXX_STANDARD.
            self.test_requires("gtest/1.12.1")

    def generate(self):
        if self.options.with_tests:
            tc = CMakeToolchain(self)
            tc.variables["BUILD_TESTING"] = True
            tc.generate()
            CMakeDeps(self).generate()

    def build(self):
        if self.options.with_tests:
            cmake = CMake(self)
            cmake.configure()
            cmake.build()
            if can_run(self):
                bin_dir = os.path.join(self.build_folder, "bin")
                if self.settings.os == "Windows":
                    bin_dir = os.path.join(bin_dir, str(self.settings.build_type))
                bin_name = "keypopcalypsocard_ut.exe" if self.settings.os == "Windows" else "keypopcalypsocard_ut"
                self.run(os.path.join(bin_dir, bin_name))

    def package(self):
        copy(self, "LICENSE", src=self.source_folder, dst=os.path.join(self.package_folder, "licenses"))
        copy(self, "*.hpp", src=os.path.join(self.source_folder, "include"), dst=os.path.join(self.package_folder, "include"))
        copy(self, "*.dox", src=os.path.join(self.source_folder, "include"), dst=os.path.join(self.package_folder, "include"))

    def package_info(self):
        self.cpp_info.bindirs = []
        self.cpp_info.libdirs = []
        self.cpp_info.set_property("cmake_file_name", "keypop-calypso-card-cpp-api")
        self.cpp_info.set_property("cmake_target_name", "Keypop::Calypso::Card")

    def package_id(self):
        self.info.clear()
