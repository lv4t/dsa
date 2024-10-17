#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Hàm tạo một Node mới
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

// Hàm lấy phần tử cuối cùng của danh sách liên kết
Node *getLast(Node *head)
{
    while (head && head->next)
    {
        head = head->next;
    }
    return head;
}

// Hàm chia danh sách liên kết
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *prev = NULL;
    Node *cur = head;
    Node *tail = pivot;

    // Lặp qua danh sách liên kết và đưa các giá trị nhỏ hơn hoặc bằng pivot vào phần bên trái, các giá trị lớn hơn pivot vào phần bên phải
    while (cur != pivot)
    {
        if (cur->data <= pivot->data)
        {
            if (*newHead == NULL)
            {
                *newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
            {
                prev->next = cur->next;
            }
            Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if (*newHead == NULL)
    {
        *newHead = pivot;
    }
    *newEnd = tail;

    // Trả về pivot
    return pivot;
}

// Hàm sắp xếp danh sách liên kết bằng thuật toán Quick Sort không đệ quy
Node *quickSort(Node *head, Node *end)
{
    if (!head || head == end)
    {
        return head;
    }
    Node *newHead = NULL;
    Node *newEnd = NULL;
    Node *pivot = partition(head, end, &newHead, &newEnd);
    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->next != pivot)
        {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        newHead = quickSort(newHead, tmp);
        tmp = getLast(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSort(pivot->next, newEnd);

    return newHead;
}

// Hàm thêm một phần tử vào đầu danh sách liên kết
void push(Node **headRef, int data)
{
    Node *node = newNode(data);
    node->next = *headRef;
    *headRef = node;
}

// Hàm in danh sách liên kết
void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    push(&head, 1);
    push(&head, 12);
    push(&head, 10);
    push(&head, 21);
    push(&head, 7);
    push(&head, 18);
    push(&head, 9);
    push(&head, 6);

    cout << "Danh sach truoc khi sap xep: ";
    printList(head);

    head = quickSort(head, getLast(head));

    cout << "Danh sach sau khi sap xep : ";
    printList(head);

    return 0;
}
