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

namespace keypop {
namespace calypso {
namespace card {

/**
 * Enumeration of the write access levels for the Calypso card Secure Session.
 *
 * <p>Each level induces the use of one of the 3 session key levels.
 *
 * @since 1.0.0
 */
enum class WriteAccessLevel {
    /**
     * For personalization, load and debit operations.
     *
     * <p>The "issuer key" will be used.
     *
     * @since 1.0.0
     */
    PERSONALIZATION,

    /**
     * For load and debit operations only.
     *
     * <p>The "load key" will be used.
     *
     * @since 1.0.0
     */
    LOAD,

    /**
     * For debit operations only.
     *
     * <p>The "debit key" will be used.
     *
     * @since 1.0.0
     */
    DEBIT
};

} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
