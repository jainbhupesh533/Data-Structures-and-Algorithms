
#include <bits/stdc++.h>
using namespace std;

// typedef vector <int> vi;
// typedef pair< int ,int > pii;
// #define sd(val) scanf("%d",&val)
// #define ss(val) scanf("%s",&val)
// #define sl(val) scanf("%lld",&val)
// #define debug(val) printf("check%d\n",val)
// #define all(v) v.begin(),v.end()
// #define PB push_back
// #define MP make_pair
// #define FF first
// #define SS second
// #define ll long long
// #define MOD 1000000007
// #define PI 3.141592653589793238
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
/*
//First set bit 
 unsigned int getFirstSetBit(int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        if((n & (1<<i)) == 0)
            count++;
        else 
            return count+1;
    }
   return 1;
}*/

/* count total set bits
int countsetBits(int n){
int count=0;
for(int i=1;i<=n;i++)
{
int x=i;
while(x!=0)
{
x = x &(x-1);
count++;
}
}
return count;
}

int posOfRightMostDiffBit(int m, int n)
{
    return log2((m ^ n) & -(m ^ n)) + 1;
}
*/
/*
int countBitsFlip(int a, int b){
    int count=0;
    // Your logic here
    int x=  (a^b);

    while(x>0){
        x &= x-1;
        count++;
    }
    return count;
}
*/
/*
bool isSparse(int n){
    
    // Your code
    return ((n & (n>>1)) == 0);
}
*/
/*
int maxConsecutiveOnes(int x)
{
 int count = 0;
    // Your code here
    for (int i=0;i<x;i++){
            x &= (x<<1);
            count++;
    }
    return count;
    
}*/
/*
int greyConverter(int n)
{
    return n^(n>>1);
    
}

int grayToBinary(int n)
{
    
    // Your code here
    int sum = n;
    while(n>1){
        n=n>>1;
        sum =  (sum ^ n);
    }
    return sum;
}*/

/*
bool isPowerofTwo(long long n){
    
    // Your code here  
    return ((n & (n-1)) == 0);
    
}*/

unsigned int swapBits(unsigned int n)
{
	
	// Your code here
	int even = n & 0xAAAAAAAA;
even = even >> 1;
int odd = n & 0x55555555;
odd = odd << 1;
return even | odd;
	
}

int main()
{
    FIO;
    OJ;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >>  n;
        //cout<< getFirstSetBit(n);
        //cout << posOfRightMostDiffBit(m, n) << endl;
        //cout<<countBitsFlip(m,n)<<endl;
        //cout<<isSparse(n)<<endl;
        //cout<<maxConsecutiveOnes(n)<<endl;
       // cout<<greyConverter(n)<<endl;
    }

    return 0;
}