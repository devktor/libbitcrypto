
#include "DummyCipher.hpp"


namespace BitCrypto{


PrivateKey DummyCipher::decrypt(const Data &data, const DummyKey &)
{
    if(data.size() != 32)
    {
        throw std::runtime_error("invalid data");
    }
    PrivateKey PrivateKey;
    std::copy(data.begin(), data.end(), PrivateKey.begin());
    return PrivateKey;
}


Data DummyCipher::encrypt(const PrivateKey &PrivateKey, const DummyKey &)
{
    Data data;
    data.resize(32);
    std::copy(PrivateKey.begin(), PrivateKey.end(), data.begin());
    return data;
}

}
