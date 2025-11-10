//Here's an assignment that'll give you some practice with arrays, specifically 2D arrays. All you have to do is write a program that allows the user to populate two 2D arrays of integers (3 x 3 matrix) by calling the 
//function InitMatrix. After the user has entered all the values, then call the function DispMatrix to display the two matrices. Then you can call the functions AddMatrices, TMatrix, and DetMatrix to calculate the 
//addition of the matrices, the transpose of each matrix, and the determinant of each matrix respectively.   

//InitMatrix will take as argument a 2D array and the number of rows and have a void return type.  It will prompt the user to enter 9 total values for a 3 x 3 matrix.

//DispMatrix will take as argument a 2D array and the number of rows and have a void return type.  It will display the contents of the 2D array. Hint: I suggest you use 
//the setw() function to display the matrices nicely.

//AddMatrix will take as argument two 2D arrays and the number of rows and have a void return type. It will add two 2D arrays and call DispMatrix to output the result.

//TMatrix will take as argument a 2D array and the number of rows and have a void return type. It will switch the rows and columns and call DispMatrix to output the result.

//DetMatrix will take as argument a 2D array and the number of rows and have an int return type.  It will calculate the determinate of a 2D array and return the result as an int.

#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

///function prototypes
void InitMatrix(int matrix[SIZE][SIZE]);
void DispMatrix(int matrix[SIZE][SIZE]);
void AddMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);
void TMatrix(int matrix[SIZE][SIZE]);
int DetMatrix(int matrix[SIZE][SIZE]);

int main() {
    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];

    cout << "Enter values for the first 3x3 matrix:" << endl;
    InitMatrix(matrix1);
    cout << "Enter values for the second 3x3 matrix:" << endl;
    InitMatrix(matrix2);

    cout << "\nFirst Matrix:" << endl;
    DispMatrix(matrix1);
    cout << "\nSecond Matrix:" << endl;
    DispMatrix(matrix2);

    cout << "\nSum of the two matrices:" << endl;
    AddMatrices(matrix1, matrix2);

    cout << "\nTranspose of the first matrix:" << endl;
    TMatrix(matrix1);
    cout << "\nTranspose of the second matrix:" << endl;
    TMatrix(matrix2);

    cout << "\nDeterminant of the first matrix: " << DetMatrix(matrix1) << endl;
    cout << "Determinant of the second matrix: " << DetMatrix(matrix2) << endl;

    return 0;
}

void InitMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Enter value for element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void DispMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void AddMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    int sumMatrix[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    DispMatrix(sumMatrix);
}

void TMatrix(int matrix[SIZE][SIZE]) {
    int transposed[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    DispMatrix(transposed);
}

int DetMatrix(int matrix[SIZE][SIZE]) {
    int determinant = 0;
    // Calculate the determinant using the formula for 3x3 matrices
    determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
                - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
                + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return determinant;
}

//End of Code
