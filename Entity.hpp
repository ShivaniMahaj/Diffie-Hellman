#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
public:
    int prime_modulus, primitve_root; 

    Entity(int primeModulus, int primitiveRoot);
    int computePublicKey(int secret);
    int computeSharedSecret(int publicKey, int secret);

private:
    int modExpression(int base, int exponent, int mod);
};

#endif ENTITY_HPP


