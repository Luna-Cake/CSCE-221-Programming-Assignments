
vector<int> vec = {1,2,3,4};
TemplatedDLList<int> dll;
dll.insert_first(4);
dll.insert_first(3);
dll.insert_first(2);
dll.insert_first(1);

list_equal(dll, vec);