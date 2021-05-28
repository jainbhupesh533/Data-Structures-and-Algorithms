#include <bits/stdc++.h>
using namespace std;

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
struct Node *start = NULL;

int create()
{
    int x;
    cout << "Enter The value: " << endl;
    cin >> x;
    Node *p = new Node(x);
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        Node *q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    return 1;
}

void display()
{
    struct Node *k = start;
    while (k != NULL)
    {
        cout << k << "\n"
             << k->key << "\n"
             << k->next << "\n"
             << "--->"
             << "\n";
        k = k->next;
    }
}

void recursiveDisplay(Node *k)
{
    // struct Node * k = start;
    if (k == NULL)
        return;

    cout << k->key << " ";
    recursiveDisplay(k->next);
    cout << endl;
}

void insert()
{
    struct Node *ptr;
    struct Node *ptrp;
    struct Node *n1;
    int item, pos, k = 2;
    cout << "Enter the Postion" << endl;
    cin >> pos;
    cout << "Enter the item" << endl;
    cin >> item;
    struct Node *avail = new Node(item);
    if (avail == NULL)
    {
        cout << "OverFlow" << endl;
        exit(0);
    }
    else
    {
        n1 = avail;
        avail = avail->next;

        // inserting at position 1
        if (pos == 1)
        {
            n1->next = start;
            start = n1;
        }
        else
        {
            ptr = start->next;
            ptrp = start;
            while ((ptr != NULL) && (k < pos))
            {
                k += 1;
                ptrp = ptr;
                ptr = ptr->next;
            }
            // inserting value at end
            if (ptr == NULL)
                ptrp->next = n1;
            // inserting value at mid
            else
            {
                n1->next = ptr;
                ptrp->next = n1;
            }
        }
    }
}

void delete1()
{
    struct Node *ptr;
    struct Node *ptrp;
    struct Node *old;
    int item;
    cout << "Enter the elements you want to delete: " << endl;
    cin >> item;
    struct Node *avail = new Node(item);
    if (start == NULL)
        exit(0);
    else
    {
        if (start->key == item)
        {
            old = start;
            start = start->next;
        }
        else
        {
            ptr = start->next;
            ptrp = start;
            while ((ptr != NULL) && (ptr->key != item))
            {
                ptrp = ptr;
                ptr = ptr->next;
            }
            if (ptr == NULL)
                exit(1);
            else
            {
                old = ptr;
                ptrp->next = ptr->next;
            }
        }
    }
    old->next = avail;
    avail = old;
}

int main()
{
    FIO;
    // OJ;
    int ch;
    do
    {
        cout << "Enter the choice: " << endl;
        cin >> ch;
        if (ch == 1)
        {
            create();
        }
        else if (ch == 2)
        {
            display();
        }
        else if (ch == 3)
        {
            insert();
        }
        else if (ch == 4)
        {
            recursiveDisplay(start);
        }
        else if (ch == 5)
        {
            delete1();
        }
    } while ((ch == 1) || (ch == 2) || (ch == 3) || (ch == 4) || (ch == 5));
    return 0;
}
