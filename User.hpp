#ifndef USER_HPP
#define USER_HPP

#include "Entity.hpp"
#include <string>

class User {
private:
    int sharedSecret;

public:
    std::string name;
    int privateKey, publicKey;
    Entity* entity;

    User(std::string userName, Entity* entityObj);
    void selectPrivateKey();
    void generatePublicKey();
    void receivePublicKey(int receivedPublicKey);
    void computeSharedSecret(int otherPublicKey);
};

#endif USER_HPP

