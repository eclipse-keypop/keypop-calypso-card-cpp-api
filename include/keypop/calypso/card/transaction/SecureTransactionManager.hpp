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

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Contains operations common to all card transactions secured by cryptographic algorithms.
 *
 * <p>See {@link TransactionManager} parent interface for more information and details of others
 * available card operations.
 *
 * @param <T> The type of the lowest level child object.
 * @since 2.0.0
 */
template <typename T>
class SecureTransactionManager : public SecureTransactionManager<T> {
public:
    /**
     * Returns the associated {@link CardTransactionCryptoExtension} instance.
     *
     * @param cryptoExtensionClass The class of the crypto extension.
     * @param <E> The generic type of the expected crypto extension.
     * @return A non-null {@link CardTransactionCryptoExtension}.
     * @throw IllegalArgumentException If the provided class is null.
     * @since 2.0.0
     */
    virtual std::shared_ptr<CardTransactionCryptoExtension>
    getCryptoExtension(const std::type_info& cryptoExtensionClass) = 0;

    /**
     * Schedules the execution of a "Close Secure Session" command.
     *
     * <p>The ratification mechanism is disabled by default but can be enabled via the {@link
     * SymmetricCryptoSecuritySetting#enableRatificationMechanism()} method.
     *
     * <p>In this case, a ratification command is added after the "Close Secure Session" command
     * when the communication is done in contactless mode.
     *
     * @return The current instance.
     * @throw IllegalStateException In the following cases:
     *     <ul>
     *       <li>No secure session is opened and no secure session opening is prepared
     *       <li>A secure session closing is already prepared
     *       <li>A secure session canceling is prepared
     *     </ul>
     *
     * @since 1.6.0
     */
    virtual SecureTransactionManager& prepareCloseSecureSession() = 0;

    /**
     * Schedules the execution of a special "Close Secure Session" command in order to abort the
     * current secure session.
     *
     * <p>This command will be executed in safe mode and will not raise any exceptions.
     *
     * @return The current instance.
     * @since 1.6.0
     */
    virtual SecureTransactionManager& prepareCancelSecureSession() = 0;
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
