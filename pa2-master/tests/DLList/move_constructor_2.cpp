 
DLList dll3;
DLList dll4(move(dll3));

check_consistency(dll3);
ASSERT_TRUE(dll3.is_empty());

std::cout << "DLL3 good to go.\n";

check_consistency(dll4);
ASSERT_TRUE(dll4.is_empty());