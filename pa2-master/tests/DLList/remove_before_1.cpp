DLList dll;
vector<int> vec = {3,2,1,2,3};
dll.insert_first(3);
dll.insert_first(2);
dll.insert_first(1);

auto ptr = dll.first_node();

dll.insert_first(0);
dll.insert_first(2);
dll.insert_first(3);

int x = dll.remove_before(*ptr);

ASSERT_EQ(x, 0);
list_equal(dll, vec);