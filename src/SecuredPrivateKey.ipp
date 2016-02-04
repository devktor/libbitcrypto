
namespace Ethereum{


template<class Cipher>
template<class CipherKey>
SecuredPrivateKey<Cipher>::SecuredPrivateKey(const PrivateKey &privateKey, const Cipher &cipher, const CipherKey &key) :
    _cipher(cipher),
    _privateKey(cipher.encrypt(privateKey, key))
{}


template<class Cipher>
SecuredPrivateKey<Cipher>::SecuredPrivateKey(const EncryptedData &privateKey, const Cipher &cipher) :
    _cipher(cipher),
    _privateKey(privateKey)
{}



template<class Cipher>
template<class CipherKey>
PrivateKey SecuredPrivateKey<Cipher>::unlock(const CipherKey &key) const
{
    return _cipher.decrypt(_privateKey, key);
}


template<class Cipher>
const EncryptedData & SecuredPrivateKey<Cipher>::getData() const
{
    return _privateKey;
}


template<class Cipher>
EncryptedData & SecuredPrivateKey<Cipher>::getData()
{
    return _privateKey;
}


template<class Cipher>
const Cipher & SecuredPrivateKey<Cipher>::getCipher() const
{
    return _cipher;
}


}
