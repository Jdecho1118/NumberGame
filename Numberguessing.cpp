#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // Include for numeric_limits

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a random number between 1 and 100. Try to guess it!" << endl;

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int attempts = 0;
    const int maxAttempts = 7; // Maximum number of attempts allowed

    // Provide a hint about the secret number being odd or even
    if (secretNumber % 2 == 0) {
        cout << "Hint: The secret number is even." << endl;
    } else {
        cout << "Hint: The secret number is odd." << endl;
    }

    while (attempts < maxAttempts) {
        cout << "Enter your guess (between 1 and 100): ";
        int guess;
        cin >> guess;

        if (cin.fail() || guess < 1 || guess > 100) {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a valid number between 1 and 100." << endl;
            continue;
        }

        attempts++;

        // Check if the guess is correct
        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts." << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! ";
        } else {
            cout << "Too high! ";
        }

        // Provide additional hints based on the difference between the guess and the secret number
        int difference = abs(secretNumber - guess);
        if (difference >= 10)
            cout << "You are very far from the secret number." << endl;
        else if (difference >= 5)
            cout << "You are getting closer to the secret number." << endl;
        else
            cout << "You are very close to the secret number." << endl;
    }

    if (attempts >= maxAttempts) {
        cout << "Sorry, you've run out of attempts. The correct number was " << secretNumber << "." << endl;
    }

    return 0;
}
