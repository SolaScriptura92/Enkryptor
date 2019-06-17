/*
    The purpose of this program is to encrypt messages as well as provide a key
    for the user to give to the person they want to have it in order to
    decrypt the message.
 
 Author: Jose Sanchez
 */

#include <iostream>
#include "Cryptic.h"

using namespace std;

int main()
{
    cout << "Hello, and welcome to my encryption program! :)\n\n";
    
    Cryptic c;
    
    c.getMessage();
    c.encode();
    c.printEncryptedMessage();
    c.decode();
    c.getDecryptedMessage();
    
    cout << endl;
    
    return 0;
}
