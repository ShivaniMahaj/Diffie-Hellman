#include "Entity.hpp"
#include <cmath>
#include <iostream>


Entity::Entity(int primeModulus, int primitiveRoot) {
    prime_modulus = primeModulus;
    primitve_root = primitiveRoot;
}

int Entity::modExpression(int base, int exponent, int mod) {
    int result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent = exponent / 2;
    }

    return result;
}

int Entity::computePublicKey(int private_key) {
    int publicKey = modExpression(primitve_root, private_key, prime_modulus);
    return publicKey;
}

int Entity::computeSharedSecret(int publicKey, int private_key) {
    int sharedSecret = modExpression(publicKey, private_key, prime_modulus);
    return sharedSecret;
}

