#include <iostream>
#include <ctime>
#include "Entity.hpp"
#include "User.hpp"
using namespace std;

int main() {
    srand(time(0));

    int prime_modulus, primitive_root;
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
    bob.receivePublicKey(alice.publicKey);

    bob.generatePublicKey();
    alice.receivePublicKey(bob.publicKey);

    alice.computeSharedSecret(bob.publicKey);
    bob.computeSharedSecret(alice.publicKey);

    return 0;
}
