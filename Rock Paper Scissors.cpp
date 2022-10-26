// A simple Rock-Paper-Scissors Game code;
#include <iostream>
#include <ctime>

    using namespace std;

char GetPlayerChoice(); 
    char GetComputerChoice();
        char ShowChoice(char choice);
            void ShowWinner(char player, char computer);

int main() {

    char player;
    char computer;

        player = GetPlayerChoice();
        cout << "You Choose ";
        ShowChoice(player);

        computer = GetComputerChoice();
        cout << "Computer's Choice is: ";
        ShowChoice(computer);

        ShowWinner(player, computer);
            return 0;
}

char GetPlayerChoice() {

         char player;
    do {
       
            cout << "Welcome to Rock-Paper-Scissors Game" << endl;
            cout << "***********************************" << endl;
            cout << "The Instructions are as follows: " << endl;
            cout << "********************************" << endl;
            cout << "Press R for rock" << endl;
            cout << "Press P for paper" << endl;
            cout << "Press S for scissors" << endl;

            cin >> player;
    }
        while (player != 'R' && player != 'P' && player != 'S');
}
        char GetComputerChoice() {
            srand(time(NULL));

            int num = (rand() % 3) + 1;
                switch (num) {
                    case 1: return 'R';
                    case 2: return 'P';
                    case 3: return 'S';
                }
        }
            char ShowChoice(char choice) {

            switch (choice) {
                case 'R': cout << "ROCK" << endl;
                        break;
                case 'P': cout << "PAPER" << endl;
                        break;
                case 'S': cout << "Scissors" << endl;
                        break;
        }

    }
        void ShowWinner(char player, char computer) {
            
            switch (player) {
                case 'P': if (computer == 'P') {
                            cout << "It's a TIE!";
                            }
                                else if (computer == 'S') {
                                    cout << "Computer Wins ;)";
                                }
                                    else if (computer == 'R') {
                                        cout << "You win!";
                                    }
                break;
                case 'R': if (computer == 'R') {
                            cout << "It's a TIE!";
                            }
                                else if (computer == 'P') {
                                    cout << "Computer Wins ;)";
                                }
                                    else if (computer == 'S') {
                                        cout << "You win!";
                                    }
                break;
                case 'S': if (computer == 'S') {
                            cout << "It's a TIE!";
                            }
                                else if (computer == 'R') {
                                    cout << "Computer Wins ;)";
                                }
                                    else if (computer == 'P') {
                                        cout << "You win!";
                                    }
            }
        }
