
#include<bits/stdc++.h>
using namespace std;
 
// typedef vector <int> vi;
//typedef vector <string> vi;
// typedef pair< int ,int > pii;
// #define endl "\n"
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
// #define clr(val) memset(val,0,sizeof(val))
// #define what_is(x) cerr << #x << " is " << x << endl;
#define OJ \
    freopen("checkup/input.txt", "r", stdin); \
    freopen("checkup/output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//Main Program 
void powerSet(string s){
    int n = s.length();
    // cout<<n;
    int powsize  = pow(2,n);
    for (int i = 0; i < powsize; i++)
    {
        for(int j= 0;j<n;j++){
            if (i & (1<<j))
                cout<<s[j];
        }
        cout<<endl;
    }
    
}
 
int main()
{
 FIO;
 OJ;
 string n;
 cin>>n;

 powerSet(n);
return 0;
   
}