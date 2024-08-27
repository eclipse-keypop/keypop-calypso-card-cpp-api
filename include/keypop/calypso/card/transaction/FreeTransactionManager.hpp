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
#include <stdexcept>

#include "keypop/calypso/card/TransactionManager.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Manager of card transactions requiring no cryptographic computation.
 *
 * <p>See {@link TransactionManager} parent interface for more information and details of available
 * card operations.
 *
 * <p>An instance of this interface can be obtained via the method {@link
 * CalypsoCardApiFactory#createFreeTransactionManager(CardReader, CalypsoCard)}.
 *
 * @since 2.0.0
 */
template <typename T>
class FreeTransactionManager : public TransactionManager<T> {
public:
    /**
     * Virtual destructor.
     */
    virtual ~FreeTransactionManager() = default;
}

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
