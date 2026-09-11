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

#include "keypop/calypso/card/card/ElementaryFile.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace card {

/**
 * Calypso EF metadata.
 *
 * @since 1.0.0
 */
class FileHeader {
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
     * @return Null if the status is not available (e.g. when the {@code
     * FileHeader} is created following the response to a "Get Data" command
     * with the GetDataTag::EF_LIST tag).
     * @since 1.0.0
     */
    virtual const std::shared_ptr<uint8_t>& getDfStatus() const = 0;

    /**
     * Gets the Elementary File type.
     *
     * @return A not null file type.
     * @since 1.0.0
     */
    virtual ElementaryFile::Type getEfType() const = 0;

    /**
     * Gets the number of records :
     *
     * <ul>
     *   <li>For a Counter file, the number of records is always 1.<br>
     *       Extra bytes (rest of the division of the file size by 3) aren't
     * accessible. <li>For a Binary file, the number of records is always 1.
     * </ul>
     *
     * @return The number of records.
     * @since 1.0.0
     */
    virtual int getRecordsNumber() const = 0;

    /**
     * Gets the size of a record :
     *
     * <ul>
     *   <li>For a Counter file, the record size is the original size of the
     * record #1.<br> Extra bytes (rest of the division of the file size by 3)
     * aren't accessible. <li>For a Binary file, the size of the record is
     * corresponding to the file size.
     * </ul>
     *
     * @return The size of a record.
     * @since 1.0.0
     */
    virtual int getRecordSize() const = 0;

    /**
     * Gets a reference to the access conditions.
     *
     * @return An empty array if the access conditions are not available (e.g.
     * when the {@code FileHeader} is created following the response to a "Get
     * Data" command with the GetDataTag::EF_LIST tag).
     * @since 1.0.0
     */
    virtual const std::vector<std::uint8_t>& getAccessConditions() const = 0;

    /**
     * Gets a reference to the keys indexes.
     *
     * @return An empty array if the key indexes are not available (e.g. when
     * the {@code FileHeader} is created following the response to a "Get Data"
     * command with the GetDataTag::EF_LIST tag).
     * @since 1.0.0
     */
    virtual const std::vector<std::uint8_t>& getKeyIndexes() const = 0;

    /**
     * Gets the non-zero unique identifier of the shared data when the file data
     * is shared.
     *
     * @return Zero if the file data is not shared or null if the information is
     * not available (e.g. when the {@code FileHeader} is created following the
     * response to a "Get Data" command with the GetDataTag::EF_LIST tag).
     * @since 1.0.0
     */
    virtual const std::shared_ptr<std::uint16_t> getSharedReference() const = 0;

    /**
     * Renders the header fields, so that a log shows the content and not the
     * address of the object.
     */
    friend std::ostream&
    operator<<(std::ostream& os, const FileHeader& fh) {
        const char* efType;
        switch (fh.getEfType()) {
        case ElementaryFile::Type::LINEAR: efType = "LINEAR"; break;
        case ElementaryFile::Type::BINARY: efType = "BINARY"; break;
        case ElementaryFile::Type::CYCLIC: efType = "CYCLIC"; break;
        case ElementaryFile::Type::COUNTERS: efType = "COUNTERS"; break;
        case ElementaryFile::Type::SIMULATED_COUNTERS:
            efType = "SIMULATED_COUNTERS";
            break;
        default: efType = "UNKNOWN"; break;
        }

        /* Formatted apart so the caller's stream keeps its own flags. */
        std::ostringstream ss;
        ss << std::uppercase << std::hex << std::setfill('0');

        ss << "FILE_HEADER: {LID: " << std::setw(4) << fh.getLid()
           << "h, EF_TYPE: " << efType << std::dec
           << ", RECORDS: " << fh.getRecordsNumber()
           << ", RECORD_SIZE: " << fh.getRecordSize() << std::hex
           << ", ACCESS_CONDITIONS: ";
        for (const auto byte : fh.getAccessConditions()) {
            ss << std::setw(2) << static_cast<int>(byte);
        }
        ss << ", KEY_INDEXES: ";
        for (const auto byte : fh.getKeyIndexes()) {
            ss << std::setw(2) << static_cast<int>(byte);
        }
        ss << ", DF_STATUS: ";
        if (fh.getDfStatus() != nullptr) {
            ss << std::setw(2) << static_cast<int>(*fh.getDfStatus()) << "h";
        } else {
            ss << "null";
        }
        ss << ", SHARED_REFERENCE: ";
        if (fh.getSharedReference() != nullptr) {
            ss << std::setw(4) << *fh.getSharedReference() << "h";
        } else {
            ss << "null";
        }
        ss << "}";

        os << ss.str();

        return os;
    }

    /**
     *
     */
    friend std::ostream&
    operator<<(std::ostream& os, const std::shared_ptr<FileHeader>& fh) {
        if (fh == nullptr) {
            os << "FILE_HEADER: null";
        } else {
            os << *fh;
        }

        return os;
    }
};

} /* namespace card */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
