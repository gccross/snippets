// Find the middle element of a linked list. 
/* Test data.  Put in a file and redirect to stdin:

2
5
1 2 3 4 5
6
2 4 6 7 5 1

*/

#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    printf("%d ", getMiddle(head));
    }
    return 0;
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */
template <typename ForwardIterator>
ForwardIterator find_middle(ForwardIterator first, ForwardIterator last)
{
        size_t len(0);
        ForwardIterator it(first), it2(first);
        for (;it!=last;++it,++len)  if (len%2) ++it2;
        return it2;
}

template <typename T>
class Node_iterator {
public:
	explicit Node_iterator(T* _n) : n(_n){};
	Node_iterator& operator++ () { n=n->next; return *this; }
	T operator* () { return n->data; }
	T* operator-> () { return n; }
	bool operator!=(Node_iterator right) { return n!=right.n; }
private:
	T* n;
};

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
   Node_iterator<Node> mid = find_middle(Node_iterator<Node>(head),Node_iterator<Node>(NULL));
   return mid->data;
}
