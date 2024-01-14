//
//  main.cpp
//  Moleculas
//
//  Created by Dario Caric on 14.01.2024..
//

#include <iostream>
#include <string>

using namespace std;

string findOneMolecula(string input) {
    string result = "";
    if (input == "Au") result = "Gold";
    else if (input == "Ag") result = "Silver";
    else if (input == "Si") result = "Silicon";
    else if (input == "Cl") result = "Clhorine";
    else if (input == "Se") result = "Selenium";
    else if (input == "Ch") result = "Chlor";
    return result;
}

string findCombination(string input) {
    // help variables
    string twoChars = "";
    string result = "";
    int i = 0;
    
    // first 2 chars
    twoChars = string() + input[i] + input[i+1]; // combine 2 chars into string
    result = result + findOneMolecula(twoChars);
    i += 2; // move 2 places since 2 first chars are checked
    
    while (i < input.length()) {
        if (input[i] < '9') i ++; // if char is number <9 skip it
        else {
            // char is not number, take 2 next char and get molecula
            twoChars = string() + input[i] + input[i+1];
            i += 2;
            result = result + " "; // add first space
            result = result + findOneMolecula(twoChars); // add new moleccula
        }
    }
    
    return result;
}

int main() {
    string input = "Au3Cl2Ag";
    string result = findCombination(input);
    cout << result << endl;
    return 0;
}
