#include <iostream>
#include <fstream>
#define in "input.txt"
#define out "output.txt"
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};
//tạo node
Node* newnode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// thêm node
void push(Node** headRef, int data) {
    Node* newNode = newnode(data);
    newNode->next = (*headRef);
    if ((*headRef) != NULL) {
        (*headRef)->prev = newNode;
    }
    (*headRef) = newNode;
}
void printList(Node* head) { //in
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Hàm trộn hai danh sách liên kết kép đã được sắp xếp thành một danh s ách liên kết kép mới đã được sắp xếp
Node* mergeLists(Node* l1, Node* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1->data < l2->data) {
        l1->next = mergeLists(l1->next, l2);
        l1->next->prev = l1;
        l1->prev = NULL;
        return l1;
    }
    else {
        l2->next = mergeLists(l1, l2->next);
        l2->next->prev = l2;
        l2->prev = NULL;
        return l2;
    }
}

// Chia đôi danh sách liên kết kép ban đầu thành hai danh sách liên kết kép nhỏ hơn
void splitList(Node* head, Node** l1Ref, Node** l2Ref) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    (*l1Ref) = head;
    (*l2Ref) = slow->next;
    slow->next = NULL;
}
void mergeSort(Node** headRef) {
    Node* head = (*headRef);
    Node* l1 = NULL;
    Node* l2 = NULL;
    if (head == NULL || head->next == NULL) {
        return;
    }
    splitList(head, &l1, &l2);
    mergeSort(&l1);
    mergeSort(&l2);
    (*headRef) = mergeLists(l1, l2);
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
    mergeSort(&head);
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