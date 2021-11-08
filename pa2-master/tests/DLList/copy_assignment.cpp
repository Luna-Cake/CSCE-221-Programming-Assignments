
#include <time.h>
#include <stdlib.h> 

/* test with random size */
srand (time(NULL));
int size = rand() % 100;
vector<int> vec;
for(int i = 0; i < size; ++i)
{
  vec.push_back(rand() % 100);
}


DLList dll;
load_list(dll, vec);
DLList dll2;

for (int i = 0; i < 8; i++) {
   dll2.insert_first(-1);
}

dll2 = dll;

list_equal(dll2, vec);
ASSERT_NE(dll2.first_node(), dll.first_node());

dll2.insert_first(0);
list_equal(dll, vec);