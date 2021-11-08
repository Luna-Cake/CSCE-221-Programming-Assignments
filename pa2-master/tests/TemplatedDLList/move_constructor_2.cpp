 
TemplatedDLList<int> dll3;
TemplatedDLList<int> dll4(move(dll3));

check_consistency(dll3);
ASSERT_TRUE(dll3.is_empty());
check_consistency(dll4);
ASSERT_TRUE(dll4.is_empty());