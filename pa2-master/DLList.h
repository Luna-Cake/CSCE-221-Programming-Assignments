// // header file for the DLList class

#ifndef DLLIST_H
#define DLLIST_H

// #include <iostream>
#include "TemplatedDLList.h"

using DLList = TemplatedDLList<int>;

// // doubly linked list class
// class DLList {
// public:
// // doubly linked list node
// struct DLListNode {
//   int obj;
//   DLListNode *prev, *next;
//   // constructor
//     DLListNode(int e=0, DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n){}
// };
// private:
//   DLListNode header, trailer;
// public:
//   DLList();
//   DLList(const DLList& dll); // copy constructor
//   DLList(DLList&& dll); // move constructor
//   ~DLList(); // destructor
//   DLList& operator=(const DLList& dll); // copy assignment operator
//   DLList& operator=(DLList&& dll); // move assignment operator

//   // return the pointer to the first node (header's next)
//   DLListNode *first_node() const;

//   // return the pointer to the trailer
//   const DLListNode *after_last_node() const;

//   // return if the list is empty
//   bool is_empty() const;
//   int first() const; // return the first object
//   int last() const; // return the last object
//   void insert_first(const int obj); // insert to the first node
//   int remove_first(); // remove the first node
//   void insert_last(const int obj); // insert to the last node
//   int remove_last(); // remove the last node
//   void insert_after(DLListNode &p, const int obj);
//   void insert_before(DLListNode &p, const int obj);
//   int remove_after(DLListNode &p);
//   int remove_before(DLListNode &p);
//   void make_empty(void);
// };

// // output operator
// std::ostream& operator<<(std::ostream& out, const DLList& dll);
// // {
// //   DLList::DLListNode* ptr = dll.first_node();

// //   while (ptr != dll.after_last_node()) {
// //     out << ptr->obj << ", ";
// //     ptr = ptr->next;
// //   }
// //   return out;
// // }

#endif
