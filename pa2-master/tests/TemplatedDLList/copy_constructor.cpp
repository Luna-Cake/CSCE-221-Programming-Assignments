#include <time.h>
#include <stdlib.h> 
#include <string>


TemplatedDLList<string> list1;

/* test with random size */
srand (time(NULL));
int size = rand() % 100;
for (int i=0; i <= size; i++) {
    list1.insert_first(to_string(rand() % 1000 + 1));
}

TemplatedDLList<string> list2(list1);

/* function to test equality of original and constructed lists */

  TemplatedDLList<string>::DLListNode *dummy_node1 = list1.first_node();
  TemplatedDLList<string>::DLListNode *dummy_node2 = list2.first_node();
  
  while(dummy_node1 != list1.after_last_node())
  {
    ASSERT_NE(dummy_node2, list2.after_last_node()); //lengths should be equal
    ASSERT_EQ(dummy_node1->obj, dummy_node2->obj); //objs should be equal
    ASSERT_NE(dummy_node1, dummy_node2); //should be deep copy
    dummy_node1 = dummy_node1 ->next;
    dummy_node2 = dummy_node2 ->next;
  }
  
  ASSERT_EQ(dummy_node2, list2.after_last_node()); //both lists should be iterated
  