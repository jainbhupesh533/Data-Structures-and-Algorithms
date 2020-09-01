
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

// sort(hybrid of quicksort,heapsort,insertion sort)
// sort O(nlogn)

// stablity in sorting algorithms -
// stable sorts : Bubble sort Insertion Sort,Merge sort
// unstable sorts : selection Sorts,Quick sort ,Heap sort

// insertion sort O(n^2) - it used in small zise of arrays
void insertionSort(vi v, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
    for (auto x : v)
        cout << x << " ";
}


int main()
{
    FIO;
    OJ;
    // vi a = {10, 15, 20, 40};
    // vi b = {5, 6, 6, 10, 15};
    // // sort(v.begin(), v.end(), greater<int>());
    // int n, d, x, l;
    // vi v;
    // // vis v;
    // while (cin >> n)
    // {
    //     v.push_back(n);
    // }
    // for (auto x : v)
    //     cout << x << " ";
    // cout << endl;
    // insertionSort(v, v.size());
    // mergeSortNaive(a, b, a.size(), b.size());

    int n, d;
    cin >> n>>d;
    int a[n], b[d];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < d; i++)
        cin >> b[i];
    sort(a, a+n);
    sort(b, b+d);
    return 0;
}