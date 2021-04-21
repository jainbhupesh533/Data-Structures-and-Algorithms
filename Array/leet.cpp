
#include <bits/stdc++.h>
using namespace std;

// typedef vector <int> vi;
// typedef vector <bool> vib;
// typedef vector <string> vis;
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
#define OJ                                       \
    freopen("../checkup/input.txt", "r", stdin); \
    freopen("../checkup/output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int * twoSum(int arr[], int target, int t)
{
    int temp[2];
    for (int i = 0; i < t; i++)
    {
        for (int j = i + 1; j < t; j++)
        {
            if (arr[j] == target - arr[i])
            {
                temp[0] = i;
                temp[1] = j;
                return temp;
            }
        }
    }
    return arr;
}

int main()
{
    FIO;
    OJ;
    int n, t;
    cin >> t;
    int arr[t];
    for (int i = 0; i < t; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout<< twoSum(arr, target, t);

    return 0;
}