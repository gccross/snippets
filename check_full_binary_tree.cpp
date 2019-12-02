#include <iostream>
#include <deque>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->key==a1){
		switch(lr){
			case 'L':root->left=new Node(a2);
			break;
			case 'R':root->right=new Node(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
bool isFullTree (struct Node* root);
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node* root = NULL;
		while(n-->0){
				int a1,a2;
				char lr;
				cin>>a1>>a2>>lr;
				if(root==NULL){
					root=new Node(a1);
					switch(lr){
						case 'L':root->left=new Node(a2);
						break;
						case 'R':root->right=new Node(a2);
						break;
					}
				}
				else{
					insert(root,a1,a2,lr);
				}
			}
		if (isFullTree(root))
			cout<<"1" << endl;
		else
			cout<<"0" << endl;
	}
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node *left, *right;
};
*/
bool isFullTree (struct Node* root)
{
//add code here.
    deque<Node*> q;
    q.push_back(root);
    q.push_back(nullptr);
    while (!q.empty()) {
        if (q.front() == nullptr) {
            q.pop_front();
            if (!q.empty()) q.push_back(nullptr);
        } else {
            if (q.front()->left && !q.front()->right
                ||
                !q.front()->left && q.front()->right)
                return false;
            
            if (q.front()->left) q.push_back(q.front()->left);
            if (q.front()->right) q.push_back(q.front()->right);
            q.pop_front();
        }
    }
    return true;
}

