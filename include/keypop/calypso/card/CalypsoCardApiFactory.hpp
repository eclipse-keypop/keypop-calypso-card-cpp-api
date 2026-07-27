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
#include "keypop/calypso/card/cpp/SecureExtendedModeTransactionManagerBase.hpp"
#include "keypop/calypso/card/cpp/SecureRegularModeTransactionManagerBase.hpp"
#include "keypop/calypso/card/transaction/AsymmetricCryptoSecuritySetting.hpp"
#include "keypop/calypso/card/transaction/FreeTransactionManager.hpp"
#include "keypop/calypso/card/transaction/SearchCommandData.hpp"
#include "keypop/calypso/card/transaction/SecureExtendedModeTransactionManager.hpp"
#include "keypop/calypso/card/transaction/SecurePkiModeTransactionManager.hpp"
#include "keypop/calypso/card/transaction/SecureRegularModeTransactionManager.hpp"
#include "keypop/calypso/card/transaction/SymmetricCryptoSecuritySetting.hpp"
#include "keypop/calypso/card/transaction/spi/AsymmetricCryptoCardTransactionManagerFactory.hpp"
#include "keypop/calypso/card/transaction/spi/SymmetricCryptoCardTransactionManagerFactory.hpp"
#include "keypop/reader/CardReader.hpp"

namespace keypop {
namespace calypso {
namespace card {

using keypop::calypso::card::card::CalypsoCard;
using keypop::calypso::card::card::CalypsoCardSelectionExtension;
using keypop::calypso::card::cpp::SecureExtendedModeTransactionManagerBase;
using keypop::calypso::card::cpp::SecureRegularModeTransactionManagerBase;
using keypop::calypso::card::transaction::AsymmetricCryptoSecuritySetting;
using keypop::calypso::card::transaction::FreeTransactionManager;
using keypop::calypso::card::transaction::SearchCommandData;
using keypop::calypso::card::transaction::SecurePkiModeTransactionManager;
using keypop::calypso::card::transaction::SecureRegularModeTransactionManager;
using keypop::calypso::card::transaction::SymmetricCryptoSecuritySetting;
using keypop::calypso::card::transaction::spi::
    AsymmetricCryptoCardTransactionManagerFactory;
using keypop::calypso::card::transaction::spi::
    SymmetricCryptoCardTransactionManagerFactory;
using keypop::reader::CardReader;

/* C++ specific */
using SecureExtendedModeTransactionManager
    = keypop::calypso::card::cpp::SecureExtendedModeTransactionManagerBase;

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
    virtual std::unique_ptr<CalypsoCardSelectionExtension>
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
    virtual std::unique_ptr<SymmetricCryptoSecuritySetting>
    createSymmetricCryptoSecuritySetting(
        const std::shared_ptr<SymmetricCryptoCardTransactionManagerFactory>&
            cryptoCardTransactionManagerFactory) = 0;

    /**
     * Returns a new instance of FreeTransactionManager.
     *
     * @param cardReader The card reader to be used.
     * @param card The selected card on which to operate the transaction.
     * @return A new instance of FreeTransactionManager}.
     * @throw  IllegalArgumentException If one of the parameters is null.
     * @since 2.0.0
     */
    virtual std::unique_ptr<FreeTransactionManager>
    createFreeTransactionManager(
        const std::shared_ptr<CardReader>& cardReader,
        const std::shared_ptr<CalypsoCard>& card) = 0;

    /**
     * Returns a new instance of AsymmetricCryptoSecuritySetting.
     *
     * @param cryptoCardTransactionManagerFactory The factory of the crypto card
     *        transaction manager to be used.
     * @return A new instance of AsymmetricCryptoSecuritySetting.
     * @throw IllegalArgumentException If the factory is null or invalid.
     * @since 2.1.0
     */
    virtual std::unique_ptr<AsymmetricCryptoSecuritySetting>
    createAsymmetricCryptoSecuritySetting(
        const std::shared_ptr<AsymmetricCryptoCardTransactionManagerFactory>&
            cryptoCardTransactionManagerFactory) = 0;

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
    virtual std::unique_ptr<SecureRegularModeTransactionManagerBase>
    createSecureRegularModeTransactionManager(
        const std::shared_ptr<CardReader>& cardReader,
        const std::shared_ptr<CalypsoCard>& card,
        const std::shared_ptr<SymmetricCryptoSecuritySetting>& securitySetting)
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
    virtual std::unique_ptr<SecureExtendedModeTransactionManager>
    createSecureExtendedModeTransactionManager(
        const std::shared_ptr<CardReader>& cardReader,
        const std::shared_ptr<CalypsoCard>& card,
        const std::shared_ptr<SymmetricCryptoSecuritySetting>& securitySetting)
        = 0;

    /**
     * Returns a new instance of SecurePkiModeTransactionManager.
     *
     * @param cardReader The card reader to be used.
     * @param card The selected card on which to operate the transaction.
     * @param securitySetting The security setting to be used.
     * @return A new instance of {@link SecurePkiModeTransactionManager}.
     * @throw IllegalArgumentException If one of the parameters is null.
     * @since 2.1.0
     */
    virtual std::unique_ptr<SecurePkiModeTransactionManager>
    createSecurePkiModeTransactionManager(
        const std::shared_ptr<CardReader>& cardReader,
        const std::shared_ptr<CalypsoCard>& card,
        const std::shared_ptr<AsymmetricCryptoSecuritySetting>& securitySetting)
        = 0;

    /**
     * Returns a new instance of SearchCommandData}.
     *
     * @return A new instance of SearchCommandData}.
     * @since 2.0.0
     */
    virtual std::unique_ptr<SearchCommandData> createSearchCommandData() = 0;
};

} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
