#include <stdlib.h>    
#include <time.h> 
srand (time(NULL));

int rand1 = rand() % 9999;
int rand2 = rand() % 9999;
int rand3 = rand() % 9999;
int rand4 = rand() % 9999;

 
vector<int> vec = {rand1,rand2,rand3,rand4};
TemplatedDLList<int> dll;
dll.insert_last(rand1);
dll.insert_last(rand2);
dll.insert_last(rand3);
dll.insert_last(rand4);

list_equal(dll, vec);