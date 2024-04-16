/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Indicates that the card requires an unauthorized session key.
 *
 * @since 1.0.0
 */
class UnauthorizedKeyException : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 1.0.0
     */
    explicit UnauthorizedKeyException(const std::string& message)
    : std::runtime_error(message) {
    }
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
