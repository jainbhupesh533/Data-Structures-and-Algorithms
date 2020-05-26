
#include <bits/stdc++.h>
using namespace std;

int counter = 2;
// typedef vector <int> vi;
typedef vector<string> vs;
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
#define ll long long
#define MOD 1000000007
// #define clr(val) memset(val,0,sizeof(val))
// #define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                                       \
    freopen("../checkup/input.txt", "r", stdin); \
    freopen("../checkup/output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// Main progerams

//complete reverse a number
ll rev(ll n)
{
    ll num = 0;
    while (n > 0)
    {
        num = num * 10 + n % 10;
        n = n / 10;
    }
    return num;
}

//loops print 1 to n
void printNos(int N)
{
    //Your code here
    if (N > 0)
    {
        printNos(N - 1);
        cout << N << " ";
    }
    return;
}
//find the sum of digits
int sumofDigits(int n)
{
    return n < 10 ? n : n % 10 + sumofDigits(n / 10);
}

//find the coutn of digits
int countDigits(int n)
{
    //Your code here
    return n < 10 ? 1 : 1 + countDigits(n / 10);
}

//find the sum root of digits
int digitalRoot(int n)
{
    //Your code here
    return n < 10 ? n : digitalRoot(sumofDigits(n));
}

long long fibonacci(int n)
{
    //Your code here
    return (n == 1 | n == 2) ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

// avoid space at the starting of the string in "move disk....."
void toh(int N, int from, int to, int aux, long long &moves)
{
    // Your code here
    if (N == 1)
    {
        cout << "move disk 1 from rod " << from << " to rod " << to << endl;
        moves++;
        return;
    }
    toh(N - 1, from, aux, to, moves);
    cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
    moves++;
    toh(N - 1, aux, to, from, moves);
}

//lucky number
bool isLucky(int n)
{
    if (counter > n)
        return 1;
    if (n % counter == 0)
        return 0;
    int next_pos = n;
    next_pos = next_pos - next_pos / counter;
    counter++;
    return isLucky(next_pos);
}

//joshepus problem
int josephus(int n, int k)
{
    return n == 1 ? 1 : (josephus(n - 1, k) + k - 1) % n + 1;
}

// power of a number
int recursivePower(int n, int p)
{
    return p == 0 ? 1 : n * recursivePower(n, p - 1);
}

// revcerse power of a no
long long power(int N, int R)
{
    return R == 0 ? 1 : (N * power(N, --R)) % MOD;
}

//power set using recursion
void getAllSet(string s, int ind, string curr, vector<string> &v)
{
    if (ind == s.length())
    {
        v.push_back(curr);
        return;
    }

    getAllSet(s, ind + 1, curr, v);
    getAllSet(s, ind + 1, curr + s[ind], v);
}
vector<string> powerSet(string s)
{
    vector<string> v;
    getAllSet(s, 0, "", v);
    return v;
}

//possible words from phone digits - O(4^n)
void printWords(vector<string> v, int curr, string s)
{
    if (curr == v.size())
    {
        cout << s << " ";
        return;
    }
    string st = v[curr];
    for (int i = 0; i < st.size(); i++)
        printWords(v, curr + 1, s + st[i]);
}
void possibleWords(int arr[], int n)
{
    string words[] = {"", "", "abc", "def", "ghi", "jkl", "mno",
                      "pqrs", "tuv", "wxyz"};

    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(words[arr[i]]);
    }

    printWords(v, 0, "");
}

int main()
{
    FIO;
    OJ;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        // printNos(n);
        // cout<<sumofDigits(n) << endl;
        //cout<<countDigits(n) << endl;
        // cout << digitalRoot(n) << endl;
        // if (isLucky(n))
        //     cout << true << endl;
        // else
        //     cout << false << endl;
        // counter = 2;
        //  cin>>n>>k;
        // cout<<josephus(n,k)<<endl;
        // cout<<recursivePower(n,k)<<endl;
        // cout << power(n, rev(n)) << endl;
        //for powerset
        // string s;
        // cin >> s;
        // vs ans = powerSet(s);
        // sort(ans.begin(), ans.end());
        // for (auto x : ans)
        //     cout << x << " ";
        // cout << endl;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        possibleWords(a, n);
        cout << endl;
    }

    return 0;
}