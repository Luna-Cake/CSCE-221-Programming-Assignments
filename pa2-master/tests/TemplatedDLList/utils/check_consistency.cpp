auto check_consistency = [](TemplatedDLList<int>& dll)
{
    int counter = 0;
    auto prev = dll.first_node()->prev;

    // checks that first item's 'prev' points to correct header
    if (dll.first_node()->prev->next != dll.first_node()) {
        cout << "ERROR: First node does not point to header node " << endl;
    }
    ASSERT_EQ(dll.first_node()->prev->next, dll.first_node());

    for (auto ptr = dll.first_node(); ptr != dll.after_last_node(); ptr = ptr->next, counter++, prev = prev->next) {
        // Check for null pointers
        if (ptr == nullptr) {
            cout << "ERROR: node points to null"  << endl;
        }
        ASSERT_NE(ptr, nullptr);
        
        // Check that the back pointer points to the previous node
        if (ptr->prev != prev) {
            cout << "ERROR: back pointers do not point to previous node" << endl;
        }
        ASSERT_EQ(ptr->prev, prev);

    }

    // checks that last item's 'next' pointer points to correct trailer
    if (dll.after_last_node()->prev->next != dll.after_last_node()) {
        cout << "ERROR: Last node does not point to trailer node" << endl;
    }
    ASSERT_EQ(dll.after_last_node()->prev->next, dll.after_last_node());
};