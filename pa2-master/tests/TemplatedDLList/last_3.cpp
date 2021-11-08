// Last element inserted with insert_last
TemplatedDLList<int> dll3;
dll3.insert_last(3);

ASSERT_EQ(dll3.last(), 3);