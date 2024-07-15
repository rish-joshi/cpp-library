#ifndef LIBRARY_HPP
#define LIBRARY_HPP

class Node {
public:
	Node* next;
	static int totalNodes;
	int data = -1;

	void addNode(int number);
	void printNodes();
	Node* addHead(int number);
	void printTotalNodes();
	Node* removeNode(int position);
}; 

class BinaryTree {
public:
	int data = -1;
	BinaryTree* Left;
	BinaryTree* Right;

	// Add a child to the binary tree.
	void addChild(int number);

	// Make the inverse binary tree. Or make the mirror.
	void INVaddChild(int number);

	/* DUH! Print the content of the tree.
		`0 means PREORDER`
		`1 means INORDER`
		`2 means POSTORDER`
	*/
	void PrintTree(int TraversalType = 0);
};


#endif