# *************************************************************************************************
# Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                         *
#                                                                                                 *
# This program and the accompanying materials are made available under the                        *
# terms of the MIT License which is available at https://opensource.org/licenses/MIT.             *
#                                                                                                 *
# SPDX-License-Identifier: MIT                                                                    *
# *************************************************************************************************/

SET(LIBRARY_NAME keypopcalypsocard)

# Declare this library as header only.
ADD_LIBRARY(
    ${LIBRARY_NAME}
    INTERFACE
)

# Include Keypop Reader CMakeLists details
INCLUDE("CMakeLists.txt.keypop-reader")


TARGET_INCLUDE_DIRECTORIES(
    ${LIBRARY_NAME}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/keypop/calypso/card
)

ADD_LIBRARY(Keypop::Calypso::Card ALIAS ${LIBRARY_NAME})
