#include "Library.h"
#include <fstream>

//Searches for a title in the database and returns vector of matching records
std::vector<Record> Library::search(const std::string title) const {
    std::vector<Record> result;

    int first_char_hash = (int)title.at(0) - 65;
    TemplatedDLList<Record>::DLListNode* ptr = book_db[first_char_hash].first_node();

    while (ptr != book_db[first_char_hash].after_last_node()) {
        if (ptr->obj.get_title() == title)
            result.push_back(ptr->obj);
        ptr = ptr->next;
    }

    return result;
}

//Imports records from a file.  Does not import duplicates.
// Return the number of records added to the database
int Library::import_database(const std::string filename) {
    int num_books = 0;
    std::ifstream books (filename);

    Record rec;
    while (books >> rec) {
        if (add_record(rec)) 
            num_books++;
    }

    return num_books;
}

//Exports the current database to a file
//Return the number of records exported
int Library::export_database(const std::string filename) const {
    int num_books = 0;
    std::ofstream books (filename);

    for (int i = 0; i < 26; i++) {
        TemplatedDLList<Record>::DLListNode* ptr = book_db[i].first_node();
        while (ptr != book_db[i].after_last_node()) {
            books << ptr->obj;
            books << std::endl;
            num_books++;
            ptr = ptr->next;
        }
    }
    books << std::endl;
    return num_books;
}

void Library::print_database() const{ 
    for (int i = 0; i < 26; i++) {
        TemplatedDLList<Record>::DLListNode* ptr = book_db[i].first_node();
        while (ptr != book_db[i].after_last_node()) {
            std::cout << ptr->obj << std::endl;
            ptr = ptr->next;
        }
    }
}

//add record to database, avoid complete duplicates
//  return true if unique
bool Library::add_record(const Record r) {
    std::cout << r << std::endl;
    int first_char_hash = (int)r.get_title().at(0) - 65;
    TemplatedDLList<Record>::DLListNode* ptr = book_db[first_char_hash].first_node();

    if (book_db[first_char_hash].is_empty() || r < ptr->obj) {
        book_db[first_char_hash].insert_first(r);
        return true;
    }

    while (ptr != book_db[first_char_hash].after_last_node()) {
        if (r < ptr->obj) {
            book_db[first_char_hash].insert_before(*ptr, r);
            return true;
        } else if (r == ptr->obj) {
            return false;
        }
        ptr = ptr->next;
    }

    book_db[first_char_hash].insert_last(r);
    return true;
}

//Deletes a record from the database
void Library::remove_record(const Record r) {
    int first_char_hash = (int)r.get_title().at(0) - 65;   

    TemplatedDLList<Record>::DLListNode* ptr = book_db[first_char_hash].first_node();

    if (r == ptr->obj) {
        book_db[first_char_hash].remove_first();
        return;
    } else if (r == book_db[first_char_hash].last()) {
        book_db[first_char_hash].remove_last();
        return;
    }

    while (ptr != book_db[first_char_hash].after_last_node()) {
        if (ptr->next->obj == r) {
            book_db[first_char_hash].remove_after(*ptr);
            return;
        }
    }
}