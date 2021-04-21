
#include <bits/stdc++.h>
using namespace std;

typedef unordered_map<char, int> u_map;
// typedef vector <int> vi;
// typedef vector <bool> vib;
// typedef vector <string> vis;
// typedef pair< int ,int > pii;
#define endl "\n"
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

const int CHAR = 256;

// * Frequency of a string
void frequencies(string str)
{
    int count[26] = {0};
    for (int i = 0; i < str.length(); i++)
        count[str[i] - 'a']++;
    for (int i = 0; i < 26; i++)
        if (count[i] > 0)
            cout << char(i + 'a') << ": " << count[i] << endl;
}

// * Palindrome in the string -NaiveMethod -θ(n),θ(n)
bool isPalNaive(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return (rev == str);
}

// * O(n),O(1)
string isPalEff(string str)
{
    int beg = 0, flag = 0, end = str.length() - 1;
    while (beg < end)
    {
        if (str[beg] != str[end])
        {
            flag = -1;
            break;
        }
        beg++;
        end--;
    }
    if (flag != -1)
    {
        sort(str.begin(), str.end());
    }
    else
    {
        str = -1;
    }
    // swap(str, str.begin());
    return (str);
}

// * O(n+m) O(1) subsquesnce
bool isSubSeq(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    int j = 0;
    for (int i = 0; i < n && j < m; i++)
    {
        if (str1[i] == str2[j])
            j++;
    }
    return (j == m);
}

// * Anagram of string using map
bool anagram(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    u_map dict;
    if (n != m)
        return false;
    for (int i = 0; i < n; i++)
        dict[str1[i]]++;
    for (int i = 0; i < m; i++)
    {
        if (dict.find(str2[i]) == dict.end())
            return false;
        else
        {
            dict[str2[i]]--;
            if (dict[str2[i]] == 0)
                dict.erase(str2[i]);
        }
    }
    return (dict.size() == 0);
}

int leftMostRepeatCharacter(string str1)
{
    int n = str1.length();
    u_map dict;
    for (int i = 0; i < n; i++)
        dict[str1[i]]++;
    for (int i = 0; i < n; i++)
        if (dict[str1[i]] > 1)
            return i;
    return -1;
}

// * Effeicient approach without using hashmap or map function - O(n)

int leftMostRepeatCharacterEff(string str1)
{
    bool visited[256];
    fill(visited, visited + 256, false);
    int res = -1;
    for (int i = str1.length() - 1; i >= 0; i--)
    {
        if (visited[str1[i]] == false)
            visited[str1[i]] = true;
        else
            res = i;
    }
    return res;
}

int nonRepeatingCharacter(string str1)
{
    int n = str1.length();
    u_map dict;
    for (int i = 0; i < n; i++)
        dict[str1[i]]++;
    for (int i = 0; i < n; i++)
        if (dict[str1[i]] == 1)
            return i;
    return -1;
}

// * effecient solution using one traversal for nonrepeating character θ(n+char),O(char) without using hashmap
int nonRepeatingCharacterEff(string str1)
{
    int temp[CHAR];
    int res = INT_MAX;
    fill(temp, temp + CHAR, -1);
    for (int i = 0; i < str1.length(); i++)
    {
        if (temp[str1[i]] == -1)
            temp[str1[i]] = i;
        else
            temp[str1[i]] = -2;
    }
    for (int i = 0; i < CHAR; i++)
        if (temp[i] >= 0)
            res = min(res, temp[i]);
    return (res == INT_MAX) ? -1 : res;
}

// * reverse words in a string O(n),O(1) with using external reverse function

void reversed(string &s, int low, int high)
{
    while (low < high)
    {
        swap(s[low], s[high]);
        low++;
        high--;
    }
}

string reverseWordString(string str1)
{
    str1.insert(str1.end(), ' ');
    int len = str1.length();
    int start = 0;
    for (int end = 0; end < len; end++)
    {
        if (str1[end] == ' ')
        {
            reversed(str1, start, end - 1);
            start = end + 1;
        }
    }
    str1.pop_back();
    reversed(str1, 0, str1.length() - 1);
    return str1;
}

int main()
{
    FIO;
    OJ;
    string str1, str2;
    // cin >> str1;
    getline(cin, str1);
    // cout<<str1<<endl;
    // cin >> str1 >> str2;

    // frequencies(str1);
    // cout << isPalNaive(str1);
    // cout << isPalEff(str1);
    // cout << isSubSeq(str1, str2) << endl;
    // cout << anagram(str1, str2) << endl;
    // cout << leftMostRepeatCharacter(str1) << endl;
    // cout << leftMostRepeatCharacterEff(str1) << endl;
    // cout << nonRepeatingCharacter(str1) << endl;
    // cout << nonRepeatingCharacterEff(str1) << endl;
    cout << reverseWordString(str1) << endl;
    return 0;
}