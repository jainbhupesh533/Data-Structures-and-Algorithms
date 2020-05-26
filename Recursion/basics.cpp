
#include <bits/stdc++.h>
using namespace std;

// typedef vector <int> vi;
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

int recursion(int n)
{
    if (n = 0)
        return 1;
    else
        return n * recursion(n - 1);
}

// tail recursion - it means we dont have anything to call after the recursive function
int factorial(int n, int k = 1)
{
    if (n == 0)
        return k;
    else
        return factorial(n - 1, k * n);
}

//string palindrome checker
bool isPal(string str, int s, int e)
{
    if (s >= e)
        return true;
    if (str[s] != str[e])
        return false;
    return isPal(str, s + 1, e - 1);
}

// fibonacii number
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// sum of a digits

int sum(int n)
{
    if (n < 10)
        return n;
    return sum(n / 10) + n % 10;
}

// rope length set question - O(3^n)

int rodCutting(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;
    int res = max(max(rodCutting(n - a, a, b, c), rodCutting(n - b, a, b, c)),
                  rodCutting(n - c, a, b, c));

    if (res == -1)
        return -1;
    return 1 + res;
}

//powerset for string using recursion - O(2^n)

void powerset(string str, int index = 0, string cur = "")
{
    int n = str.length();
    if (index == n)
    {
        cout << cur << endl;
        return;
    }
    powerset(str, index + 1, cur + str[index]);
    powerset(str, index + 1, cur);
}

//tower of hanoi peroblem
void TOH(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << "Move 1 from " << A << "to " << C << endl;
        return;
    }
    TOH(n - 1, A, C, B);
    cout << "move " << n << " from " << A << "to " << C << endl;
    TOH(n - 1, B, A, C);
}

//Josephus Problem - O(n)
int jos(int n, int k)
{
    if (n == 1)
        return 0;
    else
        return (jos(n - 1, k) + k) % n;
}
//if that above problem starts with 1 then we have to had to solve this
int myjos(int n, int k)
{
    return jos(n, k) + 1;
}

//subset sum problem  - theta(2^n)
int subset(int arr[],int n,int sum){
    if(n==0)
        return (sum == 0)? 1:0;
    return subset(arr,n-1,sum) + subset(arr,n-1,sum-arr[n-1]);
}

int main()
{
    FIO;
    OJ;
    // string s;
    // cin >> s;
    int n, a, b, c, k;
    cin >> n >> k;
    // cin >> n >> a >> b >> c;
    //ex - 25 13 9 12 rodcutting
    //  factorial number using reursion
    //  cout<<recursion(n);
    //  cout<<factorial(n);
    // cout << isPal(s, n, e);
    // cout<<fib(n);
    // cout<<sum(n);
    // cout << rodCutting(n, a, b, c);
    // powerset(s);
    // TOH(n, 'A', 'B', 'C');
    cout << jos(n, k);
    return 0;
}