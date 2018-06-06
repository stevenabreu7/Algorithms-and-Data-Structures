/*
  CH08-320142
  a2_p5.cpp
  Steven Abreu
  s.abreu@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>

using namespace std;

bool isPalindrome(string s) {
    string rev = "";
    int i;
    for (i = (int)s.length()-1; i >= 0; i--) {
        rev += s[i];
    }
    return (rev == s);
}

int main() {
    string input;
    while (true) {
        cin >> input;
        if (input == "stop") {
            break;
        }
        if (isPalindrome(input)) {
            cout << "This is a palindrome!" << endl;
        } else {
            cout << "This is not a palindrome..." << endl;
        }
    }
    return 0;
}
