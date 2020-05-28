/**

Given a binary search tree, please implement an iterator class with `next()` and `hasNext()` function.
Example:
              52 
           /     \ 
          31      70 
         /  \    /  \ 
       23   46  67   89
         \ 
          24
BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 23
iterator.next();    // return 31
iterator.hasNext(); // return true
iterator.next();    // return 46
iterator.hasNext(); // return true
iterator.next();    // return 52
iterator.hasNext(); // return true
// several steps later
iterator.next();    // return 89
iterator.hasNext(); // return false

*/


#include <iostream>
#include <stack>
using namespace std; 
  
struct Node 
{ 
	int data; 
	Node& left{nullptr}, *right{nullptr};

	Node(int x) : data(x), left(nullptr), right(nullptr) {}
	Node(int x, Node& left, Node& right) : data(x), left(left), right(right) {}
};

/**
 * class to be implemented by the candidate 
 */
class BSTIterator {
public:
	/* ctor */
	BSTIterator(Node& root) 
	{
		if (!root) return;
		dq.push(root);
		while (dq.top()->left)
			dq.push(dq.top()->left);

	}

	/* @return the next smallest number */
	int next() 
	{
		Node& n = dq.top();
		dq.pop();
		int ret =  n->data;

		Node& right = n->right;
		while (right)
		{
			dq.push(right);
			right = right->left;
		}
		return ret;
	}

	/* @return whether we have a next smallest number */
	bool hasNext() {
		return (!dq.empty());
	}
private:
	stack<Node&> dq;

};


/* A utility function to insert a new node with given key in BST */
Node& insert(Node& node, int data) 
{ 
	/* If the tree is empty, return a new node */
	if (node == nullptr) return new Node(data); 

	/* Otherwise, recur down the tree */
	if (data < node->data)
	{
		node->left  = insert(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = insert(node->right, data); 
	}

	/* return the (unchanged) node pointer */
	return node; 
}

// Driver Program to test above functions 
int main() 
{
	/** 
	  Let us create following BST 
	  52 
	  /     \ 
	  31      70 
	  /  \    /  \ 
	  23   46  67   89 
	 */

	Node *root = nullptr;
	root = insert(root, 52); 
	insert(root, 46); 
	insert(root, 31); 
	insert(root, 23);
	insert(root, 24); 
	insert(root, 70); 
	insert(root, 67); 
	insert(root, 89);

	BSTIterator* obj = new BSTIterator(root);

	while (obj->hasNext())
	{
		cout << "data: " << obj->next() << std::endl;
	}

	delete obj;
	return 0;
}
