// test of the DLList class

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "DLList.h"

using namespace std;

void CheckListConsistency(const DLList& dll, const int line_no = 0){
  auto t = dll.first_node();

  while(t != dll.after_last_node()){
    assert(t->next != nullptr);
    assert(t->next->prev = t);
    t = t->next;
  }

  if(line_no != 0){
    std::cout << "Consistency check passed line " << line_no << std::endl;
  }
}

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList dll;
  cout << "list: " << dll << endl << endl;
  
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_last(i);
  }
  CheckListConsistency(dll, __LINE__);
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_first(i);
  }
  CheckListConsistency(dll, __LINE__);
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList dll2(dll);
  CheckListConsistency(dll, __LINE__);
  CheckListConsistency(dll2, __LINE__);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList dll3;
  dll3 = dll;
  CheckListConsistency(dll, __LINE__);
  CheckListConsistency(dll3, __LINE__);
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_last();
  }
  CheckListConsistency(dll, __LINE__);
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_first();
  }
  CheckListConsistency(dll, __LINE__);
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  CheckListConsistency(dll2, __LINE__);
  cout << "list2: " << dll2 << endl;
  CheckListConsistency(dll3, __LINE__);
  cout << "list3: " << dll3 << endl << endl;

  // more testing...
  // add tests for insert_after, insert_before
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_last(i);
  }
  CheckListConsistency(dll, __LINE__);
  cout << "list: " << dll << endl << endl;

  // Get reference for testing
  DLList::DLListNode *curr = dll.first_node();
  while (curr->obj != 50) {
    curr = curr->next;
  }
  CheckListConsistency(dll, __LINE__);
  DLList::DLListNode& ref = *curr;

  // Insert before
  cout << "Insert 41-49 before 50" << endl;
  for (int i = 41; i < 50; ++i) {
    dll.insert_before(ref, i);
  }
  CheckListConsistency(dll, __LINE__);
  cout << dll << endl << endl;

  // Insert after
  cout << "Insert 59-51 after 50" << endl;
  for (int i = 59; i > 50; --i) {
    dll.insert_after(ref, i);
  }
  cout << dll << endl << endl;
  CheckListConsistency(dll, __LINE__);

  // add tests for remove_after, remove_before
  
  // Remove after
  cout << "Remove 9 after 50" << endl;
  for (int i = 0; i < 9; i++) {
    dll.remove_after(ref);
  }
  CheckListConsistency(dll, __LINE__);
  cout << dll << endl << endl;

  // Remove before
  cout << "Remove 9 before 50" << endl;
  for (int i = 0; i < 9; i++) {
    dll.remove_before(ref);
  }
  CheckListConsistency(dll, __LINE__);
  cout << dll << endl << endl;

  // Test move constuctor / assignment
  DLList origDll;
  for (int i=10; i <= 100; i+=10) {
    origDll.insert_last(i);
  }
  CheckListConsistency(origDll, __LINE__);
  
  DLList moveDll(move(origDll));
  CheckListConsistency(moveDll, __LINE__);
  CheckListConsistency(origDll, __LINE__);
  dll2 = move(moveDll);
  CheckListConsistency(moveDll, __LINE__);
  CheckListConsistency(origDll, __LINE__);
  CheckListConsistency(dll2, __LINE__);

  return 0;
}
