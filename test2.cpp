#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
using namespace std;
// Cấu trúc của một nút trong cây biểu thức nhị phân
struct Node {
    std::string data;
    Node* left;
    Node* right;
    Node(std::string data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Hàm kiểm tra xem một chuỗi có phải là một toán hạng hay không
bool isOperand(std::string str) {
    return str != "+" && str != "-" && str != "*" && str != "/";
}

// Hàm để chuyển biểu thức từ chuỗi thành cây biểu thức nhị phân
Node* constructExpressionTree(std::string expression) {
    std::stack<Node*> stack;
    for (int i = 0; i < expression.length(); i++) {
        std::string token = "";
        // Nếu là toán hạng, tạo một nút lá mới và đưa vào stack
        if (isdigit(expression[i])) {
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                token += expression[i];
                i++;
            }
            i--;
            Node* node = new Node(token);
            stack.push(node);
        }
        // Nếu là toán tử, tạo một nút mới và lấy hai nút trên đầu stack để làm con trái và con phải
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            Node* right = stack.top();
            stack.pop();
            Node* left = stack.top();
            stack.pop();
            Node* node = new Node(std::string(1, expression[i]));
            node->left = left;
            node->right = right;
            stack.push(node);
        }
        // Nếu không phải là toán hạng hoặc toán tử, đó là một ký tự không hợp lệ
        else {
            throw std::invalid_argument("Invalid character: " + std::string(1, expression[i]));
        }
    }
    // Phần tử cuối cùng trên đỉnh stack là nút gốc của cây biểu thức nhị phân
    return stack.top();
}

// Hàm đệ quy để tính giá trị biểu thức từ cây biểu thức nhị phân
float evaluateExpression(Node* root) {
    // Nếu nút hiện tại là một nút lá, trả về giá trị của nó
    if (root->left == nullptr && root->right == nullptr) {
        return std::stof(root->data);
    }
    // Nếu nút hiện tại là một nút phép toán, tính giá trị của các nút con bên trái và bên phải và áp dụng phép toán lên hai giá tr
    float leftValue = evaluateExpression(root->left);
    float rightValue = evaluateExpression(root->right);
    if (root->data == "+") {
        return leftValue + rightValue;
    } else if (root->data == "-") {
        return leftValue - rightValue;
    } else if (root->data == "*") {
        return leftValue * rightValue;
    } else if (root->data == "/") {
        return leftValue / rightValue;
    } else {
        throw std::invalid_argument("Invalid operator: " + root->data);
    }
}
