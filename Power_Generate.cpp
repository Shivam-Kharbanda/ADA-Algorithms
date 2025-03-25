#include <iostream>
using namespace std;

int computePower(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * computePower(base, exp - 1);
}

int main() {
    int base = 4, exponent = 2;
    int result = computePower(base, exponent);
    
    cout << "Result: " << result << endl;
    return 0;
}
