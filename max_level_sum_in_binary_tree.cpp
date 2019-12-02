#include <deque>
#include <iostream>
#include <map>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;

	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
	if (node==NULL)
		return 0;
	else
		return 1 + max(height(node->left), height(node->right));
}
int maxLevelSum(Node * root);
/* Function to get diameter of a binary tree */
void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);    
}
/* Driver program to test size function*/
int main()
{
	int t;
	scanf("%d ", &t);
	while (t--)
	{
		map<int, Node*> m;
		int n;
		scanf("%d",&n);
		struct Node *root = NULL;
		struct Node *child;
		while (n--)
		{
			Node *parent;
			char lr;
			int n1, n2;
			scanf("%d %d %c", &n1, &n2, &lr);
			if (m.find(n1) == m.end())
			{
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL)
					root = parent;
			}
			else
				parent = m[n1];
			child = new Node(n2);
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
			m[n2]  = child;
		}
		cout << maxLevelSum(root) << endl;
	}
	return 0;
}

int maxLevelSum(Node* root)
{
	if (!root) return 0;
	deque<Node*> q;
	q.push_back(root);
	q.push_back(nullptr);
	int rowsum{0}, maxsum{INT_MIN};
	while (!q.empty()) {
		if (q.front() == nullptr) {
			if (rowsum > maxsum) maxsum = rowsum;
			rowsum = 0;
			q.pop_front();
			if (!q.empty()) q.push_back(nullptr);
		} else {
			rowsum += q.front()->data;
			if (q.front()->left) q.push_back(q.front()->left);
			if (q.front()->right) q.push_back(q.front()->right);
			q.pop_front();

		}
	}
	return maxsum;
}

