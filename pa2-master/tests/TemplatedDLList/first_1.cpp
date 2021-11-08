#include <stdlib.h>    
#include <time.h> 
#include <utility>      


/******************************
 * UNIT TESTS
 ******************************/
 
srand (time(NULL));
int rand1 = rand() % 100;
int rand2 = rand() % 100;
int rand3 = rand() % 100;
int rand4 = rand() % 100;
int rand5 = rand() % 100;
int rand6 = rand() % 100;
 // First element inserted with insert_first
TemplatedDLList<pair<int,int>> dll;
dll.insert_first(make_pair (rand1,rand2));
dll.insert_first(make_pair (rand3,rand4));
dll.insert_first(make_pair (rand5,rand6));

ASSERT_EQ(dll.first().first, rand5);
ASSERT_EQ(dll.first().second, rand6);