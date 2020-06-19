
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vis;
// typedef pair< int ,int > pii;
// #define endl "\n"
// #define sd(val) scanf("%d",&val)
// #define ss(val) scanf("%s",&val)
// #define sl(val) scanf("%lld",&val)
// #define debug(val) printf("check%d\n",val)
#define all(v) v.begin(), v.end()
#define PB push_back
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

//operations of array - fixed array
// 1.deletion of an array
int *deleteEle(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
            break;
    }
    for (int j = i; j < n - 1; j++)
        arr[j] = arr[j + 1];
    return (arr);
}

int *reverseArray(int arr[], int low, int high)
{
    // int low = 0, high = n - 1;
    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
    return arr;
}

//remove duplicates from a sorteed array using naive solution- O(n) time and spce both

int remDups(int arr[], int n)
{
    int temp[n];
    temp[0] = arr[0];
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (temp[res - 1] != arr[i])
        {
            temp[res] = arr[i];
            res++;
        }
    }
    for (int i = 0; i < res; i++)
        arr[i] = temp[i];
    return res;
}

// time and spcae are O(n) ,O91
int remDupsef(int arr[], int n)
{
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[res - 1])
        {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}
//left rotation  in array by 1
int *lRotateOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
        arr[i - 1] = arr[i];
    arr[n - 1] = temp;
    return arr;
}

// for n th elements of left rotation by O(nd) ,O(n)

// Method -1 Naive Solution
int *leftrotate(int arr[], int n, int d)
{
    for (int i = 0; i < d; i++)
        lRotateOne(arr, n);
    return arr;
}

// Method 2 -Better - O(n),O(d)
int *leftrotatebetter(int arr[], int n, int d)
{
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = arr[i];
    for (int i = d; i < n; i++)
        arr[i - d] = arr[i];
    for (int i = 0; i < d; i++)
        arr[n - d + i] = temp[i];
    return arr;
}

//Method -3 Reversal Algorithm -O(n),O(1)

int *leftrotatebest(int arr[], int n, int d)
{
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
    return arr;
}

//leader of an array
//method 1 naive solution -O(n^2)

void leader(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            cout << arr[i] << " ";
    }
}

// method 2 better solution o(n)

void leaderbetter(int arr[], int n)
{
    int curr = arr[n - 1];
    cout << curr << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (curr < arr[i])
        {

            curr = arr[i];
            cout << curr << " ";
        }
        // else
        //     curr = arr[i];
    }
}

// Stock  buy and sell (Naive Solution) - O(n^2)

int maxProfit(int price[], int start, int end)
{
    if (end <= start)
        return 0;
    int profit = 0;
    for (int i = start; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (price[j] > price[i])
            {
                int curr_profit = price[j] - price[i] + maxProfit(price, start, i - 1) + maxProfit(price, j + 1, end);
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}
// its better solution u will find in dynamic arryay section that is solved by vector for practice at line 261
// from now on i mgoing to solve all the questions from vector

// in an dynamic array - vector

//1. remove duplicates from an vector - for first and last - O(1) for lmiddle - O(n)

vi remDupvec(vi v)
{
    sort(all(v));
    auto ip = v.erase(unique(all(v)), v.end());
    v.resize(distance(v.begin(), ip));
    return v;
}

// 2. left rotation by vector in O(n) average,first and last - O(1)
vi leftRotate(vi v, int d)
{
    rotate(v.begin(), v.begin() + d, v.end());
    return v;
}

// 3.leader
vi leader(vi v)
{
    vi res;
    int last = v.back();
    res.push_back(last);
    for (size_t i = v.size() - 1; i-- > 0;)
    {
        if (v[i] >= last)
        {
            last = v[i];
            res.push_back(last);
        }
    }
    reverse(all(res));
    return res;
}

// 4. Maximum Difference - Naive solution -O(n^2)

int maxdiff(vi v)
{
    int res = v[1] - v[0];
    for (auto i = 0; i < v.size() - 1; i++)
    {
        for (auto j = i + 1; j < v.size(); j++)
        {
            res = max(res, v[j] - v[i]);
        }
    }
    return res;
}

// better solution - O(n),O(1)

int maxdiffbetter(vi v)
{
    int res = v[1] - v[0], minval = v[0];
    for (auto i = 1; i < v.size(); i++)
    {
        res = max(res, v[i] - minval);
        minval = min(minval, v[i]);
    }
    return res;
}

// stock buy and sell (efficent solution) - O(n),O(1)
int maxProfit(vi v)
{
    int profit = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > v[i - 1])
        {
            profit += (v[i] - v[i - 1]);
        }
    }
    return profit;
}

// solving trapping rain water problem by brute force method -O(n^2)

int getWater(vi v)
{
    int res = 0, n = v.size();
    for (int i = 1; i < n - 1; i++)
    {
        int lmax = v[i];
        for (int j = 0; j < i; j++)
        {
            lmax = max(lmax, v[j]);
        }
        int rmax = v[i];
        for (int j = i + 1; j < n; j++)
        {
            rmax = max(rmax, v[j]);
        }
        res = res + (min(lmax, rmax) - v[i]);
    }
    return res;
}

// better solution of trapping with O(n)
int getWaterBetter(vi v)
{
    int res = 0, n = v.size();
    int rmax[n], lmax[n];
    lmax[0] = v[0];
    for (int i = 1; i < n; i++)
        lmax[i] = max(v[i], lmax[i - 1]);
    rmax[n - 1] = v[n - 1];
    for (size_t i = n - 2; i-- > 0;)
        rmax[i] = max(v[i], rmax[i + 1]);
    for (int i = 1; i < n - 1; i++)
        res = res + (min(lmax[i], rmax[i]) - v[i]);
    return res;
}

// Maximum consecutive ones Naive solution -O(n)

int maxConsecutiveOnes(vis v)
{
    int res = 0, n = v.size();
    int curr = 0;
    for (int i = 0; i < n; i++)
    {

        if (v[i] == 0)
            curr = 0;
        else
        {
            curr++;
            res = max(res, curr);
        }
    }
    return res;
}

// Kadane Algortihms maximum sum of subarray better sol O(n)
int maxSum(vi v)
{
    int n = v.size();
    int res = v[0], maxEnding = v[0];
    for (int i = 0; i < n; i++)
    {
        maxEnding = max(v[i], maxEnding + v[i]);
        res = max(res, maxEnding);
    }
    return res;
}

// maximum lengthn even odd subaaray beeter solution -O(n)
int maxeEveOddlength(vi v)
{
    int n = v.size(), res = 1, curr = 1;
    for (int i = 1; i < n; i++)
    {
        if ((v[i] % 2 == 0 && v[i - 1] % 2 != 0) || (v[i - 1] % 2 == 0 && v[i] % 2 != 0))
        {
            curr++;
            res = max(res, curr);
        }
        else
            curr = 1;
    }
    return res;
}

// Maximum circular subarray sum - O(n)

int maxCircularSum(vi v)
{
    int arr_sum = 0, n = v.size();
    int max_normal = maxSum(v);
    if (max_normal < 0)
        return max_normal;

    for (int i = 0; i < n; i++)
    {
        arr_sum += v[i];
        v[i] = -v[i];
    }
    int max_circular = arr_sum + maxSum(v);
    return max(max_normal, max_circular);
}

// majority element appear at n/2 times - O(n)
int majorityElement(vi v)
{
    int res = 0, n = v.size(), count = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[res] == v[i])
            count++;
        else
            count--;
        if (count == 0)
            res = i, count = 1;
    }
    count = 0;
    for (int i = 0; i < n; i++)
        if (v[res] == v[i])
            count++;
    if (count <= n / 2)
        res = -1;
    return res;
}

// window sliding techqnique - O(d)
int windowSliding(vi v, int k)
{
    int curr_sum = 0,n= v.size();
    for (int i = 0; i < k; i++)
        curr_sum += v[i];
    int max_sum = curr_sum;
    for (int i = k; i < n; i++)
    {
        curr_sum += v[i] - v[i - k];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main()
{
    FIO;
    OJ;
    // for fixed array
    int n, d;
    // cin >> n >> d;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    // // sort(arr,arr+n);
    // // cout << remDupsef(arr, n) << endl;
    // // int *ptr = deleteEle(arr, n, 12);
    // // int low = 0, high = n - 1;
    // // int *ptr = reverseArray(arr, low,high);
    // // int *ptr = lRotateOne(arr, n, d);
    // // int *ptr = leftrotate(arr, n, d);
    // // auto *ptr = leftrotatebetter(arr, n, d);
    // // auto *ptr = leftrotatebest(arr, n, d);
    // // leader(arr, n);
    // cout << maxProfit(arr,0,n-1) << " ";

    // leaderbetter(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout << ptr[i] << " ";

    // for dynamic array
    vi v;
    // vis v;
    cin >> d;
    while (cin >> n)
    {
        v.push_back(n);
    }
    for (auto i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // reverse(v.begin(), v.end());
    // auto res = remDupvec(v);
    // auto res = leftRotate(v, d);
    // auto res = leader(v);
    // auto res = maxdiff(v);
    // auto res = maxdiffbetter(v);
    // cout << res << " ";
    // cout << maxProfit(v) << " ";
    // cout << getWaterBetter(v) << " ";
    // cout << maxConsecutiveOnes(v) << " ";
    // cout << maxSum(v) << " ";
    // cout << maxCircularSum(v) << " ";
    // cout << maxeEveOddlength(v) << " ";
    // cout << majorityElement(v) << " ";
    cout << windowSliding(v, d) << " ";
    // for (auto i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }

    return 0;
}