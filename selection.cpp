#include <iostream>
#include <fstream>
#define in "input.txt"
#define out "output.txt"
using namespace std;

struct Node {
    int data;
    Node* next;
};

void selectionSort(Node **head) {
    Node *nodeA = *head, *nodeB, *min;
    if (nodeA == NULL)
        return;
    while (nodeA->next != NULL) {
        min = nodeA;
        nodeB = nodeA->next;
        while (nodeB != NULL) {
            if (nodeB->data < min->data)
                min = nodeB;
            nodeB = nodeB->next;
        }
        if (min != nodeA) {
            int t = min->data;
            min->data = nodeA->data;
            nodeA->data = t;
        }
        nodeA = nodeA->next;
    }
}

void addNodeAtTail(Node** head, int data){
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        Node* tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = node;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    ifstream file(in);
    int n;
    file >> n;
    int a[n];
    for ( int i = 0; i< n ; i++){
        file >> a[i];
    }
    file.close();
    
    // tạo list node từ mảng trong file input.txt
    Node* head = NULL;
    for ( int i = 0; i < n; i++){
        addNodeAtTail(&head, a[i]);
    }
    cout << "Mang truoc khi sap xep: \n";
    printList(head);
    selectionSort(&head);
    cout << "Mang sau khi sap xep: \n";
    printList(head);
    
    ofstream fileOut(out);
    Node* tmp = head;
    while ( tmp != NULL ){
        fileOut << tmp->data << " ";
        tmp = tmp->next;
    }
    fileOut.close();
    return 0;
}