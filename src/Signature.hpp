#pragma once

#include <algorithm>
#include "bitcrypto/secp256k1/secp256k1.h"


namespace BitCrypto{


class Signature
{
    public:

        Signature();
        Signature(const Signature &);
        Signature(const secp256k1_ecdsa_signature &);

        secp256k1_ecdsa_signature * operator & ();
        const secp256k1_ecdsa_signature * operator & () const;

    private:
        secp256k1_ecdsa_signature _data;

};


}

