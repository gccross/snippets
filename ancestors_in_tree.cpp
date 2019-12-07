{
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
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
bool printAncestors(struct Node *root, int target);
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
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
     int a;
     cin>>a;
    printAncestors(root, a);
  }
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
// Function should print all the ancestor of the target node
bool printAncestors(struct Node *root, int target)
{
    //cout << "target: " << target << endl;
    if (0 == target) {
        cout << endl;
        return false;
    }
    if (root->left && root->left->data == target
        ||
        root->right && root->right->data == target)
    {
        cout << root->data ;
        if (root->data == 0 ) cout << endl;
        else cout << " ";
        return true;
    }
    if (root->left && printAncestors(root->left, target) 
        ||
        root->right && printAncestors(root->right, target))
    {
        cout << root->data ;
        if (root->data == 0 ) cout << endl;
        else cout << " ";
        return true;
    }
    return false;
}
