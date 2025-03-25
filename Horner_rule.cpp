#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int evaluatePolynomial(const vector<int>& coeffs, int x) {
    int result = 0;
    int n = coeffs.size();
    for(int i = 0; i < n; i++) {
        result += coeffs[i] * pow(x, n - 1 - i);
    }
    return result;
}

int main() {
    vector<int> coefficients = {3, -5, 4, -2}; 
    int x;
    
    cout << "Enter the value of x: ";
    cin >> x;

    int sum = evaluatePolynomial(coefficients, x);
    cout << "Polynomial evaluation result: " << sum << endl;

    return 0;
}
