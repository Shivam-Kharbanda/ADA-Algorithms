#include <iostream>
using namespace std;

int fact(int num) {
    if (num <= 1)
        return 1;
    return num * fact(num - 1);
}

int main() {
    int n = 6, r = 3;
    int permutation = fact(n) / fact(n - r);
    
    cout << "Permutation (nPr) = " << permutation << endl;
    return 0;
}
