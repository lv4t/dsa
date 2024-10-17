#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <fstream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
void docFile(int arr[], int &n)
{
          ifstream inputFile;
          inputFile.open("input.txt");
          inputFile >> n;
          for (int i = 0; i < n; i++)
          {
                    inputFile >> arr[i];
          }
          inputFile.close();
}
void swapNodes(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}
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
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL, *current = head, *tail = pivot;

    while (current != pivot) {
        if (current->data < pivot->data) {
            if (*newHead == NULL) {
                *newHead = current;
            }
            prev = current;
            current = current->next;
        }
        else {
            if (prev) {
                prev->next = current->next;
            }
            Node* temp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = temp;
        }
    }

    if (*newHead == NULL) {
        *newHead = pivot;
    }
    *newEnd = tail;

    return pivot;
}
class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};
void ghiFile(int arr[], int n)
{
          ofstream outputFile;
          outputFile.open("output.txt");
          for (int i = 0; i < n; i++)
          {
                    outputFile << arr[i] << " ";
          }
          outputFile.close();
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
    Node* head = NULL;
    Node* curr = head;
    int arr[8];
    int n = sizeof(arr) / sizeof(arr[0]);
    docFile(arr, n);
    LinkedList list;
    for (int i = 0; i < n; i++) {
        list.addNode(arr[i]);
    }
    selectionSort(&head);
     int i = 0;
        while (curr != nullptr) {
            arr[i] = curr->data;
            i++;
            curr = curr->next;
    ghiFile(arr, n);
    cout << "Danh sach: ";
    list.printList();
    printList(head);
    return 0;
}
}
