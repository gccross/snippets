#include <iostream>
#include <memory>
using namespace std;

struct Node
{
	int data;
	shared_ptr<Node> next;	
};

shared_ptr<Node> reorder(shared_ptr<Node> head)
{
	// get length
	size_t length=0;
	shared_ptr<Node> head2(head);
	while (head2)
	{
		head2=head2->next;
		++length;
	}
	
	// reverse to middle
	shared_ptr<Node> temp,rhead(NULL);
	head2=head;
	for (int i=0; i!= length/2+1; ++i)
	{
		temp = head2->next;
		head2->next = rhead;
		rhead = head2;
		head2 = temp;
	}

	// now interweave 2nd half of list with first
	shared_ptr<Node> temp2, rhead2(rhead);
	while (head2)
	{
		temp = rhead->next;
		rhead->next = head2;
		temp2 = head2->next;
		head2->next = temp;
		head2 = temp2;
		rhead = rhead->next->next;
	}

	// head2 is now NULL, rhead is now useless to us

	// now reverse back
	while (rhead2)
	{
		temp=rhead2->next;
		rhead2->next=head2;
		head2 = rhead2;
		rhead2 = temp;

	}
	return head2;

}

void print_list(shared_ptr<Node> head)
{
	
	while (head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;

}

int main ()
{
	shared_ptr<Node> head;
	for (size_t i=1;i<10;i++)
	{
		shared_ptr<Node> n(new Node());
		n->data=i;
		n->next=head;
		head=n;
	}

	print_list(head);
	head = reorder(head);
	print_list(head);

	return 0;
}
