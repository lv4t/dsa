#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
	string s;
	Node *left, *right;

	Node(string s)
	{
		this->s = s;
		this->left = this->right = nullptr;
	}
};
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to check if a given character is a digit (0-9)
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to construct a binary expression tree from a postfix expression
Node* constructTree(string postfix) {
    stack<Node*> stack;
    Node *t, *t1, *t2;

    // Traverse through every character of the postfix expression
    for (int i = 0; i < postfix.length(); i++) {
        // If the current character is a digit, push a new node to the stack
        if (isDigit(postfix[i])) {
            t = new Node(string(1, postfix[i]));
            stack.push(t);
        }
        // If the current character is an operator, pop two nodes from the stack,
        // create a new node with the operator as the root and the popped nodes as
        // the left and right children, then push the new node back to the stack
        else if (isOperator(postfix[i])) {
            t = new Node(string(1, postfix[i]));
            t1 = stack.top();
            stack.pop();
            t2 = stack.top();
            stack.pop();
            t->right = t1;
            t->left = t2;
            stack.push(t);
        }
    }
    // The last node remaining in the stack is the root of the binary expression tree
    t = stack.top();
    stack.pop();

    return t;
}

// Utility function to check if a given node is a leaf node
bool isLeaf(Node* node) {
	return node->left == nullptr && node->right == nullptr;
}

// Function to apply an operator 'op' to values 'x' and 'y' and return the result
double process(string op, double x, double y)
{
	if (op == "+") { return x + y; }
	if (op == "-") { return x - y; }
	if (op == "*") { return x * y; }
	if (op == "/") { return x / y; }

	return 0;
}

// Recursive function to evaluate a binary expression tree
double evaluate(Node* root)
{
	// base case: invalid input
	if (root == nullptr) {
		return 0;
	}

	// the leaves of a binary expression tree are operands
	if (isLeaf(root)) {
		return stod(root->s);
	}

	// recursively evaluate the left and right subtree
	double x = evaluate(root->left);
	double y = evaluate(root->right);

	// apply the operator at the root to the values obtained in the previous step
	return process(root->s, x, y);
}
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->s << " ";
        inOrder(root->right);
    }
}
int main()
{
	/*Node* root = new Node("+");
	root->left = new Node("*");
	root->right = new Node("/");
	root->left->left = new Node("-");
	root->left->right = new Node("5");
	root->right->left = new Node("21");
	root->right->right = new Node("7");
	root->left->left->left = new Node("10");
	root->left->left->right = new Node("5");*/
	string s;
	cout<<"nhap bieu thuc can tinh:\n";
    getline(cin,s);
	Node* data = constructTree(s);
	cout << "Bieu thuc la: ";

            inOrder(data);
            cout << endl;
	cout << "Gia tri bieu thuc la " << evaluate(data) << endl;
	return 0;
}