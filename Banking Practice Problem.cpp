#include <iostream>
#include <iomanip>

    using namespace std;

void showBAL(double balance);
    double deposit();
        double withdraw(double balance);

int main() {
    double balance = 0;
    int choice = 0;

        do {
            cout << "**********************" << endl;
            cout << "Enter your choice" << endl;
            cout << "**********************" << endl;
            cout << "1. Show Balance" << endl;
            cout << "2. Deposit Money" << endl;
            cout << "3. Withdraw Money" << endl;
            cout << "4. Exit the Program :(" << endl;
            cin >> choice;

            switch (choice) {
                case 1: showBAL(balance);
                        break;
                case 2: balance += deposit();
                        showBAL(balance);
                        break;
                case 3: balance -= withdraw(balance);
                        showBAL(balance);
                        break;
                case 4: cout << "Thanks for your time :)";
                        break;

                default: cout << "Invalid Response!";
                        break;
            }
        }
            while (choice != 4);

            return 0;
}
void showBAL(double balance) {
    cout << "Your balance is: $" << setprecision(2) << fixed << balance << endl;
        return;
}
    double deposit() {
        double amount;
        cout << "Enter the amount to deposit in your bank account: ";
            cin >> amount;

            if (amount > 0) {
                return amount;
            }
                else {
                    cout << "Enter a valid response!" << endl;
                        return 0;
                }
               

    }
        double withdraw(double balance) {
            double amount = 0;
                cout << "Enter the withdrawal amount: ";
                    cin >> amount;

                    if (amount > balance) {
                        cout << "Bro you can't withdraw more than you have :/" << endl;
                            return 0;
                       
                    }   
                        else if (amount < 0) {
                            cout << "Invalid Amount!" << endl;
                                return 0;
                        }
                            else {
                                return amount;
                            }
        }
