#ifndef LIBRARY_H
#define LIBRARY_H

#include "Record.h"
#include "TemplatedDLList.h"
#include <cctype>
#include <vector>
#include <fstream>

class Library {
    private:
        std::vector<TemplatedDLList<Record>> book_db = std::vector<TemplatedDLList<Record>>(26);
    public:
        //Searches for a title in the database and returns vector of matching records
        std::vector<Record> search(const std::string title) const;

        //Imports records from a file.  Does not import duplicates.
        // Return the number of records added to the database
        int import_database(const std::string filename);

        //Exports the current database to a file
        //Return the number of records exported
        int export_database(const std::string filename) const;

        void print_database() const;

        //add record to database, avoid complete duplicates
        //  return true if unique
        bool add_record(const Record r);

        //Deletes a record from the database
        void remove_record(const Record r);
};

#endif