#pragma once 

#include <boost/shared_ptr.hpp>
#include "secp256k1/secp256k1.h"


namespace BitCrypto{


class Secp256k1ContextDisposer
{
    public:
        void operator()(secp256k1_context *) const;
};


typedef boost::shared_ptr<secp256k1_context> Secp256k1ContextPtr;



class Secp256k1ContextFactory
{

    public:
        Secp256k1ContextPtr create() const;
        Secp256k1ContextPtr create(int flags) const;

    private:
        secp256k1_context * makeNew(int flags = SECP256K1_CONTEXT_SIGN|SECP256K1_CONTEXT_VERIFY) const;
};


}


