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

// intersection of two sorted arrays 0-means common elemets
// Naive solution - O(m*n),O(1)

void intersection(int a[], int b[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i > 0 && a[i - 1] == a[i])
            continue;
        for (int j = 0; j < n; j++)
            if (a[i] == b[j])
                cout << a[i]<<" ";
    }
}

int main()
{
    FIO;
    OJ;
}