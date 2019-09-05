#include <iostream>
#include <vector>

using namespace std;
vector<int> threeWayPartition(vector<int> A,
		int lowVal, int highVal);
int main() {

	int t;
	cin>>t;
	while(t--)
	{

		int N;
		cin>>N;
		vector<int> A(N);
		int hash[1000001];
		memset(hash,0,sizeof hash);

		for(int i=0;i<N;i++){
			cin>>A[i];
			hash[A[i]]++;
		}

		int n,m;
		cin>>n>>m;

		// vector to store the answer
		// to verify the correct output
		vector<int> B(A.size());
		for(int i=0;i<A.size();i++)
		{
			B[i]=A[i];
		}
		int k1=0,k2=0,k3=0;
		int kk1=0;int kk2=0;int kk3=0;

		for(int i=0;i<B.size();i++)
		{

			if(B[i]>m)
			{
				k3++;
			}
			else if(B[i]<=m and B[i]>=n)
			{
				k2++;
			}
			else if(B[i]<m)
				k1++;
		}

		vector<int> Res = threeWayPartition(A,
				n,m);

		for(int i=0;i<k1;i++)
		{
			if(Res[i]<m)
				kk1++;
		}

		for(int i=k1;i<k1+k2;i++)
		{

			if(Res[i]<=m and Res[i]>=n)
				kk2++;

		}

		for(int i=k1+k2;i<k1+k2+k3;i++)
		{
			if(Res[i]>m)
				kk3++;
		}
		bool ok = 0;
		if(k1==kk1 and k2 ==kk2 and k3 == kk3)
			ok = 1;
		for(int i=0;i<Res.size();i++)
			hash[Res[i]]--;

		for(int i=0;i<Res.size();i++)
			if(hash[Res[i]]!=0)
				ok=0;

		if(ok)
			cout<<1<<endl;
		else
			cout<<0<<endl;

	}

	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*The function should return the modified array
  as specified in the problem statement */
vector<int> threeWayPartition(vector<int> A, int a, int b)
{
	//Your code here
	vector<int> v(A.size());
	vector<int>::iterator vfront = v.begin(), vmid = v.begin()+1;
	vector<int>::reverse_iterator vback = v.rbegin();
	for (vector<int>::iterator it=A.begin(); it!=A.end(); ++it){
		if (*it < a) *vfront++ = *it;
		else if (*it > b) *vback++ = *it;
	}
	for (vector<int>::iterator it=A.begin(); it!=A.end(); ++it)
		if (*it >= a && *it <= b) *vfront++ = *it;
	
	return v;
}

//  Given an array A[] and a range [a, b]. The task is to partition the array around the range such that array is divided in three parts.
//  1) All elements smaller than a come first.
//  2) All elements in range a to b come next.
//  3) All elements greater than b appear in the end.
//  The individual elements of three sets can appear in any order. You are required to return the modified arranged array.
//  
//  Input Format:
//  The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array (A[]).
//  
//  Output Format:
//  For each test case the output will be 1 if the array is properly arranged else it would be 0.
//  
//  User Task: 
//  The task is to complete the function threeWayPartition() which should segregate the elements as required. The function returns an array.
//  
//  Constraints:
//  1 <= T <= 100
//  1 <= N <= 10^5
//  1 <= A[i] <= 10^6
//  
//  Example:
//  Input:
//  2
//  5
//  1 2 3 3 4
//  1 2
//  3
//  1 2 3
//  1 3
//  
//  Output:
//  1
//  1
//  
//  Explanation:
//  Testcase 2: First, array has elements less than or equal to 1. Then, elements between 1 and 3. And, finally elements greater than 3. So, output is 1.
//   
//  
//  
