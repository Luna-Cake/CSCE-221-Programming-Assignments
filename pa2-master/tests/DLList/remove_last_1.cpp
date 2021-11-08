DLList dll;
vector<int> vec = {1,2};
dll.insert_first(3);
dll.insert_first(2);
dll.insert_first(1);
int x = dll.remove_last();

ASSERT_EQ(x, 3);
list_equal(dll, vec);