/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <cstdint>
#include <map>
#include <memory>
#include <ostream>
#include <vector>

#include "keypop/reader/selection/spi/IsoSmartCard.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace card {

/**
 * Extends the {@link IsoSmartCard} interface of the "Keypop Reader API" to provide additional
 * functionality specific to Calypso cards.
 *
 * <p>An instance of {@code CalypsoCard} is obtained by casting the {@link IsoSmartCard} object from
 * the selection process defined by the "Keypop Reader API".
 *
 * <p>It is a dynamic view of the card's content, regularly updated from the selection stage to the
 * end of the transaction.
 *
 * <p>The various information contained in CalypsoCard includes:
 *
 * <ul>
 *   <li>The application identification fields (revision/version, class, DF name, serial number,
 *       ATR, issuer)
 *   <li>The indication of the presence of optional features (Stored Value, PIN, Rev3.2 mode,
 *       ratification management)
 *   <li>The management information of the modification buffer
 *   <li>The invalidation status
 *   <li>The files, counters, SV data read or modified during the execution of the processes defined
 *       by the card transaction manager.
 * </ul>
 *
 * @since 1.0.0
 */
class CalypsoCard : public IsoSmartCard {
public:
    /**
     * All Calypso Card products supported by this API.
     *
     * @since 1.0.0
     */
    enum class ProductType {
        /**
         * Card Calypso Prime revision 1.x
         *
         * @since 1.0.0
         */
        PRIME_REVISION_1,

        /**
         * Card Calypso Prime revision 2.x
         *
         * @since 1.0.0
         */
        PRIME_REVISION_2,

        /**
         * Card Calypso Prime revision 3.x
         *
         * @since 1.0.0
         */
        PRIME_REVISION_3,

        /**
         * Card Calypso Light
         *
         * @since 1.0.0
         */
        LIGHT,

        /**
         * Card Calypso Basic
         *
         * @since 1.0.0
         */
        BASIC,

        /**
         * Application type is equal to 0 or FFh or if the data provided by the selection process is
         * not properly formatted (bad TLV data).
         *
         * @since 1.0.0
         */
        UNKNOWN
    };

    /**
     * Gets the card product type.
     *
     * @return A not null reference.
     * @since 1.0.0
     */
    virtual const ProductType& getProductType() const = 0;

    /**
     * Indicates if the card is a Calypso HCE (Host Card Emulation) .
     *
     * @return True if the card is a Calypso HCE.
     * @since 1.0.0
     */
    virtual bool isHce() const = 0;

    /**
     * Tells if the current DF is invalidated or not.
     *
     * <p>The invalidation status is determined either from the response to the Select Application
     * command or from the response to a Select File (DF) command.
     *
     * <p>For a PRIME_REVISION_3 card, a 6283h status word is returned in response to the Select
     * Application command when the corresponding DF is invalidated.
     *
     * <p>For older Calypso cards it may be necessary to execute a Select File command in order to
     * determine the invalidation status.
     *
     * @return True if the current DF has been invalidated.
     * @since 1.0.0
     */
    virtual bool isDfInvalidated() const = 0;

    /**
     * Gets the DF name as an array of bytes.
     *
     * <p>The DF name is the name of the application DF as defined in ISO/IEC 7816-4.
     *
     * <p>It also corresponds to the complete representation of the target covered by the AID value
     * provided in the selection command.
     *
     * <p>The AID selects the application by specifying all or part of the targeted DF Name (5 bytes
     * minimum).
     *
     * @return A not null byte array containing the DF Name bytes (5 to 16 bytes)
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t>& getDfName() const = 0;

    /**
     * Gets the Calypso application serial number as an array of bytes.
     *
     * @return A not null byte array containing the Application Serial Number (8 bytes).
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t> getApplicationSerialNumber() const = 0;

    /**
     * Gets the raw Calypso startup information.
     *
     * @return A not null byte array.
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t>& getStartupInfoRawData() const = 0;

    /**
     * Gets the platform identification byte which is the reference of the chip.
     *
     * @return The platform identification byte.
     * @since 1.0.0
     */
    virtual uint8_t getPlatform() const = 0;

    /**
     * Gets the Application Type byte which determines the Calypso product type and various options.
     *
     * @return The Application Type byte.
     * @since 1.0.0
     */
    virtual uint8_t getApplicationType() const = 0;

    /**
     * Gets the Application Subtype that provides a reference to the file structure of the Calypso
     * DF.
     *
     * @return The Application Subtype byte
     * @since 1.0.0
     */
    virtual uint8_t getApplicationSubtype() const = 0;

    /**
     * Gets the Software Issuer byte that indicates the entity responsible for the software of the
     * selected application.
     *
     * @return The Software Issuer byte.
     * @since 1.0.0
     */
    virtual uint8_t getSoftwareIssuer() const = 0;

    /**
     * Gets the Software Version field that may be set to any fixed value by the Software Issuer of
     * the Calypso application.
     *
     * @return The Software Version byte.
     * @since 1.0.0
     */
    virtual uint8_t getSoftwareVersion() const = 0;

    /**
     * Gets the Software Revision field that may be set to any fixed value by the Software Issuer of
     * the Calypso application.
     *
     * @return The Software Revision byte.
     * @since 1.0.0
     */
    virtual uint8_t getSoftwareRevision() const = 0;

    /**
     * Gets the session modification byte from the startup info structure.
     *
     * <p>Depending on the type of card, the session modification byte indicates the maximum number
     * of bytes that can be modified or the number of possible write commands in a session.
     *
     * @return The Session Modification byte.
     * @since 1.0.0
     */
    virtual uint8_t getSessionModification() const = 0;

    /**
     * Gets the traceability information of the product.
     *
     * <p>The returned array contains the software issuer ID and the discretionary data.
     *
     * @return An empty array if the traceability information is not available.
     * @see CalypsoCardSelectionExtension#prepareGetData(GetDataTag)
     * @see TransactionManager#prepareGetData(GetDataTag)
     * @since 1.1.0
     */
    virtual const std::vector<uint8_t> getTraceabilityInformation() const = 0;

    /**
     * Returns the metadata of the current DF.
     *
     * @return Null if is not set.
     * @see CalypsoCardSelectionExtension#prepareSelectFile(short)
     * @see CalypsoCardSelectionExtension#prepareSelectFile(SelectFileControl)
     * @see TransactionManager#prepareSelectFile(short)
     * @see TransactionManager#prepareSelectFile(SelectFileControl)
     * @since 1.0.0
     */
    virtual const std::shared_ptr<DirectoryHeader> getDirectoryHeader() const = 0;

    /**
     * Returns a reference to the ElementaryFile that has the provided SFI.
     *
     * <p>Note that if a secure session is actually running, then the object contains all session
     * modifications, which can be canceled if the secure session fails.
     *
     * @param sfi The SFI to search.
     * @return Null if the requested EF is not found or if the SFI is equal to 0.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<ElementaryFile> getFileBySfi(const uint8_t sfi) const = 0;

    /**
     * Returns a reference to the ElementaryFile that has the provided LID value.
     *
     * <p>Note that if a secure session is actually running, then the object contains all session
     * modifications, which can be canceled if the secure session fails.
     *
     * @param lid The LID to search.
     * @return Null if the requested EF is not found.
     * @since 1.0.0
     */
    virtual const std::shared_ptr<ElementaryFile> getFileByLid(const uint16_t lid) const = 0;

    /**
     * Returns a reference to a map of all known Elementary Files by their associated SFI.
     *
     * <p>Note that if a secure session is actually running, then the map contains all session
     * modifications, which can be canceled if the secure session fails.
     *
     * @return A not null reference (it may be empty if no one EF is set).
     * @since 1.0.0
     * @deprecated Since an EF may not have an SFI, the getFiles() method must be used instead.
     */
    virtual const std::map<const uint8_t, const std::shared_ptr<ElementaryFile>> getAllFiles() const
        = 0;

    /**
     * Returns a reference to the set of all known Elementary Files contains inside the current DF.
     *
     * <p>Note that if a secure session is actually running, then the set contains all session
     * modifications, which can be canceled if the secure session fails.
     *
     * @return A not null reference (it may be empty if no one EF is set).
     * @since 1.1.0
     */
    virtual const std::vector<std::shared_ptr<ElementaryFile>>& getFiles() const = 0;

    /**
     * Tells if the last session with this card has been ratified or not.
     *
     * @return True if the card has been ratified.
     * @throws IllegalStateException If no session has been opened.
     * @see CalypsoCardSelectionExtension#preparePreOpenSecureSession(WriteAccessLevel)
     * @see SecureSymmetricCryptoTransactionManager#prepareOpenSecureSession(WriteAccessLevel)
     * @since 1.0.0
     */
    virtual bool isDfRatified() const = 0;

    /**
     * Returns the transaction counter value provided in the output data of the last successful
     * "Open Secure Session" command.
     *
     * <p>Please note that there are other commands that can decrement the original card counter
     * (e.g.
     * Change Key, Change/Verify PIN, SV Debit/Undebit/Reload). For these other commands, the counter
     * value returned by this method will not be updated.
     *
     * @return A positive value.
     * @throws IllegalStateException If no session has been opened.
     * @see CalypsoCardSelectionExtension#preparePreOpenSecureSession(WriteAccessLevel)
     * @see SecureSymmetricCryptoTransactionManager#prepareOpenSecureSession(WriteAccessLevel)
     * @since 1.2.0
     */
    virtual int getTransactionCounter() const = 0;

    /**
     * Indicates whether the Public Key Authentication is supported or not (since rev 3.3).
     *
     * <p>This boolean is interpreted from the Application Type byte
     *
     * @return True if the Public Key Authentication is supported.
     * @since 1.0.0
     */
    virtual bool isPkiModeSupported() const = 0;

    /**
     * Indicates whether the Extended Mode is supported or not (since rev 3.2).
     *
     * <p>This boolean is initially the result of the interpretation of the application type byte
     * but may be updated after the secure session is opened. Indeed, depending on the type of key
     * used, the extended mode functionalities may not be available (non-AES keys) and this
     * information is provided by the card in response to the "Open Secure Session" command.
     *
     * @return True if the Extended Mode is supported.
     * @since 1.0.0
     */
    virtual bool isExtendedModeSupported() const = 0;

    /**
     * Indicates if the ratification is done on deselect (ratification command not necessary).
     *
     * <p>This boolean is interpreted from the Application Type byte
     *
     * @return True if the ratification on deselect is supported.
     * @since 1.0.0
     */
    virtual bool isRatificationOnDeselectSupported() const = 0;

    /**
     * Indicates whether the card has the Calypso PIN feature.
     *
     * <p>This boolean is interpreted from the Application Type byte
     *
     * @return True if the card has the PIN feature.
     * @since 1.0.0
     */
    virtual bool isPinFeatureAvailable() const = 0;

    /**
     * Indicates if the PIN is blocked. The maximum number of incorrect PIN submissions has been
     * reached.
     *
     * @return True if the PIN status is blocked
     * @throw IllegalStateException If the PIN has not been checked.
     * @see TransactionManager#prepareCheckPinStatus()
     * @see TransactionManager#prepareVerifyPin(byte[])
     * @since 1.0.0
     */
    virtual bool isPinBlocked() const = 0;

    /**
     * Gives the number of erroneous PIN presentations remaining before blocking.
     *
     * @return The number of remaining attempts.
     * @throw IllegalStateException If the PIN has not been checked.
     * @see TransactionManager#prepareCheckPinStatus()
     * @see TransactionManager#prepareVerifyPin(byte[])
     * @since 1.0.0
     */
    virtual int getPinAttemptRemaining() const = 0;

    /**
     * Indicates whether the card has the Calypso Stored Value feature.
     *
     * <p>This boolean is interpreted from the Application Type byte
     *
     * @return True if the card has the Stored Value feature
     * @since 1.0.0
     */
    virtual bool isSvFeatureAvailable() const = 0;

    /**
     * Gets the current SV balance value
     *
     * @return An int
     * @throws IllegalStateException If no SV Get command has been executed.
     * @see SecureSymmetricCryptoTransactionManager#prepareSvGet(SvOperation, SvAction)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int, byte[], byte[])
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int, byte[], byte[], byte[])
     * @since 1.0.0
     */
    virtual int getSvBalance() const = 0;

    /**
     * Gets the last SV transaction number
     *
     * @return An int
     * @throws IllegalStateException If no SV Get command has been executed.
     * @see SecureSymmetricCryptoTransactionManager#prepareSvGet(SvOperation, SvAction)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int, byte[], byte[])
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int, byte[], byte[], byte[])
     * @since 1.0.0
     */
    virtual int getSvLastTNum() const = 0;

    /**
     * Gets a reference to the last {@link SvLoadLogRecord}
     *
     * @return A last SV load log record object or null if not available.
     * @see SecureSymmetricCryptoTransactionManager#prepareSvGet(SvOperation, SvAction)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int, byte[], byte[])
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int, byte[], byte[], byte[])
     * @since 1.0.0
     */
    virtual const std::shared_ptr<SvLoadLogRecord> getSvLoadLogRecord() = 0;

    /**
     * Gets a reference to the last {@link SvDebitLogRecord}
     *
     * @return A last SV debit log record object or null if not available.
     * @see SecureSymmetricCryptoTransactionManager#prepareSvGet(SvOperation, SvAction)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int, byte[], byte[])
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int, byte[], byte[], byte[])
     * @since 1.0.0
     */
    virtual const std::shared_ptr<SvDebitLogRecord> getSvDebitLogLastRecord() = 0;

    /**
     * Gets list of references to the {@link SvDebitLogRecord} read from the card.
     *
     * @return An empty list if no log records are available.
     * @see SecureSymmetricCryptoTransactionManager#prepareSvGet(SvOperation, SvAction)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvDebit(int, byte[], byte[])
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int)
     * @see SecureSymmetricCryptoTransactionManager#prepareSvReload(int, byte[], byte[], byte[])
     * @since 1.0.0
     */
    virtual const std::vector<std::shared_ptr<SvDebitLogRecord>> getSvDebitLogAllRecords() const
        = 0;
};

inline std::ostream&
operator<<(std::ostream& os, const CalypsoCard::ProductType& pt) {
    os << "PRODUCT_TYPE: ";

    switch (pt) {
    case CalypsoCard::ProductType::BASIC:
        os << "BASIC";
        break;
    case CalypsoCard::ProductType::LIGHT:
        os << "LIGHT";
        break;
    case CalypsoCard::ProductType::PRIME_REVISION_1:
        os << "PRIME_REVISION_1";
        break;
    case CalypsoCard::ProductType::PRIME_REVISION_2:
        os << "PRIME_REVISION_2";
        break;
    case CalypsoCard::ProductType::PRIME_REVISION_3:
        os << "PRIME_REVISION_3";
        break;
    default:
        os << "UNKNOWN";
        break;
    }

    return os;
}

} /* namespace card */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
