#include<queue>
#include<string>
#include <cstdlib>
#include <fstream>
#include <stack>
#include <iostream>

using namespace std;
struct Node {
	int data;
	char type;
	Node* left;
	Node* Right;
};

class BinaryTree {
private:
	Node* root;

	Node* Create_Node(int w, char t) {
		Node* n = new Node;
		n->data = w;
		n->left = NULL;
		n->Right = NULL;
		n->type = t;
		return n;
	}
	int operation(int x0, int x1, char O) {
		switch (O) {
		case '+':
			return x0 + x1;
			break;
		case '-':
			return x0 - x1;
			break;
		case '/':
			return x0 / x1;
			break;
		case '*':
			return x0 * x1;
			break;
		case '%':
			return x0 % x1;
			break;
		case '^':
			return x0 ^ x1;
			break;

		}
	}
	char is_digit(char s) {
		if ('0' <= s && s <= '9')
			return 'N';
		return 'O';

	}

public:

	Node* get_root() {
		return this->root;
	}

	BinaryTree() {/*root = NULL; */ };
	~BinaryTree() {};


	void evaluate() {
		int n1, n2;
		int Ans;

		stack <int> st;
		int num;
		int n;
		string x;
		ifstream file;
		file.open("text.txt", ios::in);
		file >> num;
		for (int i = 0; i < num; i++) {
			file >> x;
			char y;
			y = is_digit(x[0]);
			if (y == 'N') {
				n = stoi(x);
				st.push(n);
			}
			else if (y == 'O') {
				n2 = st.top();
				st.pop();
				n1 = st.top();
				st.pop();
				Ans = operation(n1, n2, x[0]);
				st.push(Ans);

			}
		}

		cout << st.top();

	}
	void construct_tree() {
		stack <Node*> st;
		int num;
		int n;
		string x;
		ifstream file;
		file.open("text.txt", ios::in);
		file >> num;
		for (int i = 0; i < num; i++) {
			file >> x;
			Node* k = new Node;
			char y;
			y = is_digit(x[0]);
			if (y == 'N') {
				n = stoi(x);

				k = Create_Node(n, 'N');
				st.push(k);
			}
			else if (y == 'O') {

				k = Create_Node((int)x[0], 'O');
				k->Right = st.top();
				st.pop();
				k->left = st.top();
				st.pop();
				st.push(k);
			}

		}root = st.top();
	}
	void print_tree(Node* root1) {
		queue <Node*> q;
		char tmp;
		q.push(root1);
		int count;
		while (!q.empty()) {
			count = q.size();
			for (int i = 0; i < count; i++) {
				if (q.front()->left != NULL)
					q.push(q.front()->left);
				if (q.front()->Right != NULL)
					q.push(q.front()->Right);
				if (q.front()->type == 'N') {
					cout << q.front()->data << " ";
					q.pop();
				}
				else if (q.front()->type == 'O') {
					tmp = q.front()->data;
					cout << tmp << " ";
					q.pop();

				}
			}
			cout << endl;

		}
	}

};

int main() {
	int choice;	BinaryTree T;
	while (1) {
		cout << "_____________________________________________________________" << endl;
		cout << "1. Read postfix expression from file and create expression tree \n";
		cout << "2. Evaluate postfix expression from file \n";
		cout << "3. Print tree level by level \n";
		cout << "4. Exit \n";
		cout << "_____________________________________________________________" << endl;
		cout << "Enter Your Choice : ";
		cin >> choice;
		switch (choice) {
		case 1:
			T.construct_tree();
			break;

		case 2:
			T.evaluate();
			cout << endl;
			break;
		case 3: 
			T.print_tree(T.get_root());
			break;
		case 4:
			cout << "End of program";
			cout << endl<<"_____________________________________________________________" << endl;
			exit(0);
		default:  cout << "invalid choice" << endl;
		}
	}

	return 0;
}