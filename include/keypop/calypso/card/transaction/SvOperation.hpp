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

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Defines the type of Stored Value operation to be performed.
 *
 * @since 1.0.0
 */
enum class SvOperation {
    /**
     * Increase the balance of the stored value
     *
     * @since 1.0.0
     */
    RELOAD,

    /**
     * Decrease the balance of the stored value
     *
     * @since 1.0.0
     */
    DEBIT
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
