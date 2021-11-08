// First element inserted with insert_last
#include <stdlib.h>    
#include <time.h> 
srand (time(NULL));

char c = rand() % 256;

TemplatedDLList<char> dll3;
dll3.insert_last(c);

ASSERT_EQ(dll3.first(), c);