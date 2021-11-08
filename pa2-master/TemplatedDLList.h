// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>

// doubly linked list class
template <typename T>
class TemplatedDLList {
public:
// doubly linked list node
  struct DLListNode {
    T obj;
    DLListNode *prev, *next;
    // constructor
    DLListNode(T e=T(), DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n) {}
  };
private:
  DLListNode header, trailer;
public:
  // default constructor 
  TemplatedDLList(void) {
    header.next = &trailer;
    trailer.prev = &header;
  }
  
  // copy constructor
  TemplatedDLList(const TemplatedDLList<T>& dll) {
    header = DLListNode();
    trailer = DLListNode();
    if (this != &dll) {
      header.next = &trailer;
      trailer.prev = &header;

      DLListNode* curr = dll.header.next;

      while (curr != &dll.trailer) {
          insert_last(curr->obj);
          curr = curr->next;
      }
    }
  } 

  // move constructor
  TemplatedDLList(TemplatedDLList<T>&& dll) {
    if (dll.is_empty()) {
      header.next = &trailer;
      trailer.prev = &header;
      return;
    }

    header.next = dll.header.next;
    dll.header.next->prev = &header;

    trailer.prev = dll.trailer.prev;
    dll.trailer.prev->next = &trailer;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
  } 

  // destructor
  ~TemplatedDLList() {
    make_empty();
    header.next = &trailer;
    trailer.prev = &header;
  }

  // copy assignment operator
  TemplatedDLList<T>& operator=(const TemplatedDLList<T>& dll) {
    if (this != &dll) {
      make_empty();
      header.next = &trailer;
      trailer.prev = &header;

    DLListNode* curr = dll.header.next;

      while (curr != &dll.trailer) {
          insert_last(curr->obj);
          curr = curr->next;
      }
    }
  }

  TemplatedDLList<T>& operator=(TemplatedDLList<T>&& dll) {
    make_empty();
    header.next = &trailer;
    trailer.prev = &header;

    if (dll.is_empty())
      return *this;

    header.next = dll.header.next;
    dll.header.next->prev = &header;

    trailer.prev = dll.trailer.prev;
    dll.trailer.prev->next = &trailer;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;

    return *this;
  } // move assignment operator

  // return the pointer to the first node
  DLListNode *first_node(void) const {
    return header.next;
  }

  // return the pointer to the trailer
  const DLListNode *after_last_node(void) const {
    return &trailer;
  }

  // return true if the list is empty
  bool is_empty(void) const {
    return (header.next == &trailer && trailer.prev == &header);
  }
// return the first object
  T first(void) const {
    if (is_empty())
      throw std::runtime_error("Access to empty list.");
    else
      return header.next->obj;
  }
   // return the last object
  T last(void) const {
    if (is_empty())
      throw std::runtime_error("Access to empty list.");
    else
      return trailer.prev->obj  ;
  }
  // insert to the first node
  void insert_first(const T obj) {
    DLListNode* to_insert = new DLListNode(obj);

    to_insert->prev = &header;
    to_insert->next = header.next;
    header.next->prev = to_insert;
    header.next = to_insert;
  }
  // remove the first node
  T remove_first() {
    if (is_empty())
      throw std::runtime_error("Empty list.");
    
    DLListNode* temp = header.next;
    T to_return = temp->obj;

    header.next = header.next->next;
    header.next->prev = &header;
    delete temp;

    return to_return;
  }
  // insert to the last node
  void insert_last(const T obj) {
      DLListNode* to_insert = new DLListNode(obj);

      to_insert->prev = trailer.prev;
      to_insert->next = &trailer;
      trailer.prev->next = to_insert;
      trailer.prev = to_insert;
  }
  // remove last node
  T remove_last() {
    if (is_empty())
        throw std::runtime_error("Empty list.");

    DLListNode* prev = trailer.prev;
    T val = prev->obj;
    
    trailer.prev = trailer.prev->prev;
    trailer.prev->next = &trailer;
    delete prev;

    return val;
  }


  void insert_after(DLListNode &p, const T obj) {
    DLListNode* curr = new DLListNode(obj);

    curr->next = p.next;
    curr->prev = &p;
    p.next->prev = curr;
    p.next = curr;
  }
  void insert_before(DLListNode &p, const T obj) {
    DLListNode* curr = new DLListNode(obj);

    curr->next = &p;
    curr->prev = p.prev;

    p.prev->next = curr;
    p.prev = curr;
  }
  T remove_after(DLListNode &p) {
    if (is_empty() || p.next == &trailer)
      throw std::runtime_error("Empty list.");
    
    DLListNode* temp = p.next;
    T to_return = temp->obj;

    p.next = p.next->next;
    p.next->prev = &p;

    delete temp;

    return to_return;
  }
  T remove_before(DLListNode &p) {
    if (is_empty() || p.prev == &header)
      throw std::runtime_error("Empty list.");
    
    DLListNode* temp = p.prev;
    T to_return = temp->obj;

    p.prev = p.prev->prev;
    p.prev->next = &p;

    delete temp;

    return to_return;
  }
  void make_empty(void) {
    DLListNode* ptr = header.next;
    while (!(ptr == &trailer)) {
      DLListNode* temp = ptr;
      ptr = ptr->next;
      delete temp;
    }
    header.next = &trailer;
    trailer.prev = &header;
  }
};

// output operator
template <typename T>
std::ostream& operator<<(std::ostream& out, const TemplatedDLList<T>& dll) {
  auto ptr = dll.first_node();

  while (ptr != dll.after_last_node()) {
    out << ptr->obj << ", ";
    ptr = ptr->next;
  }
  return out;
}

#endif
