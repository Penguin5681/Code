#include <iostream>

int FactorialFN(int x) {

    if (x > 1) {
        return x * FactorialFN(x - 1);
    }
        else {
            return 1;
        }
}

int Combination(int n ,int r) {

    int numerator;
    int denominator;

    numerator = FactorialFN(n);
    denominator = FactorialFN(r) * FactorialFN(n - r);
    return numerator / denominator;

}

int main() {

    int n, r;
    std::cout << "For the Combination Formula (nCr), Enter n & r: ";
    std::cin >> n >> r;

    std::cout << n << "C" << r << " = " << Combination(n, r);

    return 0;
}
