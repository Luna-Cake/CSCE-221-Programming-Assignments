
vector<int> vec = {1,2,3,4};
DLList dll;
dll.insert_last(1);
dll.insert_last(2);
dll.insert_last(3);
dll.insert_last(4);

list_equal(dll, vec);