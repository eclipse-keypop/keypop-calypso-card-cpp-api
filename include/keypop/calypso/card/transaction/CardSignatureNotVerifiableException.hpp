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
 * Indicates that the card has correctly closed the secure session, but that it is impossible to
 * check the authenticity of the card session because the cryptographic module is no more available
 * (timeout, network problem, etc.).
 *
 * @since 1.2.0
 */
class CardSignatureNotVerifiableException final : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 1.2.0
     */
    explicit CardSignatureNotVerifiableException(const std::string& message)
    : std::runtime_error(message) {
    }

    /**
     * Encapsulates a lower level exception.
     *
     * @param message Message to identify the exception context.
     * @param cause The cause.
     * @since 1.2.0
     */
    CardSignatureNotVerifiableException(
        const std::string& message, const std::shared_ptr<std::exception> cause)
    : std::runtime_error(message) {
        (void)cause;
    }
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
