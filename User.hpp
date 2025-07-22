#ifndef USER_HPP
#define USER_HPP

#include "Entity.hpp"
#include <string>

class User {
private:
    long long int sharedSecret;
    long long int receivedPublicKey;

public:
    std::string name;
    long long int privateKey, publicKey;
    Entity* entity;

    User(std::string userName, Entity* entityObj);
    void selectPrivateKey();
    void generatePublicKey();
    long long int getPublicKey();
    long long int getReceivedPublicKey();
    void receivePublicKey(long long int receivedPublicKey);
    void computeSharedSecret(long long int otherPublicKey);
};

#endif USER_HPP

