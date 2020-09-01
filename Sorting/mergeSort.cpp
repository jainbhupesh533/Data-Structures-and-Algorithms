#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define OJ                                       \
    freopen("../checkup/input.txt", "r", stdin); \
    freopen("../checkup/output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// Merge Sort -
/*
Divide and Conquer Algortihm
Stable Algotithms
O(nlogn) Time and O(n) Auzx space
well suited for linked losts O(1) in aux space
used in external sorting
in arrays, quicksort is better
*/

// merge two sorted arrays in a naive solution -O((m+n)*log(m+n))

void mergeSortNaive(vi a, vi b, int n, int m)
{
    vi c;
    copy(a.begin(), a.end(), back_inserter(c));
    copy(b.begin(), b.end(), back_inserter(c));
    sort(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " ";
    cout << endl;
}

// effiecient solution -O(m+n)
void mergeSortEfficient(int a[], int b[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
            cout << a[i++] << " ";
        else
            cout << b[j++] << " ";
    }
    while (i < m)
        cout << a[i++] << ' ';
    while (j < n)
        cout << b[j++] << " ";
}

// Merge Sort Algorithm - O(n*d), d = logn ,spcae -Θ(n)
// example - if we have 8 elements then we have [log₂8] +1  = 4
// for megring it take Θ(n) of n and for each resursive it will take same

void merge(int arr[], int l, int m, int h) //time =O(n),spcace=O(n)
{
    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + 1];
    for (int i = 0; i < n1; i++)
        right[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = right[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
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
    // mergeSortNaive(a, b, a.size(), b.size());

    int n, d;
    cin >> n >> d;
    int a[n], b[d];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < d; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + d);
    mergeSortEfficient(a, b, n, d);
    return 0;
}