#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
public:
    long long int prime_modulus, primitve_root;

    Entity(long long int primeModulus, long long int primitiveRoot);
    long long int computePublicKey(long long int private_key);
    long long int computeSharedSecret(long long int publicKey, long long int private_key);

private:
    long long int modExpression(long long int base, long long int exponent, long long int mod);
};

#endif ENTITY_HPP


