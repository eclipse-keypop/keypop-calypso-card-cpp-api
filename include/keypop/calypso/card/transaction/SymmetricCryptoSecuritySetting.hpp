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

#include <cstdint>

#include "keypop/calypso/card/WriteAccesLevel.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Security setting for a Calypso card transaction secured by "symmetric" key
 * cryptographic algorithms (e.g. SAM).
 *
 * <p>An instance of this interface can be obtained via the method {@link
 * CalypsoCardApiFactory::createSymmetricCryptoSecuritySetting(
 *     SymmetricCryptoCardTransactionManagerFactory)}.
 *
 * @since 2.0.0
 */
class SymmetricCryptoSecuritySetting {
public:
    /**
     * Enables multiple session mode to allow more changes to the card than the
     * session buffer can handle.
     *
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting& enableMultipleSession() = 0;

    /**
     * Enables the ratification mechanism to handle the early removal of the
     * card preventing the terminal from receiving the acknowledgement of the
     * session closing.
     *
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting& enableRatificationMechanism() = 0;

    /**
     * Enables the PIN transmission in plain text.
     *
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting& enablePinPlainTransmission() = 0;

    /**
     * Enables the retrieval of both loading and debit log records.
     *
     * <p>The default value is false.
     *
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting& enableSvLoadAndDebitLog() = 0;

    /**
     * Allows the SV balance to become negative.
     *
     * <p>The default value is false.
     *
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting& authorizeSvNegativeBalance() = 0;

    /**
     * Disables the automatic merging of the "Open Secure Session" command with
     * a possible "Read Record" command.
     *
     * <p>By default, this optimization is performed when the command that
     * follows the session opening is a "Read Record" command.
     *
     * <p>This mechanism may in some cases be incompatible with the security
     * requirements.
     *
     * @return The current instance.
     * @since 1.6.0
     */
    virtual SymmetricCryptoSecuritySetting& disableReadOnSessionOpening() = 0;

    /**
     * Defines for a given write access level the KIF value to use for cards
     * that only provide KVC.
     *
     * @param writeAccessLevel The write access level.
     * @param kvc The card's KVC value.
     * @param kif The KIF value to use.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided writeAccessLevel is null.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting& assignKif(
        const WriteAccessLevel writeAccessLevel,
        const uint8_t kvc,
        const uint8_t kif)
        = 0;

    /**
     * Defines for a given write access level the default KIF value to use when
     * it could not be determined by any other means.
     *
     * @param writeAccessLevel The write access level.
     * @param kif The KIF value to use.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided writeAccessLevel is null.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting&
    assignDefaultKif(const WriteAccessLevel writeAccessLevel, const uint8_t kif)
        = 0;

    /**
     * Defines for a given write access level the KVC value to use for cards
     * that do not provide KVC.
     *
     * @param writeAccessLevel The session level.
     * @param kvc The KVC to use.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided writeAccessLevel is null.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting&
    assignDefaultKvc(const WriteAccessLevel writeAccessLevel, const uint8_t kvc)
        = 0;

    /**
     * Adds an authorized session key defined by its KIF and KVC values.
     *
     * <p>By default, all keys are accepted. <br>
     * If at least one key is added using this method, then only authorized keys
     * will be accepted.
     *
     * @param kif The KIF value.
     * @param kvc The KVC value.
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting&
    addAuthorizedSessionKey(const uint8_t kif, const uint8_t kvc)
        = 0;

    /**
     * Adds an authorized Stored Value key defined by its KIF and KVC values.
     *
     * <p>By default, all keys are accepted. <br>
     * If at least one key is added using this method, then only authorized keys
     * will be accepted.
     *
     * @param kif The KIF value.
     * @param kvc The KVC value.
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting&
    addAuthorizedSvKey(const uint8_t kif, const uint8_t kvc)
        = 0;

    /**
     * Sets the KIF/KVC pair of the PIN verification ciphering key.
     *
     * <p>The default value for both KIF and KVC is 0.
     *
     * @param kif The KIF value.
     * @param kvc The KVC value.
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting&
    setPinVerificationCipheringKey(const uint8_t kif, const uint8_t kvc)
        = 0;

    /**
     * Sets the KIF/KVC pair of the PIN modification ciphering key.
     *
     * <p>The default value for both KIF and KVC is 0.
     *
     * @param kif The KIF value.
     * @param kvc The KVC value.
     * @return The current instance.
     * @since 1.0.0
     */
    virtual SymmetricCryptoSecuritySetting&
    setPinModificationCipheringKey(const uint8_t kif, const uint8_t kvc)
        = 0;

    /**
     * Prepares the cryptographic module for the next transaction by
     * anticipating all security context configuration operations.
     *
     * <p>This feature is only useful if the currently allocated cryptographic
     * module will be used for the next transaction. It is particularly relevant
     * to optimize the transaction time in a ticketing context of user card
     * validation.
     *
     * <p>For this optimization to be effective, it is necessary to call this
     * method at the very end
     * of the current transaction, i.e. <u>after</u> having notified the user of the access right
     * (e.g. after opening the gate).
     *
     * @throw CryptoException If an error occurred when computing a crypto
     * operation.
     * @throw CryptoIOException If a communication error with the crypto module
     * (e.g. timeout with the reader or the computing unit, network error,
     * etc.).
     * @since 2.0.0
     */
    virtual void initCryptoContextForNextTransaction() = 0;
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
