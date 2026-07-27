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

#include "keypop/calypso/card/transaction/SecureTransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace cpp {

using keypop::calypso::card::transaction::SecureTransactionManager;

class SecureRegularModeTransactionManagerBase
: public virtual SecureTransactionManager<
      SecureRegularModeTransactionManagerBase> {
public:
    /**
     * virtual destructor.
     */
    virtual ~SecureRegularModeTransactionManagerBase() = default;
};

} /* namespace cpp */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
