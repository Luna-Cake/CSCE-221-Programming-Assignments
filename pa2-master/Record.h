#ifndef Record_H
#define Record_H

#include <iostream>
#include <string>

class Record {
private:
    //member variables
    std::string title;
    std::string author;
    std::string ISBN;
    std::string year;
    std::string edition;
public:
    //accessor/mutator functions
    // std::string get_title(void) const;
    // ... for all 5 fields
    std::string get_title() const;
    std::string get_author() const;
    std::string get_ISBN() const;
    std::string get_year() const;
    std::string get_edition() const;

    void set_title(std::string new_title);
    void set_author(std::string new_author);
    void set_ISBN(std::string new_ISBN);
    void set_year(std::string new_year);
    void set_edition(std::string new_edition);

    friend std::istream& operator>>(std::istream& is, Record& rec);
};

std::istream& operator>>(std::istream& is, Record& rec);
std::ostream& operator<<(std::ostream& os, const Record& rec);
bool operator==(const Record& r1, const Record& r2);
bool operator<(const Record& lhs, const Record& rhs);

#endif