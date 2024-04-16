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
 * Policy for managing the physical channel after a card request is executed.
 *
 * @since 2.0.0
 */
enum class ChannelControl {
    /**
     * Leaves the physical channel open.
     *
     * @since 2.0.0
     */
    KEEP_OPEN,

    /**
     * Terminates communication with the card.<br>
     * The physical channel closes instantly or a card removal sequence is initiated depending on
     * the observation mode.
     *
     * @since 2.0.0
     */
    CLOSE_AFTER
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
