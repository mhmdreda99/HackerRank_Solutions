void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* current = head;
    while (current != nullptr) {
        cout << current->data << endl;
        current = current->next;
    }
}