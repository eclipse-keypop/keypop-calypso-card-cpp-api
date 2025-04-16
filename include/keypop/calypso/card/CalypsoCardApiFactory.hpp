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

#include "keypop/calypso/card/card/CalypsoCard.hpp"
#include "keypop/calypso/card/card/CalypsoCardSelectionExtension.hpp"
#include "keypop/calypso/card/transaction/SearchCommandData.hpp"
#include "keypop/calypso/card/transaction/SecureExtendedModeTransactionManager.hpp"
#include "keypop/calypso/card/transaction/SymmetricCryptoSecuritySetting.hpp"
#include "keypop/calypso/card/transaction/spi/SymmetricCryptoCardTransactionManagerFactory.hpp"
#include "keypop/calypso/reader/CardReader.hpp"

namespace keypop {
namespace calypso {
namespace card {

/**
 * Calypso Card API Factory.
 *
 * @since 2.0.0
 */
class CalypsoCardApiFactory {
public:
    /**
     * Returns a new instance of CalypsoCardSelectionExtension.
     *
     * @return A new instance of CalypsoCardSelectionExtension.
     * @since 2.0.0
     */
    virtual std::shared_ptr<CalypsoCardSelectionExtension>
    createCalypsoCardSelectionExtension() = 0;

    /**
     * Returns a new instance of SymmetricCryptoSecuritySetting.
     *
     * @param cryptoCardTransactionManagerFactory The factory of the crypto card
     * transaction manager to be used.
     * @return A new instance of SymmetricCryptoSecuritySetting.
     * @throw IllegalArgumentException If the factory is null or invalid.
     * @since 2.0.0
     */
    virtual std::shared_ptr<SymmetricCryptoSecuritySetting>
    createSymmetricCryptoSecuritySetting(
        const std::shared_ptr<SymmetricCryptoCardTransactionManagerFactory>
            cryptoCardTransactionManagerFactory)
        = 0

        /**
         * Returns a new instance of FreeTransactionManager.
         *
         * @param cardReader The card reader to be used.
         * @param card The selected card on which to operate the transaction.
         * @return A new instance of FreeTransactionManager}.
         * @throw  IllegalArgumentException If one of the parameters is null.
         * @since 2.0.0
         */
        virtual std::
            shared_ptr<FreeTransactionManager> createFreeTransactionManager(
                const std::shared_ptr<CardReader> cardReader,
                const std::shared_ptr<CalypsoCard> card)
        = 0;

    /**
     * Returns a new instance of SecureRegularModeTransactionManager.
     *
     * @param cardReader The card reader to be used.
     * @param card The selected card on which to operate the transaction.
     * @param securitySetting The security setting to be used.
     * @return A new instance of SecureRegularModeTransactionManager.
     * @throw IllegalArgumentException If one of the parameters is null.
     * @since 2.0.0
     */
    virtual std::shared_ptr<SecureRegularModeTransactionManager>
    createSecureRegularModeTransactionManager(
        const std::shared_ptr<CardReader> cardReader,
        const std::shared_ptr<CalypsoCard> card,
        const std::shared_ptr<SymmetricCryptoSecuritySetting> securitySetting)
        = 0;

    /**
     * Returns a new instance of SecureExtendedModeTransactionManager.
     *
     * @param cardReader The card reader to be used.
     * @param card The selected card on which to operate the transaction.
     * @param securitySetting The security setting to be used.
     * @return A new instance of SecureExtendedModeTransactionManager.
     * @throw IllegalArgumentException If one of the parameters is null.
     * @since 2.0.0
     */
    virtual std::shared_ptr<SecureExtendedModeTransactionManager>
    createSecureExtendedModeTransactionManager(
        const std::shared_ptr<CardReader> cardReader,
        const std::shared_ptr<CalypsoCard> card,
        const std::shared_ptr<SymmetricCryptoSecuritySetting> securitySetting)
        = 0;

    /**
     * Returns a new instance of SearchCommandData}.
     *
     * @return A new instance of SearchCommandData}.
     * @since 2.0.0
     */
    virtual std::shared_ptr<SearchCommandData> createSearchCommandData() = 0;
};

} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
