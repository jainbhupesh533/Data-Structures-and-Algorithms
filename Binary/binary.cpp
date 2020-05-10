// C++ program to Count set 
// bits in an integer 
#include <bits/stdc++.h> 
using namespace std; 

/* Function to get no of set bits in binary 
representation of positive integer n */
unsigned int countSetBits(unsigned int n) 
{ 
	unsigned int count = 0; 
	while (n != 0) {
	    if (n % 2 != 0)
	       count++;
	    n = n/2;      
	} 
	return count; 
} 

/* Program to test function countSetBits */
int main() 
{ 
#ifndef ONLINE_JUDGE
	freopen("checkup/input.txt","r",stdin);
	freopen("checkup/output.txt","w",stdout);
#endif
	int i;
	cin>>i;
	cout << countSetBits(i)<<endl; 
	return 0; 
} 


