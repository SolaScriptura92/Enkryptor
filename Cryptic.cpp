//
//  Cryptic.cpp
//  Enkryptor
//
//  Created by Jose on 6/10/19.
//  Copyright © 2019 Jose'sProjects. All rights reserved.
//

#include "Cryptic.h"
#include "Matrix.h"

Cryptic::Cryptic() //default constructor
{
    getCharMap();
    Matrix x(2,2);
    encoder = x;
    generateEncoder();
    
}

void Cryptic::getCharMap()
{
    substitutions.insert(pair<int, char>(0, ' '));
    
    for(int i = 65; i <= 90; i++)
    {
        substitutions.insert(pair<int, char>((i - 64), static_cast<char>(i)));
    }
    
    for(int i = 97; i <= 122; i++)
    {
        substitutions.insert(pair<int, char>((i - 70), static_cast<char>(i)));
    }
}


void Cryptic::getMessage()
{
    cout << "\nPlease enter the message (letters and spaces only) you would like to encode below: " << endl;
    cout << "\nYour message -> ";
    getline(cin, message);
}

void Cryptic::encode()
{
    Matrix mappedMatrix(ceil(static_cast<double>(message.length()) / encoder.getNumRows()), encoder.getNumRows());
    int messageIndex = 0;
    
    for (int i = 0; i < mappedMatrix.getNumRows(); i++)
    {
        for (int j = 0; j < mappedMatrix.getNumColumns(); j++)
        {
            if(messageIndex < message.length())
            {
                auto it = substitutions.begin();
                
                while(it != substitutions.end())
                {
                    if (it->second == message[messageIndex])
                    {
                        mappedMatrix.setValue(i, j, it->first);
                        break;
                    }
                    
                    else
                        it++;
                }
    
                messageIndex++;
            }
            
            else
            {
                mappedMatrix.setValue(i, j, 0);
            }
        }
    }
    
    encodedMessage = mappedMatrix * encoder;
}

void Cryptic::decode()
{
    generateDecoder();
    
    Matrix product;
    product = encodedMessage * decoder;
    double scalar = 1.0 / encoder.getDeterminant();
    
    for(int i = 0; i < product.getNumRows(); i++)
    {
        for(int j = 0; j < product.getNumColumns(); j++)
        {
            product.setValue(i, j, (scalar * product.getValue(i, j)));
            recreatedMessage += substitutions[product.getValue(i, j)];
        }
    }
}

void Cryptic::generateEncoder()
{
    //******** HARD CODED FOR NOW BY GETTING FROM USER...
    encoder.getUserMatrix();
}

void Cryptic::generateDecoder()
{
    //HARD CODED FOR NOW...APPLY FORMULA...
    decoder = encoder;
    int temp = decoder.getValue(0, 0);
    decoder.setValue(0, 0, decoder.getValue(1, 1));
    decoder.setValue(1, 1, temp);
    decoder.setValue(0, 1, (decoder.getValue(0, 1) * -1));
    decoder.setValue(1, 0, (decoder.getValue(1, 0) * -1));
}

void Cryptic::printMessage()
{
    cout << message;
}

void Cryptic::printEncryptedMessage()
{
    cout << "\nYour message encrypted: " << endl << endl;
    encodedMessage.printMatrix();
}

void Cryptic::getDecryptedMessage()
{
    cout << "\nYour message decrypted: " << endl << endl;
    cout << recreatedMessage << endl;
}
