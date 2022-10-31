// Aleth: Ethereum C++ client, tools and libraries.
// Copyright 2019 Aleth Authors.
// Licensed under the GNU General Public License, Version 3.

#pragma once

#include "Common.h"

namespace dev
{
namespace p2p
{
DEV_SIMPLE_EXCEPTION(ENRIsTooBig);
DEV_SIMPLE_EXCEPTION(ENRSignatureIsInvalid);
DEV_SIMPLE_EXCEPTION(ENRKeysAreNotUniqueSorted);

/// Class representing Ethereum Node Record - see EIP-778
class ENR
{
public:
    // ENR class implementation is independent of Identity Scheme.
    // Identity Scheme specifics are passed to ENR as functions.

    // Sign function gets serialized ENR contents and signs it according to some Identity Scheme
    using SignFunction = std::function<bytes(bytesConstRef)>;
    // Verify function gets ENR key-value pairs, signature, and serialized content and validates the
    // signature according to some Identity Scheme
    using VerifyFunction =
        std::function<bool(std::map<std::string, bytes> const&, bytesConstRef, bytesConstRef)>;

    // Parse from RLP with given signature verification function
    ENR(RLP _rlp, VerifyFunction const& _verifyFunction);
    // Create with given sign function
    ENR(uint64_t _seq, std::map<std::string, bytes> const& _keyValues,
        SignFunction const& _signFunction);

    uint64_t sequenceNumber() const { return m_seq; }
    std::map<std::string, bytes> const& keyValuePairs() const { return m_map; }
    bytes const& signature() const { return m_signature; }

    // Serialize to given RLP stream
    void streamRLP(RLPStream& _s) const;

private:
    uint64_t m_seq = 0;
    std::map<std::string, bytes> m_map;
    bytes m_signature;

    bytes content() const;
    size_t contentRlpListItemCount() const { return m_map.size() * 2 + 1; }
    void streamContent(RLPStream& _s) const;
};


ENR createV4ENR(Secret const& _secret, boost::asio::ip::address const& _ip, uint16_t _tcpPort,  uint16_t _udpPort);

ENR parseV4ENR(RLP _rlp);

std::ostream& operator<<(std::ostream& _out, ENR const& _enr);

}
}
