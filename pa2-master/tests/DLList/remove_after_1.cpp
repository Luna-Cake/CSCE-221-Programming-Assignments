DLList dll;
vector<int> vec = {3,2,0,2,3};
dll.insert_first(3);
dll.insert_first(2);
dll.insert_first(1);
dll.insert_first(0);

auto ptr = dll.first_node();

dll.insert_first(2);
dll.insert_first(3);

int x = dll.remove_after(*ptr);

ASSERT_EQ(x, 1);
list_equal(dll, vec);