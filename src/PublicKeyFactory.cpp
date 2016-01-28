#include "PublicKeyFactory.hpp"


namespace Ethereum{


PublicKeyFactory::PublicKeyFactory(const Secp256k1ContextPtr &context) : 
    Secp256k1Handler(context)
{}


PublicKeyFactory::PublicKeyFactory()
{}


PublicKey PublicKeyFactory::createFromSecret(const PrivateKey &secret)
{
    return createFromSecretData(secret);
}



template<class Point>
PublicKey PublicKeyFactory::createFromPointData(const Point &point)
{
    BinaryPublicKeySerializer serializer(getContext());
    PublicKey key(getContext());

    if(!serializer.unserialize(point, key))
    {
        throw std::runtime_error("invalid point");
    }

    return key;
}


PublicKey PublicKeyFactory::createFromPoint(const Data &point)
{
    return createFromPointData(point);
}


PublicKey PublicKeyFactory::createFromPoint(const UncompressedPoint &point)
{
    return createFromPointData(point);
}


PublicKey PublicKeyFactory::createFromPoint(const CompressedPoint &point)
{
    return createFromPointData(point);
}


}
