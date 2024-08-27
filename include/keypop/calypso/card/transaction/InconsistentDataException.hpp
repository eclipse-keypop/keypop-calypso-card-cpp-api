/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <exception>
#include <string>

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Indicates the detection of inconsistent data related to one of the following cases:
 *
 * <ul>
 *   <li>A de-synchronization of the APDU exchanges. This means that the number of APDU responses is
 *       different from the number of APDU requests.
 *   <li>An inconsistency in the card data. This can happen, for example, if the data read in
 *       session is different from the data read outside the session.
 * </ul>
 *
 * @since 1.2.0
 */
class InconsistentDataException final : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 1.2.0
     */
    explicit InconsistentDataException(const std::string& message)
    : std::runtime_error(message) {
    }
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
