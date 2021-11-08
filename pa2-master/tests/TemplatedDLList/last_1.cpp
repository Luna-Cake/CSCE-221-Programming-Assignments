// Last element inserted with insert_first
#include <stdlib.h>    
#include <time.h> 
srand (time(NULL));

TemplatedDLList<int> dll;
int rand_last = rand() % 9999;
dll.insert_first(rand_last);
dll.insert_first(rand() % 9999);
dll.insert_first(rand() % 9999);

ASSERT_EQ(dll.last(), rand_last);