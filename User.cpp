#include "User.hpp"
#include <iostream>
#include <cstdlib>

User::User(std::string userName, Entity* entityObj) {
    name = userName;
    entity = entityObj;
    privateKey = 0;
    publicKey = 0;
    sharedSecret = 0;
}

void User::selectPrivateKey() {
    privateKey = rand() % (entity->prime_modulus - 2) + 2;
    std::cout << name << " selected private key: " << privateKey << std::endl;
}

void User::generatePublicKey() {
    publicKey = entity->computePublicKey(privateKey);
    std::cout << name << " generated public key: " << publicKey << std::endl;
}

void User::receivePublicKey(long long int receivedPublicKey) {
    this->receivedPublicKey = receivedPublicKey;
    std::cout << name << " received public key: " << receivedPublicKey << std::endl;
}

long long int User::getPublicKey() {
    return this->publicKey;
}

long long int User::getReceivedPublicKey() {
    return this->receivedPublicKey;
}

void User::computeSharedSecret(long long int otherPublicKey) {
    sharedSecret = entity->computeSharedSecret(otherPublicKey, privateKey);
    std::cout << name << " computed shared secret: " << sharedSecret << std::endl;
}


