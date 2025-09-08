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

#include "keypop/calypso/card/cpp/SecureExtendedModeTransactionManagerBase.hpp"
#include "keypop/calypso/card/transaction/SecureSymmetricCryptoTransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

using keypop::calypso::card::cpp::SecureExtendedModeTransactionManagerBase;

/**
 * Manager of card transactions secured by symmetric key cryptographic
 * algorithms, adding additional operations available only for "Calypso Prime
 * Extended" products.
 *
 * <p>See SecureSymmetricCryptoTransactionManager parent interface for
 * more information and details of available card operations.
 *
 * <p>An instance of this interface can be obtained via the method
 * CalypsoCardApiFactory::createSecureExtendedModeTransactionManager(CardReader,
 * CalypsoCard, SymmetricCryptoSecuritySetting).
 *
 * @since 2.0.0
 */
template <typename T>
class SecureExtendedModeTransactionManager
: public SecureExtendedModeTransactionManagerBase,
  public SecureSymmetricCryptoTransactionManager<T> {
public:
    /* C++: Moved to SecureExtendedModeTransactionManagerBase */
    // virtual SecureRegularModeTransactionManagerBase&
    // prepareEarlyMutualAuthentication() = 0;

    /* C++: Moved to SecureExtendedModeTransactionManagerBase */
    // virtual SecureExtendedModeTransactionManager& prepareActivateEncryption()
    //     = 0;

    /* C++: Moved to SecureExtendedModeTransactionManagerBase */
    // virtual SecureExtendedModeTransactionManagerBase&
    // prepareDeactivateEncryption() = 0;
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
