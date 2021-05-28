
#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<char, int> u_map;
// typedef vector <int> vi;
// typedef vector <bool> vib;
// typedef vector <string> vis;
// typedef pair< int ,int > pii;
#define endl "\n"
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


//  * NAive Searching - O(n-m+1 * m) O(1)
void naiveSearching(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (str2[j] != str1[i + j])
                break;
        if (j == m)
            cout << i << " ";
    }
}

// * Improved naive seaching for disctint

int main()
{
    FIO;
    OJ;
    string str1, str2;
    cin >> str1 >> str2;

    naiveSearching(str1, str2);
    return 0;
}