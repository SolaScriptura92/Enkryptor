//
//  Cryptic.h
//  Enkryptor
//
//  Created by Jose on 6/10/19.
//  Copyright © 2019 Jose'sProjects. All rights reserved.
//

#ifndef Cryptic_h
#define Cryptic_h

#include <map>
#include <string>
#include <iterator>
#include <math.h>
#include "Matrix.h"

using namespace std;

class Cryptic
{

private:

    map<int, char> substitutions;
    string message = "";
    string recreatedMessage = "";
    Matrix encoder;
    Matrix decoder;
    Matrix encodedMessage;
    
public:
    
    Cryptic(); //the default contructor;
    void getCharMap();
    void getMessage();
    void encode();
    void decode();
    void generateEncoder();
    void generateDecoder();
    void printMessage();
    void printEncryptedMessage();
    void getDecryptedMessage();
};


#endif /* Cryptic_h */
