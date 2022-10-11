#include <iostream>

int FactorialFN(int num) {
    
        if (num > 1) {
            return num * FactorialFN(num - 1);
        }
            else {
                return 1;
            }
}

int main() {

    int n;
    std::cin >> n;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << FactorialFN(i)/(FactorialFN(j) * FactorialFN (i-j)) << " ";
        }
            std::cout << '\n';
    }
}
