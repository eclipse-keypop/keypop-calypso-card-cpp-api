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

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {
namespace spi {

/**
 * Marker interface for CA certificate parser.
 *
 * <p>The implementation of this interface is provided by the Keypop extensions
 * for asymmetric cryptography.
 *
 * @since 2.1.0
 */
class CaCertificateParser {
public:
    /**
     * Virtual destructor
     */
    virtual ~CaCertificateParser() = default;
};

} /* namespace spi */
} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
