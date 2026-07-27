/******************************************************************************
 * Copyright (c) 2025 Calypso Networks Association https://calypsonet.org/    *
 *                                                                            *
 * This program and the accompanying materials are made available under the   *
 * terms of the MIT License which is available at                             *
 * https://opensource.org/licenses/MIT.                                       *
 *                                                                            *
 * SPDX-License-Identifier: MIT                                               *
 ******************************************************************************/

#pragma once

#include <memory>
#include <stdexcept>
#include <string>

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Indicates that the certificate is invalid.
 *
 * <p>This exception is thrown when a certificate fails validation checks. This
 * includes issues with the certificate's signature validity, as well as
 * problems with other essential fields of the certificate, such as the validity
 * period, issuer and subject details, and any relevant constraints or
 * extensions. It signifies that the certificate does not conform to the
 * expected standards and requirements, either due to incorrect signing,
 * expiration, revocation, or other compliance failures.
 *
 * @since 2.1.0
 */
class InvalidCertificateException final : public std::runtime_error {
public:
    /**
     * @param message The message to identify the exception context.
     * @since 2.1.0
     */
    explicit InvalidCertificateException(const std::string& message)
    : std::runtime_error(message) {
    }

    /**
     * Encapsulates a lower level exception.
     *
     * @param message Message to identify the exception context.
     * @param cause The cause.
     * @since 2.1.0
     */
    InvalidCertificateException(
        const std::string& message, const std::exception& /*cause*/)
    : std::runtime_error(message) {
    }
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
