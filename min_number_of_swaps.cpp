// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include <iostream>

using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */
namespace george 
{
	template <typename It>
	void rotate (It first , It n_first, It last)
	{
		It next = n_first;
		while (first < next)
		{
			swap(*first++, *next++);
			if (next == last)
				next = n_first;
			else if (first == n_first)
				n_first = next;
		}
	}

	template <typename It>
	void insertion_sort(It first, It last)
	{
		if (distance(first,last) < 2) return;
		It next = first;
		while (++next != last)
		{
			It spot = lower_bound(first, next, *next);
			rotate(spot, next, next+1);

		}
	}
}

	struct node
	{
		int value;
		int index;
		bool vis;	
	};
	
	bool operator<(const node& l, const node& r)
	{
		return l.value < r.value;
	}

// return the minimum number of swaps required to sort the arra
int minSwaps(int arr[], int N){
    /*Your code here */

/*	
	//Test helper routines

G	for (int i = 0; i< N; ++i)
		cout << "original: " << arr[i] << "\t" ;
	cout << endl;

	george::rotate(arr, arr+N/2, arr+N); 
	for (int i = 0; i< N; ++i)
		cout << "rotated " << N/2 << ": " << arr[i] << "\t" ;
	cout << endl;

	
	george::insertion_sort(arr,arr+N);
	for (int i = 0; i< N; ++i)
		cout << "sorted: " << arr[i] << "\t" ;
	cout << endl;
*/


	node arrPos[N];

	for (int i=0; i<N; ++i)
		arrPos[i] = { arr[i],i,false};
	george::insertion_sort(arrPos,arrPos+N);

	int ans = 0;

	for (int i=0; i<N; ++i)
	{
		if (arrPos[i].vis || arrPos[i].index == i) continue;
		int j = i;
		int count = 0;
		while (!arrPos[j].vis)
		{
			arrPos[j].vis = true;
			j = arrPos[j].index;
			++count;
		}

		if (count) --count;
		ans += count;
	}
	
	
    return ans;    
    
}

/*
   // Graph solution
   template<typename T>
class graph{
    map<T,list<T>> adjList;
    public:
    graph(){

    }
    void addEdge(T u , T v , bool bidirectional=true){
        adjList[u].push_back(v);
        if(bidirectional){
            adjList[v].push_back(u);
        }
    }
    void print(){
        for(auto i : adjList){
            cout<<i.first<<": ";
            for(auto j : i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
    void recursiveDFS(T node , map<T,bool> &visited, map<int,int>&count,int colour){
        if(visited[node]==true){
            return ;
        }
        visited[node] = true;
        if(count.count(colour)==0) count[colour]=1;
        else count[colour]++;
        for(auto neighbour : adjList[node]){
            recursiveDFS(neighbour,visited,count,colour);
        }
    }
    int connected_components(T source){
        map<T,bool>visited;
        int component=1;
        int colour = 1;
        map<int,int>count;
        for(auto node : adjList){
            visited[node.first] = false;
        }
        recursiveDFS(source,visited,count,colour);
        int ans = count[colour]-1;
        colour++;
        for(auto node : adjList){
            if(!visited[node.first]){
                recursiveDFS(node.first,visited,count,colour);
                ans+=count[colour]-1;
                colour++;
                component++;
            }
        }
        return ans;
    }

};
int minSwaps(int A[], int N){
    int *arr = new int[N];
    for(int i=0;i<N;i++) arr[i] = A[i];
    sort(arr,arr+N);
    graph<int>g;
    for(int i=0;i<N;i++){
        g.addEdge(A[i],arr[i],false);
    }
    return g.connected_components(A[0]);
}

*/
/*
Given an array of integers. Find the minimum number of swaps required to sort the array in non-decreasing order.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N denoting the no of element of the array A[ ]. In the next line are N space separated values of the array A[ ] .

Output:
For each test case in a new line output will be an integer denoting  minimum umber of swaps that are  required to sort the array.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[] <= 106

User Task:
You don't need to read input or print anything. Your task is to complete the function minSwaps() which takes the array arr[] and its size N as inputs and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0.

Expected Time Complexity: O(NlogN).
Expected Auxiliary Space: O(N).

Example(To be used only for expected output):
Input:
2
5
1 5 4 3 2
4
8 9 16 15

Output:
2
1

Explanation:
Test Case 1: We need two swaps, swap 2 with 5 and 3 with 4 to make it sorted.
*/
