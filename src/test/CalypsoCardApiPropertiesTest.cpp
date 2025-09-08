/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#include <regex>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

/* Keypop Reader */
#include "keypop/calypso/card/CalypsoCardApiProperties.hpp"

using keypop::calypso::card::CalypsoCardApiProperties_VERSION;

TEST(CalypsoCardApiPropertiesTest, versionIsCorrectlyWritten) {
    const std::string& apiVersion = CalypsoCardApiProperties_VERSION;
    const std::regex r("\\d+\\.\\d+");

    ASSERT_TRUE(std::regex_match(apiVersion, r));
}
