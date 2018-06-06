/*
  CH08-320142
  a1_p6.cpp
  Steven Abreu
  s.abreu@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string name;
    int guess, randomNumber, tries;
    tries = 0;

    cin >> name;
    randomNumber = (rand()) % 100 + 1; //random number between 1 and 100

    do {
        cin >> guess;
        tries++;
        if (guess > randomNumber) {
            cout << "guess too high." << endl;
        } else if (guess < randomNumber) {
            cout << "guess too low." << endl;
        }
    } while (guess != randomNumber);

    cout << "After " << tries << " tries, you guessed correctly! Congratulations, " << name << "!" << endl;
    return 0;
}
