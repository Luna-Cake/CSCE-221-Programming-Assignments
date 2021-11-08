auto list_equal = [check_consistency](TemplatedDLList<int>& dll, vector<int>& vec)
{
    check_consistency(dll);

    int i = 0;
    for (auto ptr = dll.first_node(); ptr != dll.after_last_node(); ptr = ptr->next, i++) {
        // The DLList contains more items than the vector
        // or the list has an incorrect item
        if ((vec.size() <= i) || ptr->obj != vec[i]) {
            cout << "ERROR: Item at position " << i << " does not match" << endl;
        }
        ASSERT_GT(vec.size(), i);
        ASSERT_EQ(ptr->obj, vec[i]);
    }

    // DLList is too short
    if (i < vec.size()) {
        cout << "ERROR: Dimensions of list do not match" << endl;
    }
    ASSERT_GE(i, vec.size());
};