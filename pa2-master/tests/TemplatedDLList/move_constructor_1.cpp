#include <time.h>
#include <stdlib.h>

srand(time(NULL));

vector<int> vec;
for(int i=0; i<5; i++) {
  vec.push_back(rand()%100);
}

TemplatedDLList<int> dll;
load_list(dll, vec);
TemplatedDLList<int> dll2(move(dll));

list_equal(dll2, vec);
ASSERT_TRUE(dll.is_empty());