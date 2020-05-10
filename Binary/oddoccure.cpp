
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
// typedef pair< int ,int > pii;
// #define endl "\n"
// #define sd(val) scanf("%d",&val)
// #define ss(val) scanf("%s",&val)
// #define sl(val) scanf("%lld",&val)
// #define debug(val) printf("check%d\n",val)
// #define all(v) v.begin(),v.end()
#define PB push_back
// #define MP make_pair
// #define FF first
// #define SS second
// #define ll long long
// #define MOD 1000000007
// #define clr(val) memset(val,0,sizeof(val))
// #define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                                    \
	freopen("checkup/input.txt", "r", stdin); \
	freopen("checkup/output.txt", "w", stdout);
#define FIO                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);



//MAin Program

/*  Efficient solution of one odd no
int findOdd(vi v,int n){
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res = res ^ v[i];
	}
	return res;
}
*/

/* missing no program
int getMissing(vi v,int n){
	 int x1 = v[0]; 
  
    // For xor of all the elements from 1 to n+1 
    int x2 = 1; 
  
    for (int i = 1; i < n; i++) 
        x1 = x1 ^ v[i]; 
  
    for (int i = 2; i <= n + 1; i++) 
        x2 = x2 ^ i; 
  
    return (x1 ^ x2);
}
*/

//two odd appearing numbers effiecient is O(n)
void oddAppering(vi v,int n){
	int xor1 = 0,res1 =0,res2 =0;
	for (int i = 0; i < n; i++)
	{
		xor1 = xor1 ^ v[i];
	}
	int s= xor1 & ~(xor1 -1); // right most set bit
	for (int i = 0; i < n; i++)
	{
		if ((v[i] & s) != 0)
			res1 = res1 ^ v[i];
		else
			res2 = res2 ^ v[i];
		
	}
	cout<< res1<<" "<<res2;
}

int main()
{
	OJ;
	FIO;

	vi v;
	int n;
	while (cin >> n)
	{
		v.PB(n);
	}

/*	// naive soltion  - O(N^2) for both one and two odd elements
	for (int i = 0; i < v.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == v[i])
			{
				count++;
			}
		}
		if (count % 2 != 0)
		{
			cout << v[i];
		}
	}
	*/

	//Effiecient solution -O(n) and space O(1)
	//cout<<findOdd(v,v.size());

	//find an missing number
	//cout<<getMissing(v,v.size());

	//two odd occuring 
	oddAppering(v,v.size());

	return 0;
}