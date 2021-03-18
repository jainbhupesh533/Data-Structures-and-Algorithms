
#include <bits/stdc++.h>
using namespace std;

// typedef vector <int> vi;
// typedef vector <bool> vib;
// typedef vector <string> vis;
#define OJ                                       \
    freopen("../checkup/input.txt", "r", stdin); \
    freopen("../checkup/output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// intersection of two sorted arrays - O(m*n)
void intersection(int a[], int b[], int n, int d)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i - 1] == a[i])
            continue;
        for (int j = 0; j < d; j++)
            if (a[i] == b[j])
                cout << a[i] << " ";
    }
}

// intersection of two sorted arrays - O(m+n)
void intersectionEfficient(int a[], int b[], int n, int d)
{
    int i = 0, j = 0;
    while (i < n & j < d)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
}

// union of two arrays - O(m=n),O(1)
void unionEffiecient(int a[], int b[], int n, int d)
{
    int i = 0, j = 0;
    while (i < n && j < d)
    {
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j - 1])
        {
            j++;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            i++;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << ' ';
            j++;
        }
        else
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (i == 0 || a[i] != a[i - 1])
        {
            cout << a[i] << " ";
            i++;
        }
    }
    while (j < d)
    {
        if (j == 0 || b[j] != b[j - 1])
        {
            cout << b[j] << " ";
            j++;
        }
    }
}

int main()
{
    FIO;
    OJ;
    int n, d;
    cin >> n >> d;
    int a[n], b[d];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < d; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + d);
    // intersection(a, b, n, d);
    // intersectionEfficient(a, b, n, d);
    unionEffiecient(a, b, n, d);
    return 0;
}