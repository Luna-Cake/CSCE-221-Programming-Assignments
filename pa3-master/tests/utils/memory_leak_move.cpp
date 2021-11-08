
#include <iostream>
#include <fstream>
#include "BSTree.h"

using namespace std;

BSTree read_file(string file_name)
{
    /* open the file and use the input operator (operator>>)
    to construct a new tree */
      
    BSTree new_tree;
    ifstream infile(file_name); 
    infile >> new_tree;
    return new_tree;
}


int main()
{
    for(int i = 1; i <= 12; i++) {
        string dir= "data-files/"+std::to_string(i);
        BSTree empty;
        BSTree l = read_file(dir+"l");
        //cout << "average search time linear " << i << " " << l.get_average_search_time() << endl;
        BSTree p = read_file(dir+"p");
        //cout << "average search time perfect "<< i << " " << p.get_average_search_time() << endl;
        BSTree r = read_file(dir+"r");
        //cout << "average search time random "<< i << " " << r.get_average_search_time() << endl;

        BSTree ll(move(l)),pp(move(p)),rr(move(r)), ee(move(empty));
        
        ee.insert(-1);
        rr.insert(-1);
        pp.insert(-1);
        ll.insert(-1);
        l.insert(-1);
        empty.insert(-1);
        r.insert(-1);
        p.insert(-1);
    }
}

