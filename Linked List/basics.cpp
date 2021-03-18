#include <bits/stdc++.h>
using namespace std;

// typedef vector <int> vi;
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

// * Singly Linked list
//  * Diadvantagees  - no cachfriendliness ,no a random access
//  * advantages - no wastage of space,insertion - O(1),deleyion after is O(1)

//  * Doubly Lisnked List
//  * Delete a given node in O(1)
//  * Traversal backward
//  * insert before in O(1)

struct Node
{
    int key;
    Node *next;
    Node(int x)
    {
        key = x;
        next = NULL;
    }
};

struct Llist
{
    Node *head, *tail;
    Llist() { head = NULL; }

    void insertAtBegin(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        if(tail == NULL){
            tail = head;
        }
    }
};

int main()
{
    FIO;
    OJ;
    Llist ll;
    int x;
    cin>>x;
    ll.insertAtBegin(x);

    return 0;
}
