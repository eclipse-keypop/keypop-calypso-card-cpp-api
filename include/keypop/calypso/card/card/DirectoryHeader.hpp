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

#pragma once

#include <cstdint>
#include <vector>

#include "keypop/calypso/card/WriteAccessLevel.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace card {

/**
 * Calypso DF metadata.
 *
 * @since 1.0.0
 */
class DirectoryHeader {
public:
    /**
     * Gets the associated LID.
     *
     * @return The LID.
     * @since 1.0.0
     */
    virtual uint16_t getLid() const = 0;

    /**
     * Gets the DF status.
     *
     * @return The DF status byte.
     * @since 1.0.0
     */
    virtual uint8_t getDfStatus() const = 0;

    /**
     * Gets a reference to access conditions.
     *
     * @return A not empty byte array.
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t>& getAccessConditions() const = 0;

    /**
     * Gets a reference to keys indexes.
     *
     * @return A not empty byte array.
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t>& getKeyIndexes() const = 0;

    /**
     * Gets the KIF associated to the provided write access level.
     *
     * @param writeAccessLevel The write access level (should be not null).
     * @return The KIF value.
     * @throws IllegalArgumentException if writeAccessLevel is null.
     * @since 1.0.0
     */
    virtual uint8_t getKif(const WriteAccessLevel writeAccessLevel) const = 0;

    /**
     * Gets the KVC associated to the provided write access level.
     *
     * @param writeAccessLevel The write access level (should be not null).
     * @return The KVC value.
     * @throws IllegalArgumentException if writeAccessLevel is null.
     * @since 1.0.0
     */
    virtual uint8_t getKvc(const WriteAccessLevel writeAccessLevel) const = 0;
};

} /* namespace card */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
