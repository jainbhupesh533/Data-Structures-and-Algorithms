
#include <bits/stdc++.h>
using namespace std;

#define OJ                                    \
    freopen("checkup/input.txt", "r", stdin); \
    freopen("checkup/output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

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

void create()
{
    int info;
    cout << "Enter Info part:" << endl;
    cin >> info;
    Node *p = new Node(info);
    if (start == NULL)
    {
        start = p;
        p->next = start;
    }
    else
    {
        Node *q = start;
        while (q->next != start)
        {
            q = q->next;
        }
        q->next = p;
        p->next = start;
    }
}

void display()
{
    Node *curr = start;
    do
    {
        cout << curr->key << endl;
        curr = curr->next;
    } while (curr != start);
}

void insert()
{
    int item, pos, k = 2;
    Node *prev, *curr, *n1;
    cout << "Enter the position: " << endl;
    cin >> pos;
    cout << "Enter the value: " << endl;
    cin >> item;
    Node *avail = new Node(item);
    if (avail == NULL)
    {
        exit(0);
    }
    else
    {
        n1 = avail;
        prev = start;
        curr = start->next;
        if (pos == 1)
        {
            n1->next = avail;
            start = n1;
        }
        while ((curr != start) && (k < pos))
        {
            k += 1;
            prev = curr;
            curr = curr->next;
        }
        if (curr == start)
        {
            prev->next = n1;
            n1->next = start;
        }
        else
        {
            n1->next = curr;
            prev->next = n1;
        }
    }
}

void delete1()
{
    struct Node *ptr;
    struct Node *ptrp;
    // struct node * avail = new node;
    struct Node *old;
    int item;
    cout << "Enter the elements you want to delete: " << endl;
    cin >> item;
    if (start == NULL)
    {
        cout << "Underflow" << endl;
    }
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
            while ((ptr != start) && (ptr->key != item))
            {
                ptrp = ptr;
                ptr = ptr->next;
            }
            if (ptr == start)
            {
                cout << "Deletion not possible" << endl;
                exit(1);
            }
            else
            {
                old = ptr;
                ptrp->next = ptr->next;
            }
        }
    }
}

void search() {}
int main()
{
    FIO;
    int ch;
    cout << "\t\t ENTER THE CHOICES FOR THE LINKED LIST " << endl;
    cout << "PRESS 1 FOR CREATING LINK LIST" << endl;
    cout << "PRESS 2 FOR DISLAYING LINK LIST" << endl;
    cout << "PRESS 3 FOR INSERTING VALUES IN LINKED LIST" << endl;
    cout << "PRESS 3 FOR DELETING VALUES IN LINKED LIST" << endl;
    cout << "PRESS 4 FOR SEARCHING VALUES IN LINKED LIST" << endl;
    do
    {
        cout << "Enter the choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete1();
            break;
        case 5:
            search();
            break;

        default:
            break;
        }
    } while ((ch == 1) || (ch == 2) || (ch == 3) || (ch == 4) || (ch == 5));
    return 0;
}