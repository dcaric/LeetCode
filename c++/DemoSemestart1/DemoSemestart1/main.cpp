//
//  main.cpp
//  DemoSemestart1
//
//  Created by Dario Caric on 03.02.2024..
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <filesystem>

using namespace std;

// *********************************************************
// STRUCTURES
// *********************************************************
struct Book {
    string name;
    vector<string> chapter;
};

struct Student {
    string name;
    vector<Book> books;
};
// *********************************************************


// *********************************************************
// FUNCTIONS DECLARATION
// *********************************************************
void getPath(); // OKO OVOG SE NE MISLI PISE DOLE OBJASNJENJE
void insertStudent(vector<Student> &students);
void printStudents(vector<Student> &students);
void printOneStudent(vector<Student> &students);
void saveStudentsToFile(vector<Student> &students, string fileName);
void copyStudentsFromFile(vector<Student> &students, string fileName);
// *********************************************************



int main() {
    
    getPath();
    
    // MAIN VARIABLES ***********
    vector<Student> students;
    const string fileName = "students.txt";
    int choice;
    // **************************
    
    
    
    do {
        cout << "1" << "\t Insert student" << endl;
        cout << "2" << "\t Print all students" << endl;
        cout << "3" << "\t Print one student by name" << endl;
        cout << "4" << "\t Copy all students into file" << endl;
        cout << "5" << "\t Read all students from file" << endl;
        cout << "0" << "\t EXIT" << endl;
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                insertStudent(students);
                break;
            case 2:
                printStudents(students);
                break;
            case 3:
                printOneStudent(students);
                break;
            case 4:
                saveStudentsToFile(students, fileName);
                break;
            case 5:
                copyStudentsFromFile(students, fileName);
                break;
            default:
                break;
        }
        
    } while (choice != 0);


    return 0;
}

// *********************************************************
// FUNCTION DEFINITION
// *********************************************************
void insertStudent(vector<Student> &students) {
    
    Student oneStudent;
    
    cout << "Insert:" << endl;
    cout << "Name:";
    getline(cin, oneStudent.name);
    cout << "How many books student have?:";
    int bookNum;
    cin >> bookNum;
    cin.ignore();
    // FOR loop za knjige od ovog studenta, i- JE ZA KNJIGE
    for (int i=0; i<bookNum; i++) {
        // temp Book var za pojedinacnu knjigu
        Book book;
        cout << "Ime knjige:";
        getline(cin, book.name);
        cout << "Koliko poglavlja ima knjiga? ";
        int chapters;
        cin >> chapters;
        cin.ignore();
        // j- JE ZA POGLAVLJA
        for (int j=0; j<chapters; j++) {
            // temp var za chaptere
            string oneChapter;
            cout << "Chapter:";
            getline(cin, oneChapter);
            book.chapter.push_back(oneChapter);
        }
        // kad smo upisali sva poglavlja i ime knjige sa je dodajempo u listu <books>
        oneStudent.books.push_back(book);
        // sad oneStudent ima kreiranu listu books a svaka ta book ima ime i listu chaptera
    }
    // sad jos ostaje da tako popunjenog oneStudent pushamo u students listu
    students.push_back(oneStudent);
}


void printStudents(vector<Student> &students) {
    
    // FOR ZA LISTU STUDENATA
    for (int i=0; i<students.size(); i++) {
        cout << "STUDENT: ";
        cout << students[i].name << endl;
        
        // FOR ZA LISTU KNJIGA KOJE IMA 1 STUDENT
        cout << "KNJIGE KOJE IMA:" << endl;
        for (int j=0; j<students[i].books.size(); j++) {
            cout << students[i].books[j].name << endl;
            
            // FOR LOOP JOS ZA CHAPTERE TE KNJIGE:
            cout << "CHAPTERS OF THE BOOK:" << endl;
            for (int k=0; k<students[i].books[j].chapter.size(); k++) {
                cout << students[i].books[j].chapter[k] << endl;
            }
            cout << endl; // space izmedju knjiga
        }
        cout << endl << endl; // 2x space izmedju studenata
    }
}


void printOneStudent(vector<Student> &students) {
    
    cout << "Kako se zove student? ";
    string studentname;
    getline(cin, studentname);
    
    // FOR ZA LISTU STUDENATA
    for (int i=0; i<students.size(); i++) {
        if (students[i].name == studentname) {
            
            // FOR ZA LISTU KNJIGA KOJE IMA 1 STUDENT
            cout << "KNJIGE KOJE IMA:" << endl;
            for (int j=0; j<students[i].books.size(); j++) {
                cout << students[i].books[j].name;
                
                // FOR LOOP JOS ZA CHAPTERE TE KNJIGE:
                cout << "CHAPTERS OF THE BOOK:" << endl;
                for (int k=0; k<students[i].books[j].chapter.size(); k++) {
                    cout << students[i].books[j].chapter[k] << endl;
                }
                cout << endl; // space izmedju knjiga
            }
        
            break; // IZLAZ IZ FOR-i LOOPA da dalje ne vrti bez veze kad je nasao
        }
    }
}


void saveStudentsToFile(vector<Student> &students, string filename){
    
    ofstream file(filename);
    
    // FOR ZA LISTU STUDENATA
    for (int i=0; i<students.size(); i++) {
        file << "STUDENT" << endl;
        file << students[i].name << endl;
        
        // FOR ZA LISTU KNJIGA KOJE IMA 1 STUDENT
        for (int j=0; j<students[i].books.size(); j++) {
            file << "BOOK" << endl;
            file << students[i].books[j].name << endl;
            
            // FOR LOOP JOS ZA CHAPTERE TE KNJIGE:
            file << "CHAPTERS" << endl;
            for (int k=0; k<students[i].books[j].chapter.size(); k++) {
                file << students[i].books[j].chapter[k] << endl;
            }
        }
    }
    file.close();
}


void copyStudentsFromFile(vector<Student> &students, string fileName){
    // Ovdje treba citati liniju po liniju , jedna linija izgleda
    // ivan cosmos chapter1 chapter 2 pariz chapter1 chapter2
    // malo je sad teze znati di pocinje knjiga pa da ne kompliciram
    // samo cemo ispisati liniju po liniju
    
    ifstream file(fileName);
    
    string line;
    if (file) {
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        cout << "ERROR: File not exist" << endl;
    }
    file.close();
}



// *********************************************************



// OVO NISTA OVO JE MENI DA ZNAM DI JE PATH OF OVOG PROJEKTA JER XCODE
// TO STAVI U NPR OVO DOLE STO MI JE TESKO PAMTITI A HOCU DA ODEM DA VIDIM .TXT FAJLU
// Current Path: "/Users/dariocaric/Library/Developer/Xcode/DerivedData/DemoSemestart1-gmnzssoqkuzgsvbrbdlrmgytvbpi/Build/Products/Debug"
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
