#include "Record.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>    
#include <time.h> 
#include <iostream>


using namespace std;

int main() {
    
    Record rec;
    vector<Record> vec;

    // Attempt to open the file, exit on error
    ifstream ifs("Book.txt");
    if (!ifs.is_open()) {
        cout << "Book.txt not found";
        return 1;
    }

    // Load the records from the file into the vector,
    while (ifs >> rec) {
        vec.push_back(rec);
    }

    // Print the records,
    for (auto x: vec) {
        cout << x.get_title() << endl;
        cout << x.get_author() << endl;
        cout << x.get_ISBN() << endl;
        cout << x.get_edition() << endl;
        cout << x.get_year() << endl;
    }

}