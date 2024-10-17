void insertionSort(Node** headRef) {
    Node* head = (*headRef);
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node* sorted = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            if (sorted != NULL) {
                sorted->prev = current;
            }
            sorted = current;
            sorted->prev = NULL;
        }
        else {
            Node* temp = sorted;
            while (temp != NULL && temp->data < current->data) {
                temp = temp->next;
            }
            current->next = temp;
            current->prev = temp->prev;
            if (temp->prev != NULL) {
                temp->prev->next = current;
            }
            temp->prev = current;
        }
        current = next;
    }
    (*headRef) = sorted;
}
void binaryInsertionSort(Node** headRef) {
    Node* head = (*headRef);
    if (head == NULL || head->next == NULL) {
        return;
    }
    Node* sorted = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            if (sorted != NULL) {
                sorted->prev = current;
            }
            sorted = current;
            sorted->prev = NULL;
        }
        else {
            Node* position = binarySearch(sorted, current->data);
            current->next = position->next;
            current->prev = position;
            if (position->next != NULL) {
                position->next->prev = current;
            }
            position->next = current;
        }
        current = next;
    }
    (*headRef) = sorted;
}