#include <iostream>
#include <vector>

    typedef std::string txt;

int GetDigit(const int number);
int sumOddDigits(const txt cardNum);
int sumEvenDigits(const txt cardNum);

int main() {

    txt cardNum;
    int result = 0;
        std::cout << "Enter a credit card No. to validate: ";
        std::cin >> cardNum;

    result = sumEvenDigits(cardNum) + sumOddDigits(cardNum);

    if (result % 10 == 0) {
        std::cout << cardNum << " is valid!";
    }
        else {
            std::cout << cardNum << " is not valid";
        }
}

int GetDigit(const int number) {

    return number % 10 + (number/10 % 10);
}
int sumOddDigits(const txt cardNum) {

    int sum = 0;

        for (int i = cardNum.size() - 1; i >= 0; i -=2) {
            sum += cardNum[i] - 48;
        }

    return sum;
}
int sumEvenDigits(const txt cardNum) {

    int sum = 0;

        for (int i = cardNum.size() -2; i >= 0; i -=2) {
            sum += GetDigit((cardNum[i] - 48) * 2);
        }

    return sum;
}
