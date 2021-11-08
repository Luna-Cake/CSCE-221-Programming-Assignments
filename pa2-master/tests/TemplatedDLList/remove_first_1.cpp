
TemplatedDLList<int> dll;
vector<int> vec = {2,3};
dll.insert_first(3);
dll.insert_first(2);
dll.insert_first(1);
int x = dll.remove_first();

ASSERT_EQ(x, 1);
list_equal(dll, vec);