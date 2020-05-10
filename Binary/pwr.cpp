#include<bits/stdc++.h>
using namespace std;

//naive method
bool isPow(int n){
	if (n==0)
		return false;
	while(n!=1)
	{
		if(n%2!=0)
			return false;
		n = n/2;
	}
	return true;

	}
bool isPoo2(int n){
	return (n!=0) && ((n & (n-1))==0);
}
int main(){
	cout<<isPow(6)<<endl;
	cout<<isPoo2(8)<<endl;
	return 0;
}
