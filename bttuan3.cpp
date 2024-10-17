#include <iostream>
#include <fstream>
using namespace std;
// khai bao cau truc cay
struct Node
    {
        int data;
        Node* left;
        Node* right;
    } ;
typedef struct Node* tree;
tree root;
void Init(Node* &root) //sau khi tạo cây gọi hàm init, So root = null cho biết là cây rỗng
{
   root = NULL;
}
Node* taoNode(int x) { // Tao node moi
    Node* taoNode = new Node();
    taoNode->data = x;
    taoNode->left = NULL;
    taoNode->right = NULL;
    return taoNode;
}
Node* themNode(Node* root, int value) { 
    if (root == NULL) {
        root = taoNode(value);
    } else if (value < root->data) {
        root->left = themNode(root->left, value);
    } else {
        root->right = themNode(root->right, value);
    }
    return root;
}
void duyetNLR(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        duyetNLR(root->left);
        duyetNLR(root->right);
    }
}
bool Timkiem(Node* root, int data) {
    if (root == NULL) {
        return false;
    }
    if (root->data == data) {
        return true;
    }
    if (data < root->data) {
        return Timkiem(root->left, data);
    } else {
        return Timkiem(root->right, data);
    }
}
Node* timnodethaythe(Node* node) { //Dùng trong xóa node, khi mà node có 2 con, tìm node con bên trái nhỏ nhất
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
Node* Xoanode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = Xoanode(root->left, data);
    } else if (data > root->data) {
        root->right = Xoanode(root->right, data);
    } else {
        // Node có một hoặc không có con
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = timnodethaythe(root->right); //Neu node có 2 con
    root->data = temp->data;
    root->right = Xoanode(root->right, temp->data);
}
return root;
}
int main() {
Node* root = NULL;
int luachon, value;
do {
    cout << "Lua chon:\n";
    cout << "1. Tao cay \n";
    cout << "2. Duyet cay theo thu tu NLR (preorder)\n";
    cout << "3. Them 1 phan tu vao cay\n";
    cout << "4. Xoa 1 phan tu\n";
    cout << "5. Tim kiem 1 phan tu trong cay\n";
    cout << "6. Thoat khoi chuong trinh nay\n";
    cin >> luachon;

    switch (luachon) {
        case 1:
            cout << "Nhap gia tri cho nut goc cua cay: ";
            cin >> value;
            root = taoNode(value);
            break;
        case 2:
            cout << "Duyet theo thu tu NLR: ";
            duyetNLR(root);
            cout << endl;
            break;
        case 3:
            cout << "Nhap so can them vao cay: ";
            cin >> value;
            themNode    (root, value);
            break;
        case 4:
            cout << "Nhap so can xoa : ";
            cin >> value;
            root = Xoanode(root, value);
            break;
        case 5:
            cout << "Nhap so can tim : ";
            cin >> value;
            if (Timkiem(root, value)) {
                cout << "So " << value << " co trong cay.\n";
            } else {
                cout << "So " << value << " khong ton tai trong cay.\n";
            }
            break;
        case 6:
            break;
        default:
            cout << "******CHON LAI Lua CHON KHAC ********.\n";
    }

} while (luachon != 6);

return 0;
}   