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

#include "keypop/calypso/card/transaction/SecureTransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Manager of card transactions secured by asymmetric key cryptographic
 * algorithms, compatible with Calypso cards in PKI mode.
 *
 * @since 2.1.0
 */
class SecurePkiModeTransactionManager
: public virtual SecureTransactionManager<SecurePkiModeTransactionManager> {
public:
    /**
     *
     */
    virtual ~SecurePkiModeTransactionManager() = default;

    /**
     * Schedules the execution of an "Open Secure Session" command in PKI mode.
     *
     * <p>Note that if the next prepared command is a "Read One Record" or "Read
     * One Or More Counters", then it will by default be merged with the "Open
     * Secure Session" command for optimization purposes.
     *
     * @return The current instance.
     * @since 2.1.0
     */
    virtual SecurePkiModeTransactionManager& prepareOpenSecureSession() = 0;
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
