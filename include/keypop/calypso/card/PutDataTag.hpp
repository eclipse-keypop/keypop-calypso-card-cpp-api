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
 * Enumeration of all input data types.
 *
 * <p>May not be applicable to all products.
 *
 * @since 2.1.0
 */
enum class PutDataTag {
    /**
     * Card key pair.
     *
     * @since 2.1.0
     */
    CARD_KEY_PAIR,

    /**
     * Card certificate.
     *
     * @since 2.1.0
     */
    CARD_CERTIFICATE,

    /**
     * Certification Authority (CA) certificate.
     *
     * @since 2.1.0
     */
    CA_CERTIFICATE
};

} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
