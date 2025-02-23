#include <iostream>
#include <random>
using namespace std;
int getAttempts() {
    int choice;
    cout << "Please select the difficulty level:\n"
        << "1. Easy (10 chances)\n"
        << "2. Medium (5 chances)\n"
        << "3. Hard (3 chances)\n"
        << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: return 10;
        case 2: return 5;
        case 3: return 3;
        default:
            cout << "Invalid choice, defaulting to Medium level (5 chances).\n";
    }
}
void GuessNumber(int random_number, int& valueIndex) {
    int guessNumber = 0;
    int guessIndex = 1;
    while (valueIndex > 0) {
        cout << "Enter your guess: ";
        cin >> guessNumber;

        if (guessNumber < random_number) {
            cout << "Incorrect! The number is greater than " << guessNumber << endl;
        }
        else if (guessNumber > random_number) {
            cout << "Incorrect! The number is less than " << guessNumber << endl;
        }
        else {
            cout << "Congratulations! You guessed the correct number in " << guessIndex << " attempts." << endl;
            return;
        }

        --valueIndex;
        ++guessIndex;

        if (valueIndex == 0) {
            cout << "You've run out of attempts! The correct number was: " << random_number << endl;
        }
    }
    
}
bool playAgain() {
    string choice;
    cout << "Do you want to play again? (yes / no)";
    cin >> choice;
    return choice == "yes";
}
int main()
{
    
    std::cout << "Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between 1 and 100. You have 5 chances to guess the correct number." << endl;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 100);

    do {
        int max_attempts = getAttempts();
        if (max_attempts == 10) cout << "Great! You have selected the Easy difficulty level.\n ";
        else if (max_attempts == 5) cout << "Great! You have selected the Medium difficulty level. \n";
        else {
            cout << "Great!You have selected the Hard difficulty level.\n";
        }
        cout << "Let's start the game!\n";

        int random_number = distrib(gen);
        GuessNumber(random_number, max_attempts);
    } while (playAgain());
   
    cout << "thanks for playing! GoodBye!\n";
    

    return 0;
}

