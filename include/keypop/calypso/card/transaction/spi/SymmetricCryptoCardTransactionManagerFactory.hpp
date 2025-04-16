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
 * Card transaction manager factory provided by crypto extensions to secure
 * Calypso card transactions secured by "symmetric" key cryptographic algorithms
 * (e.g. SAM).
 *
 * @since 2.0.0
 */
class SymmetricCryptoCardTransactionManagerFactory {
public:
    /**
     * Virtual destructor
     */
    virtual ~SymmetricCryptoCardTransactionManagerFactory() = default;
};

} /* namespace spi */
} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
