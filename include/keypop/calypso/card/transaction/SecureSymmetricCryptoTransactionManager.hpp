/**************************************************************************************************
 * Copyright (c) 2024 Calypso Networks Association https://calypsonet.org/                        *
 *                                                                                                *
 * This program and the accompanying materials are made available under the                       *
 * terms of the MIT License which is available at https://opensource.org/licenses/MIT.            *
 *                                                                                                *
 * SPDX-License-Identifier: MIT                                                                   *
 **************************************************************************************************/

#pragma once

#include <vector>

#include "keypop/calypso/card/SvAction.hpp"
#include "keypop/calypso/card/SvOperation.hpp"
#include "keypop/calypso/card/WriteAccessLevel.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

/**
 * Contains operations common to all card transactions secured by "symmetric" key cryptographic
 * algorithms.
 *
 * <p>See {@link SecureTransactionManager} parent interface for more information and details of
 * available card operations.
 *
 * @param <T> The type of the lowest level child object.
 * @since 2.0.0
 */
template <typename T>
class SecureSymmetricCryptoTransactionManager : public SecureTransactionManager<T> {
public:
    /**
     * Schedules the execution of an "Open Secure Session" command.
     *
     * <p>The secure session will be opened with the provided {@link WriteAccessLevel} depending on
     * whether it is a personalization, reload or debit transaction profile.
     *
     * <p>Note that if the next prepared command is a "Read One Record" or "Read One Or More
     * Counters", then it will by default be merged with the "Open Secure Session" command for
     * optimization purposes except if the "pre-open" mode is active.
     *
     * <p>This mechanism may in some cases be incompatible with the security constraints and can be
     * disabled via the {@link SymmetricCryptoSecuritySetting#disableReadOnSessionOpening()} method.
     *
     * @param writeAccessLevel The write access level to be used.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided argument is null.
     * @throw IllegalStateException In the following cases:
     *     <ul>
     *       <li>No {@link SymmetricCryptoSecuritySetting} is available
     *       <li>A secure session opening is already prepared
     *       <li>A secure session is already opened
     *     </ul>
     *
     * @see CalypsoCardSelectionExtension#preparePreOpenSecureSession(WriteAccessLevel)
     * @since 1.6.0
     */
    virtual T& prepareOpenSecureSession(const WriteAccessLevel writeAccessLevel) = 0;

    /**
     * Schedules the execution of a "SV Get" command to prepare an SV operation or simply retrieves
     * the current SV status.
     *
     * <p>Data will be available in {@link CalypsoCard} using the dedicated SV data management
     * methods.
     *
     * @param svOperation Informs about the nature of the intended operation: debit or reload.
     * @param svAction The type of action: DO a debit or a positive reload, UNDO an undebit or a
     *        negative reload.
     * @return The current instance.
     * @throw UnsupportedOperationException If the SV feature is not available for this card.
     * @throw IllegalArgumentException If one of the arguments is null.
     * @since 1.0.0
     */
    virtual T& prepareSvGet(const SvOperation svOperation, const SvAction svAction) = 0;

    /**
     * Schedules the execution of a "SV Reload" command to increase the current SV balance and using
     * the provided additional data.
     *
     * <p>Data will be available in {@link CalypsoCard} using the dedicated SV data management
     * methods.
     *
     * <p>Note: the key used is the reload key.
     *
     * @param amount The value to be reloaded, positive or negative integer in the range.
     *        -8388608..8388607
     * @param date 2-byte free value.
     * @param time 2-byte free value.
     * @param free 2-byte free value.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided argument is out of range.
     * @throw IllegalStateException In one of the following cases:
     *     <ul>
     *       <li>Another SV command was already prepared inside the same secure session.
     *       <li>The SV command is not placed in the first position in the list of prepared
     * commands. <li>The SV command does not follow a "SV Get" command. <li>The command and the SV
     * operation are not consistent.
     *     </ul>
     *
     * @throw SessionBufferOverflowException If the command will overflow the modifications buffer
     *        size and the multiple session is not allowed.
     * @since 1.0.0
     */
    virtual T& prepareSvReload(
        const int amount,
        const std::vector<uint8_t>& date,
        const std::vector<uint8_t>& time,
        const std::vector<uint8_t>& free)
        = 0;

    /**
     * Schedules the execution of a "SV Reload" command to increase the current SV balance.
     *
     * <p>Data will be available in {@link CalypsoCard} using the dedicated SV data management
     * methods.
     *
     * <p>Note 1: the optional SV additional data are set to zero.
     *
     * <p>Note 2: the key used is the reload key.
     *
     * @param amount The value to be reloaded, positive integer in the range 0..8388607 for a DO.
     *        action, in the range 0..8388608 for an UNDO action.
     * @return The current instance.
     * @throw IllegalArgumentException If the provided argument is out of range.
     * @throw IllegalStateException In one of the following cases:
     *     <ul>
     *       <li>Another SV command was already prepared inside the same secure session.
     *       <li>The SV command is not placed in the first position in the list of prepared
     * commands. <li>The SV command does not follow a "SV Get" command. <li>The command and the SV
     * operation are not consistent.
     *     </ul>
     *
     * @throw SessionBufferOverflowException If the command will overflow the modifications buffer
     *        size and the multiple session is not allowed.
     * @since 1.0.0
     */
    virtual T& prepareSvReload(const int amount) = 0;

    /**
     * Schedules the execution of a "SV Debit" or "SV Undebit" command to increase the current SV
     * balance or to partially or totally cancels the last SV debit command and using the provided
     * additional data.
     *
     * <p>It consists in decreasing the current balance of the SV by a certain amount or canceling a
     * previous debit according to the type operation chosen in when invoking the previous SV Get
     * command.
     *
     * <p>Data will be available in {@link CalypsoCard} using the dedicated SV data management
     * methods.
     *
     * <p>Note 1: the key used is the debit key
     *
     * @param amount The amount to be subtracted or added, positive integer in the range 0..32767
     *        when subtracted and 0..32768 when added.
     * @param date 2-byte free value.
     * @param time 2-byte free value.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided argument is out of range.
     * @throw IllegalStateException In one of the following cases:
     *     <ul>
     *       <li>New value is negative and negative balances are not allowed.
     *       <li>Another SV command was already prepared inside the same secure session.
     *       <li>The SV command is not placed in the first position in the list of prepared
     * commands. <li>The SV command does not follow a "SV Get" command. <li>The command and the SV
     * operation are not consistent.
     *     </ul>
     *
     * @throw SessionBufferOverflowException If the command will overflow the modifications buffer
     *        size and the multiple session is not allowed.
     * @since 1.0.0
     */
    virtual T& prepareSvDebit(
        const int amount, const std::vector<uint8_t>& date, const std::vector<uint8_t>& time)
        = 0;

    /**
     * Schedules the execution of a "SV Debit" or "SV Undebit" command to increase the current SV
     * balance or to partially or totally cancels the last SV debit command.
     *
     * <p>It consists in decreasing the current balance of the SV by a certain amount or canceling a
     * previous debit.
     *
     * <p>Data will be available in {@link CalypsoCard} using the dedicated SV data management
     * methods.
     *
     * <p>Note 1: the optional SV additional data are set to zero.
     *
     * <p>Note 2: the key used is the debit key.
     *
     * @param amount The amount to be subtracted or added, positive integer in the range 0..32767
     *        when subtracted and 0..32768 when added.
     * @return The current instance.
     * @throw IllegalArgumentException If one of the provided argument is out of range.
     * @throw IllegalStateException In one of the following cases:
     *     <ul>
     *       <li>New value is negative and negative balances are not allowed.
     *       <li>Another SV command was already prepared inside the same secure session.
     *       <li>The SV command is not placed in the first position in the list of prepared
     * commands. <li>The SV command does not follow a "SV Get" command. <li>The command and the SV
     * operation are not consistent.
     *     </ul>
     *
     * @throw SessionBufferOverflowException If the command will overflow the modifications buffer
     *        size and the multiple session is not allowed.
     * @since 1.0.0
     */
    virtual T& prepareSvDebit(const int amount) = 0;

    /**
     * Schedules the execution of an "Invalidate" command.
     *
     * <p>This command is usually executed within a secure session with the DEBIT key (depends on
     * the access rights given to this command in the file structure of the card).
     *
     * <p>The DF status will be available in {@link CalypsoCard} using the {@link
     * CalypsoCard#isDfInvalidated()} method.
     *
     * @throw IllegalStateException If the card is already invalidated.
     * @throw SessionBufferOverflowException If the command will overflow the modifications buffer
     *        size and the multiple session is not allowed.
     * @return The current instance.
     * @since 1.0.0
     */
    virtual T& prepareInvalidate() = 0;

    /**
     * Schedules the execution of a "Rehabilitate" command.
     *
     * <p>This command is usually executed within a secure session with the PERSONALIZATION key
     * (depends on the access rights given to this command in the file structure of the card).
     *
     * <p>The DF status will be available in {@link CalypsoCard} using the {@link
     * CalypsoCard#isDfInvalidated()} method.
     *
     * @return The current instance.
     * @throw IllegalStateException If the card is not invalidated.
     * @throw SessionBufferOverflowException If the command will overflow the modifications buffer
     *        size and the multiple session is not allowed.
     * @since 1.0.0
     */
    virtual T& prepareRehabilitate() = 0;

    /**
     * Schedules the execution of "Change Key" command to replace one of the current card keys with
     * another key present in the cryptographic module.
     *
     * <p>This command can be performed only out of a secure session.
     *
     * <p>The change key process transfers the key from the cryptographic module to the card. The
     * new key is diversified by the cryptographic module from a primary key and encrypted using the
     * indicated issuer key to secure the transfer to the card. All provided KIFs and KVCs must be
     * present in the cryptographic module.
     *
     * @param keyIndex The index of the key to be replaced (1 for the issuer key, 2 for the load
     *        key, 3 for the debit key).
     * @param newKif The KIF of the new key.
     * @param newKvc The KVC of the new key.
     * @param issuerKif The KIF of the current card's issuer key.
     * @param issuerKvc The KVC of the current card's issuer key.
     * @return The current instance.
     * @throw UnsupportedOperationException If the Change Key command is not available for this
     *        card.
     * @throw IllegalArgumentException If the provided key index is out of range.
     * @throw IllegalStateException If the command is executed while a secure session is open.
     * @since 1.6.0
     */
    virtual T& prepareChangeKey(
        const int keyIndex,
        const uint8_t newKif,
        const uint8_t newKvc,
        const uint8_t issuerKif,
        const uint8_t issuerKvc)
        = 0;
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
