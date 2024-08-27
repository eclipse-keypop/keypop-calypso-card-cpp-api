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

/**
 * Manager of card transactions secured by symmetric key cryptographic algorithms, compatible with
 * all Calypso products.
 *
 * <p>See {@link SecureSymmetricCryptoTransactionManager} parent interface for more information and
 * details of available card operations.
 *
 * <p>An instance of this interface can be obtained via the method {@link
 * CalypsoCardApiFactory#createSecureRegularModeTransactionManager(CardReader, CalypsoCard,
 * SymmetricCryptoSecuritySetting)}.
 *
 * @since 2.0.0
 */
template <typename T>
class SecureRegularModeTransactionManager : public SecureRegularModeTransactionManager<T> {
public:
    /**
     * Virtual destructor.
     */
    virtual ~SecureRegularModeTransactionManager() = default;
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
