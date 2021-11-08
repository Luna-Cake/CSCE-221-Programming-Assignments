#include <time.h>
#include <stdlib.h> 


/* test with random input */
srand (time(NULL));
int val = rand() % 999999;


TemplatedDLList<int> dll;
dll.insert_first(val);
ASSERT_TRUE(dll.first_node()->obj == val);