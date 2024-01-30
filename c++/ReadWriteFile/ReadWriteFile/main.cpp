//
//  main.cpp
//  ReadWriteFile
//
//  Created by Dario Caric on 29.01.2024..
//

#include <iostream>
#include <string>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;


void getPath() {
    try {
        // Get the current working directory
        filesystem::path currentPath = filesystem::current_path();

        // Output the current path
        cout << "Current Path: " << currentPath << endl;
    } catch (const filesystem::filesystem_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

void writeToFile(string sentence, string filePath) {

    // Create an ofstream object for writing
    ofstream fileStream(filePath);

    // Check if the file is open (i.e., successfully created or existing and writable)
    if (fileStream.is_open()) {
        // Write some text to the file
        fileStream << sentence << endl;

        // Close the file stream
        fileStream.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

void readFromFile(string filePath) {

    // Create an ifstream object for reading
    ifstream fileStream(filePath);

    // Check if the file is open (i.e., successfully opened for reading)
    if (fileStream.is_open()) {
        string line;

        // Read the file line by line
        while (getline(fileStream, line)) {
            // Output the line to standard output
            cout << line << endl;
        }

        // Close the file stream
        fileStream.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
    }
}


int main(int argc, const char * argv[]) {
    
    getPath();
    
    writeToFile("Hi Dario !", "myfile.txt");
    readFromFile("myfile.txt");
    
    return 0;
}
