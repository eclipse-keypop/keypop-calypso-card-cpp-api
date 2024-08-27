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
 * Indicates that the card signature is incorrect.
 *
 * <p>In the case of a card transaction secured by "symmetrical" cryptography (e.g. SAM), this
 * indicates that the card has correctly closed the secure session, but the card session is not
 * authentic because the MAC of the card is incorrect. This can happen in the following cases:
 *
 * <ul>
 *   <li>The "Digest Authenticate" command status is 6988h;
 *   <li>The "SV Check" command status is 6988h;
 * </ul>
 *
 * In the case of a card transaction secured by "asymmetrical" cryptography (e.g. PKI), this
 * indicates only that the card signature is incorrect.
 *
 * @since 1.2.0
 */
class InvalidCardSignatureException final : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context
     * @since 1.2.0
     */
    explicit InvalidCardSignatureException(const std::string& message)
    : std::runtime_error(message) {
    }

    /**
     * Encapsulates a lower level exception.
     *
     * @param message Message to identify the exception context.
     * @param cause The cause.
     * @since 1.2.0
     */
    InvalidCardSignatureException(
        const std::string& message, const std::shared_ptr<std::exception> cause)
    : std::runtime_error(message) {
        (void)cause;
    }
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
