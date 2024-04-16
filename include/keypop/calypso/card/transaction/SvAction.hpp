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
 * Defines the type Stored Value of action.
 *
 * @since 1.0.0
 */
enum class SvAction {
    /**
     * In the case of a {@link SvOperation#RELOAD}, loads a positive amount; in the case of a {@link
     * SvOperation#DEBIT}, debits a positive amount
     *
     * @since 1.0.0
     */
    DO,

    /**
     * In the case of a {@link SvOperation#RELOAD}, loads a negative amount; in the case of a {@link
     * SvOperation#DEBIT}, cancels, totally or partially, a previous debit.
     *
     * @since 1.0.0
     */
    UNDO
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
