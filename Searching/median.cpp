
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
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

// median of two sorted arrays with effiecient solution by binary search - O(logn)
// we always assume first array is smaller size then second one
// if n1>n2 then we use to swap the array using pointers

double medianSorted(vi a1, vi a2, int n1, int n2)
{
    int begin1 = 0, end1 = n1;
    while (begin1 <= end1)
    {
        int i1 = (begin1 + end1) / 2;
        int i2 = (n1 + n2 + 1) - i1;
        int min1 = (i1 == n1) ? INT_MAX : a1[i1];
        int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];
        int min2 = (i2 == n2) ? INT_MAX : a2[i2];
        int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];
        if (max1 <= min2 && max2 <= min1)
        {
            if ((n1 + n2) % 2 == 0)
                return ((double)max(max1, max2), min(min1, min2)) / 2;
            else
                return (double)max(max1, max2);
        }
        else if (max1 > min2)
            end1 = i1 - 1;
        else
            begin1 = i1 + 1;
    }
}

int main()
{
    FIO;
    OJ;
    int n, x;
    int a1[10000001], a2[1000001];
    for (int i = 0; i < 4; i++)
        cin >> a1[i];
    for (int i = 0; i < 5; i++)
        cin >> a2[i];

    // while (cin >> n)
    // {
    //         if(n=='\n') break;
    //         else a1.push_back(n);
    // }
    // cout<<"Entering another vector: ";
    // while (cin >> x)
    // {
    //     a2.push_back(x);
    // }
    // for (auto i = 0; i < a1.size(); i++)
    // {
    //     cout << a1[i] << " ";

//  for (auto i = 0; i < a2.size(); i++)
// {
//     cout << a2[i] << " ";
// }
// if (a1.size() > a2.size())
//     a1.swap(a2);
// else
cout << medianSorted(a1, a2, 4, 5);
return 0;
}
