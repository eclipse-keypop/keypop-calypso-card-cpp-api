/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {
namespace spi {

/**
 * SPI provided by the crypto extension associated with the current transaction, enriching the card
 * transaction command set with specific crypto commands such as for example computation and
 * signature verification operations.
 *
 * @since 2.0.0
 */
class CardTransactionCryptoExtension {
public:
    /**
     * Virtual destructor
     */
    virtual ~CardTransactionCryptoExtension() = default;
};

} /* namespace spi */
} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
