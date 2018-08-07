/*

Challenge: write a function that solves for the expression (9+7)*8+5 
         +
        / \
       *   5
      / \
     +   8
    / \
   9   7

*/

#include <cstdlib>
#include <iostream>
using namespace std;


struct node {
	node* left;
	node* right;
	char const* const token;
};


double solve (const node * const root)
{
	double result;

	if (NULL==root->left) result=atof(root->token);
	else
		switch (root->token[0]) {
			case '+':
				result=solve(root->left) + solve(root->right);
			case '-':
				result=solve(root->left) - solve(root->right);
			case '*':
				result=solve(root->left) * solve(root->right);
			case '/':
				result=solve(root->left) / solve(root->right);

		}
	return result;
};

int main ()
{
	node N1{NULL,NULL,"2.71828"};
	node N2{NULL,NULL,"3.14159"};
	node N3{&N1,&N2,"/"};

	cout << solve(&N3) << endl;
	
	return 0;
}
