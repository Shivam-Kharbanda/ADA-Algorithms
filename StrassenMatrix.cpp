#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void add(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC, int newMSize) {
    for (int i = 0; i < newMSize; i++) {
        for (int j = 0; j < newMSize; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void sub(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC, int newMSize) {
    for (int i = 0; i < newMSize; i++) {
        for (int j = 0; j < newMSize; j++) {
            matrixC[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void printMatrix(vector<vector<int>> matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " \t ";
        }
        cout << endl;
    }
    cout << endl;
}

void strassenR(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &matrixC, int mSize) {
    if (mSize == 1) {
        matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
        return;
    }

    int newMSize = mSize / 2;
    vector<int> innerVector(newMSize, 0);
    vector<vector<int>> matrixA11(newMSize, innerVector), matrixA12(newMSize, innerVector),
        matrixA21(newMSize, innerVector), matrixA22(newMSize, innerVector),
        matrixB11(newMSize, innerVector), matrixB12(newMSize, innerVector),
        matrixB21(newMSize, innerVector), matrixB22(newMSize, innerVector),
        matrixC11(newMSize, innerVector), matrixC12(newMSize, innerVector),
        matrixC21(newMSize, innerVector), matrixC22(newMSize, innerVector),
        s1(newMSize, innerVector), s2(newMSize, innerVector),
        s3(newMSize, innerVector), s4(newMSize, innerVector),
        s5(newMSize, innerVector), s6(newMSize, innerVector),
        s7(newMSize, innerVector), s8(newMSize, innerVector),
        s9(newMSize, innerVector), s10(newMSize, innerVector),
        p1(newMSize, innerVector), p2(newMSize, innerVector),
        p3(newMSize, innerVector), p4(newMSize, innerVector),
        p5(newMSize, innerVector), p6(newMSize, innerVector),
        p7(newMSize, innerVector), tempMatrixA(newMSize, innerVector),
        tempMatrixB(newMSize, innerVector);

    for (int i = 0; i < newMSize; i++) {
        for (int j = 0; j < newMSize; j++) {
            matrixA11[i][j] = matrixA[i][j];
            matrixA12[i][j] = matrixA[i][j + newMSize];
            matrixA21[i][j] = matrixA[i + newMSize][j];
            matrixA22[i][j] = matrixA[i + newMSize][j + newMSize];

            matrixB11[i][j] = matrixB[i][j];
            matrixB12[i][j] = matrixB[i][j + newMSize];
            matrixB21[i][j] = matrixB[i + newMSize][j];
            matrixB22[i][j] = matrixB[i + newMSize][j + newMSize];
        }
    }

    sub(matrixB12, matrixB22, s1, newMSize);
    add(matrixA11, matrixA12, s2, newMSize);
    add(matrixA21, matrixA22, s3, newMSize);
    sub(matrixB21, matrixB11, s4, newMSize);
    add(matrixA11, matrixA22, s5, newMSize);
    add(matrixB11, matrixB22, s6, newMSize);
    sub(matrixA12, matrixA22, s7, newMSize);
    add(matrixB21, matrixB22, s8, newMSize);
    sub(matrixA11, matrixA21, s9, newMSize);
    add(matrixB11, matrixB12, s10, newMSize);

    strassenR(matrixA11, s1, p1, newMSize);
    strassenR(s2, matrixB22, p2, newMSize);
    strassenR(s3, matrixB11, p3, newMSize);
    strassenR(matrixA22, s4, p4, newMSize);
    strassenR(s5, s6, p5, newMSize);
    strassenR(s7, s8, p6, newMSize);
    strassenR(s9, s10, p7, newMSize);

    add(p5, p4, tempMatrixA, newMSize);
    add(tempMatrixA, p6, tempMatrixB, newMSize);
    sub(tempMatrixB, p2, matrixC11, newMSize);

    add(p1, p2, matrixC12, newMSize);
    add(p3, p4, matrixC21, newMSize);

    add(p5, p1, tempMatrixA, newMSize);
    sub(tempMatrixA, p3, tempMatrixB, newMSize);
    sub(tempMatrixB, p7, matrixC22, newMSize);

    for (int i = 0; i < newMSize; i++) {
        for (int j = 0; j < newMSize; j++) {
            matrixC[i][j] = matrixC11[i][j];
            matrixC[i][j + newMSize] = matrixC12[i][j];
            matrixC[i + newMSize][j] = matrixC21[i][j];
            matrixC[i + newMSize][j + newMSize] = matrixC22[i][j];
        }
    }
}

void strassen(vector<vector<int>> &matrixA, vector<vector<int>> &matrixB, vector<vector<int>> &result, int mSize) {
    strassenR(matrixA, matrixB, result, mSize);
}

int main() {
    int mSize;
    cout << "Enter the size of the square matrix: " << endl;
    cin >> mSize;

    vector<vector<int>> matrixA(mSize, vector<int>(mSize));
    cout << "Enter the elements of matrix A: " << endl;
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            cin >> matrixA[i][j];
        }
    }

    vector<vector<int>> matrixB(mSize, vector<int>(mSize));
    cout << "Enter the elements of matrix B: " << endl;
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            cin >> matrixB[i][j];
        }
    }

    if (mSize < 1 || mSize > 256) {
        cout << endl << "ERROR: n must be between 1 and 256 (including 1 and 256)" << endl;
        return 0;
    } else if (ceil(log2(mSize)) != floor(log2(mSize))) {
        cout << endl << "ERROR: matrix size must be a power of 2" << endl;
        return 0;
    }

    vector<vector<int>> result(mSize, vector<int>(mSize));
    strassen(matrixA, matrixB, result, mSize);

    cout << endl << "MATRIX C = A * B" << endl;
    printMatrix(result, mSize);

    return 0;
}
