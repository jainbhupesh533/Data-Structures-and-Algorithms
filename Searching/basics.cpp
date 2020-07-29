
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

// binary search by recursive approach O(logn)

/*
int binary_search(vi v, int low, int high, int x)
{
    int mid = (low + high) / 2;
    if (low > high)
        return -1;
    else if (v[mid] == x)
        return mid;
    else if (v[mid] > x)
        return binary_search(v, low, mid - 1, x);
    else if (v[mid] < x)
        return binary_search(v, mid + 1, high, x);
}
*/

int binarySearch(vi arr, int l, int r, int x)
{
    // int l = n/2+1, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    return -1;
}

// first occureence by binary search O(logn)

int firstOcc(vi v, int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (v[mid] > x)
            h = mid - 1;
        else if (v[mid] < x)
            l = mid + 1;
        else
        {
            if (mid == 0 || v[mid - 1] != v[mid])
                return mid;
            else
                h = mid - 1;
        }
    }
    return -1;
}

// last occurence iin O(logn)

int lastOcc(vi v, int n, int x)
{
    int l = 0, h = n;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (v[mid] > x)
            h = mid - 1;
        else if (v[mid] < x)
            l = mid + 1;
        else
        {
            if (mid == 0 || v[mid] != v[mid + 1])
                return mid;
            else
                l = mid + 1;
        }
    }
    return -1;
}

// count ocuurence in sorted - O(logn) with the help of last and first occurrenece of a problem

int countOccurence(vi v, int n, int x)
{
    int first = firstOcc(v, n - 1, x);
    if (first == -1)
        return 0;
    else
        return (lastOcc(v, n - 1, x) - first + 1);
}

// COunt 1s in a sorted binary arrray - O(logn)
int countOnes(vi v, int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (h + l) / 2;
        if (v[mid] == 0)
            l = mid + 1;
        else
        {
            if (mid == 0 || v[mid - 1] == 0)
                return (n - mid);
            else
                h = mid - 1;
        }
    }
    return 0;
}

// square root of an number - O(n ^1/2)

int sqrtNum(int x)
{
    int i = 1;
    while (i * i <= x)
    {
        i++;
    }
    return (i - 1);
}

// square root of an number with an effecient solution -O(logn)

int sqrtEfficient(int x)
{
    int l = 1, h = x, ans = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int mSq = mid * mid;
        if (mSq == x)
            return mid;
        else if (mSq > x)
            h = mid - 1;
        else
        {
            l = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

// search an element in an infinite sized array - naive solution O(n)

int searchInfinite(vi v, int x)
{
    int i = 0;
    while (true)
    {
        if (v[i] == x)
            return i + 1;
        if (v[i] > x)
            return -1;
        i++;
    }
}

// Efficient Solution -O(log position) unbounded binary search

int searchInfiniteEff(vi v, int n, int x)
{
    if (v[0] == x)
        return 0;
    int i = 1;
    while (v[i] < x)
        i *= 2;
    if (v[i] == x)
        return i;
    return binarySearch(v, i / 2 + 1, i - 1, x);
}

// search on a  sorted rotated array -O(logn)
// the approach is we search in a first sorted jhalf and then others

int searchSortedReverse(vi v, int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (v[mid] == x)
            return mid;
        if (v[l] < v[mid])
        {
            if (x >= v[l] && x < v[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (x > v[mid] && x <= v[h])
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
    return -1;
}

// peak element that mean its the largest fform the neighbours -O(logn)
// this is not sorted but still we are using binary search

int getPeak(vi v, int n)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if ((mid == 0 || v[mid - 1] <= v[mid]) && (mid == n - 1 || v[mid + 1] <= v[mid]))
            return mid;
        else if (mid > 0 && v[mid - 1] > v[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

// given an unsorted array and a number x we need to find a pair in the array with sum equals to x
// Naive solution

int getPair(vi v, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] == x)
                return true;
        }
    }
    return false;
}

// Two pointer approach when array is sorted - O(n) logn for sorting

int getPairPointer(vi v, int n, int x)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (v[left] + v[right] == x)
        {
            return true;
        }
        else if (v[left] + v[right] > x)
            right -= 1;
        else
            left += 1;
    }
    return false;
}


// two pointer approach when triplet of sum is founding in sorted arrtay O(n^2)

int isPair(vi v, int left,int right, int x)
{
    // int left = 0, right = n - 1;
    while (left < right)
    {
        if (v[left] + v[right] == x)
        {
            return true;
        }
        else if (v[left] + v[right] > x)
            right -= 1;
        else
            left += 1;
    }
    return false;
}

int getpairTriplet(vi v, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (isPair(v, i + 1, n - 1,x - v[i]))
            return true;
    }
}

// triplet of a pair of a sum sorted or unsorted is O(n^2) by hashing


int main()
{
    FIO;
    OJ;
    int n, d, x, l;

    vi v;
    // vis v;
    cin >> x;
    while (cin >> n)
    {
        v.push_back(n);
    }
    // sort(v.begin(), v.end());
    for (auto i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // cout << binary_search(v, 0, d, x);
    // cout<<firstOcc(v, d , x);
    // cout << lastOcc(v, d, x);
    // cout<<countOccurence(v,d,x);
    // cout << countOnes(v, d, x);
    // cout << sqrtNum(d);
    // cout << searchInfinite(v, x);
    // cout << searchInfiniteEff(v, d, x);
    // cout << searchSortedReverse(v, v.size(), x);
    // cout << getPeak(v, v.size());
    // cout << getPair(v, v.size(), x);
    sort(v.begin(), v.end());
    // cout << getPairPointer(v, v.size(), x);
    cout << getpairTriplet(v, v.size(), x);

    return 0;
}