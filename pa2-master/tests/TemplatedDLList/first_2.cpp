// First element inserted with insert_before
#include <stdlib.h>    
#include <time.h> 
srand (time(NULL));

int first = rand() % 99999;
int second = rand() % 99999;
TemplatedDLList<int> dll2;
dll2.insert_first(first);
dll2.insert_before(*dll2.first_node(),second);

ASSERT_EQ(dll2.first(), second);