//implementation of record class
#include "Record.h"

std::string Record::get_title() const { return title; }
std::string Record::get_author() const { return author; }
std::string Record::get_ISBN() const { return ISBN; }
std::string Record::get_year() const { return year; }
std::string Record::get_edition() const { return edition; }

void Record::set_title(std::string new_title) { title = new_title; }
void Record::set_author(std::string new_author) { author = new_author; }
void Record::set_ISBN(std::string new_ISBN) { ISBN = new_ISBN; }
void Record::set_year(std::string new_year) { year = new_year; }
void Record::set_edition(std::string new_edition) {edition = new_edition; }

// Stream operators
std::istream& operator>>(std::istream& is, Record& rec) {
    std::string temp;
    while (std::getline(is, temp)) {
        if (temp.length() != 0)
            break;
    }
    // std::getline(is, rec.title);

    rec.set_title(temp);
    std::getline(is, rec.author);
    std::getline(is, rec.ISBN);
    std::getline(is, rec.year);
    std::getline(is, rec.edition);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Record& rec) {
    os << rec.get_title() << std::endl;
    os << rec.get_author() << std::endl;
    os << rec.get_ISBN() << std::endl;
    os << rec.get_year() << std::endl;
    os << rec.get_edition() << std::endl;

    return os;
}

// Comparison operators
bool operator==(const Record& r1, const Record& r2) {
    return ((r1.get_title() == r2.get_title()) &&
            (r1.get_author() == r2.get_author()) && 
            (r1.get_ISBN() == r2.get_ISBN()));
}

bool operator<(const Record& lhs, const Record& rhs) {
    if (lhs.get_title() < rhs.get_title())
        return true;
    else if (lhs.get_title() > rhs.get_title())
        return false;
    
    if (lhs.get_author() < rhs.get_author())
        return true;
    else if (lhs.get_author() > rhs.get_author())
        return false;

    if (lhs.get_ISBN() < rhs.get_ISBN())
        return true;
    else if (lhs.get_ISBN() > rhs.get_ISBN())
        return false;

    if (lhs.get_year() < rhs.get_year())
        return true;
    else if (lhs.get_year() > rhs.get_year())
        return false;

    if (lhs.get_edition() < rhs.get_edition())
        return true;
    else if (lhs.get_edition() > rhs.get_edition())
        return false;
    
    return false;
}