 
#include <time.h>
#include <stdlib.h> 

srand (time(NULL));
DLList dll;
int size = 7;
vector<int> vec;
for(int i = 0; i < 7; ++i)
{
  vec.push_back(rand() % 100);
}

dll.insert_first(vec[6]);
dll.insert_first(vec[5]);
dll.insert_first(vec[4]);

auto ptr = dll.first_node();

dll.insert_first(vec[2]);
dll.insert_first(vec[1]);
dll.insert_first(vec[0]);

dll.insert_before(*ptr, vec[3]);

list_equal(dll, vec);