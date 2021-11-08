TemplatedDLList<int> dll;
#include <stdlib.h>    
#include <time.h> 
srand (time(NULL));
int size = 7;
vector<int> vec;
for(int i = 0; i < size; ++i)
{
  vec.push_back(rand() % 100);
}

dll.insert_first(vec[6]);
dll.insert_first(vec[5]);
dll.insert_first(vec[3]);

auto ptr = dll.first_node();

dll.insert_first(vec[2]);
dll.insert_first(vec[1]);
dll.insert_first(vec[0]);

dll.insert_after(*ptr, vec[4]);

list_equal(dll, vec);