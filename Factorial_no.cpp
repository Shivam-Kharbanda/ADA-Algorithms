#include <iostream>
using namespace std;

int fact(int num) {
    if (num <= 1)
        return 1;
    return num * fact(num - 1);
}

int main() {
    int num = 8;
    int result = fact(num);
    
    cout << "Factorial of " << num << " is: " << result << endl;
    return 0;
}
