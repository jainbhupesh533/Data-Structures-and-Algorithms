
#include <bits/stdc++.h>
using namespace std;

#define OJ                                       \
    freopen("../checkup/input.txt", "r", stdin); \
    freopen("../checkup/output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

int countMerge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = a[m + 1 + j];
    int res = 0, i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
            res += (n1 - i);
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = right[j];
        j++;
        k++;
    }
    return res;
}

// count inversion of an array in a O(nlogn) time
int countInversion(int a[], int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = l + (r - l) / 2;
        res += countInversion(a, l, m);
        res += countInversion(a, m + 1, r);
        res += countMerge(a, l, m, r);
    }
    return res;
}

int main()
{
    FIO;
    OJ;
    int n, l = 0;
    cin >> n;
    int a[n], r = n - 1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
   cout<< countInversion(a, l, r);
    return 0;
}