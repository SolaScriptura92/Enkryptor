/*
 Matrix.h
 MatrixApp
 
 This file contains what could be called the skeleton of the Matrix.cpp file. It defines the class by declaring the access type of
 its data and functions.
 */

#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix
{
private:
    vector<vector<int>> matrix;
    
    
public:
    Matrix(int rows = 0, int columns = 0);
    void printMatrix();  //Needs to have changes made so that output it neatly formatted.
    Matrix operator+(Matrix &a);
    Matrix operator-(Matrix &a);
    Matrix operator*(Matrix &a);
    Matrix transpose();
    int getNumRows();
    int getNumColumns();
    int getValue(int row, int column);
    int getDeterminant(); //only coded to work with 2 x 2 matrices for now...
    void setValue(int row, int column, int value);
    void getUserMatrix();
    void randomFill();
    bool isRowEchelonForm();
    bool isReducedRowEchelonForm();
    bool isValidRow(string row, int columns, vector<int> &numbers);
    bool isEqual(Matrix &x);
    
    
};

#endif /* Matrix_h */
