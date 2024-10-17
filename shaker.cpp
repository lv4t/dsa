#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

//  tạo node
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;
    return node;
}
void push(Node **headRef, int data) //Thêm 
{
    Node *node = newNode(data);
    node->next = *headRef;
    if (*headRef != nullptr)
    {
        (*headRef)->prev = node;
    }
    *headRef = node;
}
int count(Node *head) //Đếm
{
    int count = 0;
    Node *current = head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// Hàm trả về node ở vị trí index trong danh sách liên kết kép
Node *getNode(Node *head, int index)
{
    Node *current = head;
    int count = 0;
    while (current != nullptr)
    {
        if (count == index)
        {
            return current;
        }
        count++;
        current = current->next;
    }
    return nullptr;
}

// Hàm hoán đổi giá trị của hai node
void swap(Node *node1, Node *node2)
{
    int temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}
void shakerSort(Node **headRef)
{
    int left = 0;
    int right = count(*headRef) - 1;
    bool swapped = true;

    while (swapped)
    {
        swapped = false;
        Node *current = getNode(*headRef, left);
        for (int i = left; i < right; i++)
        {
            if (current->data > current->next->data)
            {
                swap(current, current->next);
                swapped = true;
            }
            current = current->next;
        }
        right--;

        if (!swapped)
        {
            break;
        }

        current = getNode(*headRef, right);
        for (int i = right; i > left; i--)
        {
            if (current->data < current->prev->data)
            {
                swap(current, current->prev);
                swapped = true;
            }
            current = current->prev;
        }
        left++;
    }
}
void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main()
{
    Node *head = nullptr;
    push(&head, 9);
    push(&head, 13);
    push(&head, 21);
    push(&head, 10);
    push(&head, 3);
    push(&head, 8);
    push(&head, 5);

    cout << "Danh sach truoc khi sap xep: ";
    printList(head);

    shakerSort(&head);

    cout << "Danh sach sau khi sap xep : ";
    printList(head);

    return 0;
}
