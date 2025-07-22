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

int Entity::computePublicKey(int secret) {
    int publicKey = modExpression(primitve_root, secret, prime_modulus);
    std::cout << "key Value I'm getting in computePublicKey " << primitve_root << "    " << secret << "    " << prime_modulus << std::endl;
    std::cout << "Computed Public Key: " << publicKey << std::endl;
    return publicKey;
}

int Entity::computeSharedSecret(int publicKey, int secret) {
    int sharedSecret = modExpression(publicKey, secret, prime_modulus);
    std::cout << "key Value I'm getting in computeSharedSecret " << publicKey << "    " << secret << "    " << prime_modulus << std::endl;
    std::cout << "Computed Shared Secret: " << sharedSecret << std::endl;
    return sharedSecret;
}

