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
 * Indicates a communication error with the crypto module (e.g. timeout with the reader or the
 * computing unit, network error, etc.).
 *
 * @since 2.0.0
 */
class CryptoIOException final : public std::runtime_error {
public:
    /**
     * Encapsulates a lower level exception.
     *
     * @param message Message to identify the exception context.
     * @param cause The cause.
     * @since 1.0.0
     */
    CryptoIOException(const std::string& message, const std::shared_ptr<std::exception> cause)
    : std::runtime_error(message) {
        (void)cause;
    }
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
