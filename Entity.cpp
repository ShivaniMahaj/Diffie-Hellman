#include "Entity.hpp"
#include <cmath>
#include <iostream>


Entity::Entity(long long int primeModulus, long long int primitiveRoot) {
    prime_modulus = primeModulus;
    primitve_root = primitiveRoot;
}

long long int Entity::modExpression(long long int base, long long int exponent, long long int mod) {
    long long int result = 1;
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

long long int Entity::computePublicKey(long long int private_key) {
    long long int publicKey = modExpression(primitve_root, private_key, prime_modulus);
    return publicKey;
}

long long int Entity::computeSharedSecret(long long int publicKey, long long int private_key) {
    long long int sharedSecret = modExpression(publicKey, private_key, prime_modulus);
    return sharedSecret;
}

