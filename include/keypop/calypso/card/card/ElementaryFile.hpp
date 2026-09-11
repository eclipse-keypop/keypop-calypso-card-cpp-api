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

#include <cstdint>
#include <iomanip>
#include <memory>
#include <ostream>
#include <sstream>
#include <vector>

#include "keypop/calypso/card/card/FileData.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace card {

class FileHeader;

/**
 * Calypso Elementary File.
 *
 * @since 1.0.0
 */
class ElementaryFile {
public:
    /**
     * The different types of EF.
     *
     * @since 1.0.0
     */
    enum Type {
        /**
         * A Linear EF is made of 1 to several records.
         *
         * @since 1.0.0
         */
        LINEAR,

        /**
         * A Binary EF contains a single continuous sequence of data bytes from
         * byte #0 (first byte) to byte #N−1 (last byte, for a binary file of N
         * bytes).
         *
         * @since 1.0.0
         */
        BINARY,

        /**
         * A Cyclic EF is made of 1 to several records organized in a cycle,
         * from the most recent (record #1) to the oldest.
         *
         * @since 1.0.0
         */
        CYCLIC,

        /**
         * A Counters EF is made of a single record containing an ordered
         * sequence of K counters of three bytes each, from counter #1 (bytes at
         * offsets 0, 1 and 2 of the record) to counter #K.
         *
         * @since 1.0.0
         */
        COUNTERS,

        /**
         * A Simulated Counter EF is a linear file with a single record.<br>
         * Simulated Counter EFs are present for compatibility with the Calypso
         * Revision 2 access to simulated individual counters.
         *
         * @since 1.0.0
         */
        SIMULATED_COUNTERS
    };

    /**
     * Gets the associated SFI.
     *
     * @return The SFI.
     * @since 1.0.0
     */
    virtual uint8_t getSfi() const = 0;

    /**
     * Gets the file header.
     *
     * @return Null if header is not yet set.
     * @since 1.0.0
     */
    virtual std::shared_ptr<FileHeader> getHeader() const = 0;

    /**
     * Gets the file data.
     *
     * @return A not null data reference.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<FileData> getData() const = 0;

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const ElementaryFile& ef) {
        /*
         * The SFI is formatted apart: streamed as a uint8_t it would come out
         * as a character, and most SFI values are not printable.
         */
        std::ostringstream sfi;
        sfi << std::uppercase << std::hex << std::setfill('0') << std::setw(2)
            << static_cast<int>(ef.getSfi());

        os << "ELEMENTARY_FILE: {"
           << "SFI: " << sfi.str() << "h";

        /*
         * A header is reported as present only. FileHeader includes this header
         * for the Type enumeration, so it is an incomplete type here and cannot
         * be rendered; print the header itself to see its fields.
         */
        if (ef.getHeader() != nullptr) {
            os << ", HEADER: set";
        }

        os << ", " << ef.getData() << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const std::shared_ptr<ElementaryFile> ef) {
        if (ef == nullptr) {
            os << "ELEMENTARY_FILE: null";
        } else {
            os << *ef.get();
        }

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(
        std::ostream& os,
        const std::vector<std::shared_ptr<ElementaryFile>>& ef) {
        os << "ELEMENTARY_FILES: {";

        for (auto it = ef.begin(); it != ef.end(); it++) {
            if (it != ef.begin()) {
                os << ", ";
            }

            os << *it;
        }

        os << "}";

        return os;
    }
};

} /* namespace card */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
