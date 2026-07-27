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
#include <memory>

#include "keypop/calypso/card/transaction/spi/CaCertificate.hpp"
#include "keypop/calypso/card/transaction/spi/CaCertificateParser.hpp"
#include "keypop/calypso/card/transaction/spi/CardCertificateParser.hpp"
#include "keypop/calypso/card/transaction/spi/PcaCertificate.hpp"

namespace keypop {
namespace calypso {
namespace card {
namespace transaction {

using keypop::calypso::card::transaction::spi::CaCertificate;
using keypop::calypso::card::transaction::spi::CaCertificateParser;
using keypop::calypso::card::transaction::spi::CardCertificateParser;
using keypop::calypso::card::transaction::spi::PcaCertificate;

/**
 * Security setting for a Calypso card transaction secured by "asymmetric" key
 * cryptographic algorithms (PKI).
 *
 * @since 2.1.0
 */
class AsymmetricCryptoSecuritySetting {
public:
    /**
     * Virtual destructor.
     */
    virtual ~AsymmetricCryptoSecuritySetting() = default;

    /**
     * Registers a self-signed PCA certificate.
     *
     * <p>This method performs various checks to ensure the integrity and
     * validity of the provided PCA certificate. These checks include verifying
     * the certificate's signature to ensure it is self-signed, checking the
     * validity period to ensure the certificate is not expired or prematurely
     * valid, and confirming the authenticity of the issuer and subject details.
     * Additionally, it checks for compliance with relevant constraints or
     * extensions that may be necessary for PCA certificates.
     *
     * @param pcaCertificate The PCA certificate to add. Must be a valid,
     *        self-signed certificate.
     * @return The current instance.
     * @throw IllegalArgumentException If the argument is null or invalid.
     * @throw IllegalStateException If the contained public key has already been
     *        registered.
     * @throw InvalidCertificateException If the check of the provided
     *        certificate failed.
     * @since 2.1.0
     */
    virtual AsymmetricCryptoSecuritySetting&
    addPcaCertificate(const std::shared_ptr<PcaCertificate> pcaCertificate) = 0;

    /**
     * Registers a CA certificate.
     *
     * <p>Preloading a CA certificate avoids having to read it from the card.
     *
     * <p>This method performs various checks to ensure the integrity and
     * validity of the provided CA certificate. These checks include verifying
     * the certificate's signature using the issuer's public key, checking the
     * validity period to ensure the certificate is not expired or prematurely
     * valid, and confirming the authenticity of the issuer and subject details.
     * Additionally, it checks for compliance with relevant constraints or
     * extensions that may be necessary for CA certificates.
     *
     * <p>Please note that the issuer's certificate must be loaded first.
     *
     * @param caCertificate The CA certificate to add. Must be a valid, signed
     *        certificate.
     * @return The current instance.
     * @throw IllegalArgumentException If the argument is null or invalid.
     * @throw IllegalStateException If the contained public key already been
     *        registered.
     * @throw InvalidCertificateException If the check of the provided
     *        certificate failed.
     * @see #addPcaCertificate(PcaCertificate)
     * @since 2.1.0
     */
    virtual AsymmetricCryptoSecuritySetting&
    addCaCertificate(const std::shared_ptr<CaCertificate> caCertificate) = 0;

    /**
     * Registers a CA certificate parser.
     *
     * <p>The parser provides the means to build a CaCertificate from the raw
     * data read from the card.
     *
     * <p>This parser will only be used if the CA certificate is not already
     * available.
     *
     * @param caCertificateParser The CA certificate parser to add.
     * @return The current instance.
     * @throw IllegalArgumentException If the argument is null or invalid.
     * @throw IllegalStateException If a parser associated with the same
     *        certificate type is already registered.
     * @since 2.1.0
     */
    virtual AsymmetricCryptoSecuritySetting& addCaCertificateParser(
        const std::shared_ptr<CaCertificateParser> caCertificateParser) = 0;

    /**
     * Registers a card certificate parser.
     *
     * <p>The parser provides the means to build a card certificate from the raw
     * data read from the card.
     *
     * @param cardCertificateParser The card certificate parser to add.
     * @return The current instance.
     * @throw IllegalArgumentException If the argument is null or invalid.
     * @throw IllegalStateException If a parser associated with the same
     *        certificate type is already registered.
     * @since 2.1.0
     */
    virtual AsymmetricCryptoSecuritySetting& addCardCertificateParser(
        const std::shared_ptr<CardCertificateParser> cardCertificateParser) = 0;
};

} /* namespace transaction */
} /* namespace card */
} /* namespace calypso */
} /* namespace keypop */
