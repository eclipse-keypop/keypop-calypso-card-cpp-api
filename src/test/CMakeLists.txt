# *****************************************************************************
# Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/     *
#                                                                             *
# This program and the accompanying materials are made available under the    *
# terms of the MIT License which is available at                              *
# https://opensource.org/licenses/MIT.                                        *
#                                                                             *
# SPDX-License-Identifier: MIT                                                *
# *****************************************************************************/

SET(EXECTUABLE_NAME keypopcalypsocard_ut)

INCLUDE_DIRECTORIES(

    ${CMAKE_CURRENT_SOURCE_DIR}
)

ADD_EXECUTABLE(

    ${EXECTUABLE_NAME}

    ${CMAKE_CURRENT_SOURCE_DIR}/MainTest.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CalypsoCardApiPropertiesTest.cpp
)

# Add Google Test
INCLUDE(CMakeLists.txt.googletest)

TARGET_LINK_LIBRARIES(

    ${EXECTUABLE_NAME}

    gtest
    gmock
    Keypop::Calypso::Card
)
