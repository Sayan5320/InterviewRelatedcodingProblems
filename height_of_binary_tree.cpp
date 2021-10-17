#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data)
{

	Node* newnode = new Node();
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

int calculateHeight(Node* root)
{
	queue<Node*> nodesInLevel;
	int height = 0;
	int nodeCount = 0; 
	Node* currentNode; 
					
	if (root == NULL) {
		return 0;
	}
	nodesInLevel.push(root);
	while (!nodesInLevel.empty()) {
		height++;
		nodeCount = nodesInLevel.size();
		while (nodeCount--) {
			currentNode = nodesInLevel.front();

			if (currentNode->left != NULL) {
				nodesInLevel.push(currentNode->left);
			}
            if (currentNode->right != NULL) {
				nodesInLevel.push(currentNode->right);
			}
            nodesInLevel.pop();
		}
	}
	return height;
}

int main()
{

	Node* root = NULL;

	root = createNode(100);
	root->left = createNode(103);
	root->left->left = createNode(256);
	root->left->left->left = createNode(95);
	root->left->right = createNode(111);
	root->right = createNode(92);
	root->right->left = createNode(14);
	root->right->left->right = createNode(200);
	root->right->left->left = createNode(220);
	root->right->left->left = createNode(500);
	root->right->left->left->right = createNode(524);

	cout << "The height of the binary tree using iterative "
			"method is: " << calculateHeight(root) << ".";

	return 0;
}
