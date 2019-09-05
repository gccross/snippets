#include <algorithm>
#include <iostream>
using namespace std;
int findLongestConseqSubseq(int [], int );
int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		int a[n];
		
		// input array elements
		for(int i=0;i<n;i++)
		    cin>>a[i];
		
		cout<< findLongestConseqSubseq(a, n)<<endl;
		
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/

// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int arr[], int n)
{
	sort (arr, arr+n);
	unique(arr, arr+n);
	size_t telltail=1, num_consec=1;
	for (int i=1; i<n; ++i) {
		if (arr[i] == arr[i-1]+1) 
			if (++num_consec > telltail) ++telltail;
			else;
		else num_consec = 1;
	}
	
	return telltail;
}
