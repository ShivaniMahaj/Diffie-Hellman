#include <iostream>
#include <ctime>
#include "Entity.hpp"
#include "User.hpp"
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    long long int prime_modulus, primitive_root;
    cout << "Enter the prime modulus: ";
    cin >> prime_modulus;
    cout << "Enter the primitive root: ";
    cin >> primitive_root;

    Entity entity(prime_modulus, primitive_root);

    User alice("Alice", &entity);
    User bob("Bob", &entity);

    alice.selectPrivateKey();
    bob.selectPrivateKey();

    alice.generatePublicKey();
    bob.generatePublicKey();

    bob.receivePublicKey(alice.getPublicKey());
    alice.receivePublicKey(bob.getPublicKey());

    alice.computeSharedSecret(alice.getReceivedPublicKey());
    bob.computeSharedSecret(bob.getReceivedPublicKey());

    return 0;
}
