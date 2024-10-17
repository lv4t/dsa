#include <iostream>

using namespace std;

// Định nghĩa cấu trúc nút trong cây
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Tạo một nút mới trong cây
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Thêm một nút vào cây
Node* insert(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Tìm kiếm một phần tử trong cây
bool search(Node* root, int value) {
    if (root == NULL) {
        return false;
    } else if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// In ra các nút trong cây theo thứ tự pre-order
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// In ra các nút trong cây theo thứ tự in-order
void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// In ra các nút trong cây theo thứ tự post-order
void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Xóa một nút khỏi cây
Node* remove(Node* root, int value) 
{
    if (root == NULL) {
        return NULL;
    }
    if (value < root->data) {
        root->left = remove(root->left, value);
    } else if (value > root->data) {
        root->right = remove(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = remove(root->right, temp->data);
   return root;
    }
}

int main() 
{
    Node* root = NULL;
    // Tạo cây
root = insert(root, 50);
root = insert(root, 30);
root = insert(root, 20);
root = insert(root, 40);
root = insert(root, 70);
root = insert(root, 60);
root = insert(root, 80);

// In ra các nút trong cây
cout << "Duyet cay theo pre-order: ";
preOrder(root);
cout << endl;

cout << "Duyet cay theo in-order: ";
inOrder(root);
cout << endl;

cout << "Duyet cay theo post-order: ";
postOrder(root);
cout << endl;

// Tìm kiếm phần tử trong cây
int valueToSearch = 60;
if (search(root, valueToSearch)) {
    cout << "Phan tu " << valueToSearch << " co ton tai trong cay" << endl;
} else {
    cout << "Phan tu " << valueToSearch << " khong ton tai trong cay" << endl;
}

// Xóa phần tử khỏi cây
int valueToRemove = 30;
root = remove(root, valueToRemove);

// In ra các nút trong cây sau khi xóa phần tử
cout << "Duyet cay theo in-order sau khi xoa phan tu " << valueToRemove << ": ";
inOrder(root);
cout << endl;
return 0;
}