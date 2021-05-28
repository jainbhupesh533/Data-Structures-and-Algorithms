
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
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct Node *start = NULL;
int size = 0;

void create()
{
    int info;
    cout << "Enter the value: " << endl;
    cin >> info;
    Node *curr = new Node(info);
    if (start == NULL)
    {
        start = curr;
        // curr->next = start;
        // start->prev = curr;
    }
    else
    {
        Node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = curr;
        curr->prev = temp;
    }
    size++;
}

void display()
{
    Node *k = start;
    while (k != NULL)
    {
        cout << k->prev << "\n"
             << k->data << "\n"
             << k->next << "\n"
             << "--->"
             << "\n";
        k = k->next;
    }
}

void insertFirst()
{
    int item;
    cout << "Enter the value for inserting: ";
    cin >> item;
    Node *avail = new Node(item);
    if (avail == NULL)
    {
        cout << "Overflow and exiting" << endl;
        exit(0);
    }
    else
    {
        avail->next = start;
        start->prev = avail;
        start = avail;
        size++;
    }
}

void insertMid()
{
    Node *curr = start, *temp = NULL;
    int mid = (size % 2 == 0) ? (size / 2) : ((size + 1 / 2));
    int item;
    cout << "Enter the value for inserting: " << endl;
    cin >> item;
    Node *avail = new Node(item);
    if (avail == NULL)
    {
        cout << "Overflow and exiting" << endl;
        exit(0);
    }
    else
    {
        for (int i = 1; i < mid; i++)
            curr = curr->next;
        temp = curr->next;
        curr->prev = temp;
        curr->next = avail;
        avail->prev = curr;
        avail->next = temp;
        temp->prev = avail;
        size++;

        //? Without using temporary
        //  avail->next = curr->next;
        // curr->next->prev = avail;
        // avail->prev = curr;
        // curr->next = avail;
    }
}

void insertPos()
{
    int item, pos, k = 2;
    Node *curr = start;
    cout << "Enter the value for inserting: " << endl;
    cin >> item;
    cout << "Enter the position: " << endl;
    cin >> pos;
    Node *avail = new Node(item);
    if (avail == NULL)
    {
        cout << "overflow" << endl;
        exit(0);
    }
    else
    {
        if (pos == 1)
        {
            avail->next = curr;
            curr->prev = avail;
            curr = avail;
            size++;
        }
        else
        {
            while ((curr->next != NULL) && (k < pos))
            {
                k++;
                curr = curr->next;
            }
            avail->next = curr->next;
            curr->next->prev = avail;
            curr->next  = avail;
            avail->prev = curr;
            size++;
        }
    }
}

void insertLast() {
    int item;
    cout << "Enter the value for inserting: ";
    cin >> item;
    Node *avail = new Node(item);
    Node * curr = start ;
    if (avail == NULL)
    {
        cout << "Overflow and exiting" << endl;
        exit(0);
    }else{
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = avail;
        avail->prev = curr;
        
    }
}

void searchLL() {}

int main()
{
    FIO;
    int ch, i;
    cout << "\t\t ENTER THE CHOICES FOR THE LINKED LIST " << endl;
    cout << "PRESS 1 FOR CREATING LINK LIST" << endl;
    cout << "PRESS 2 FOR DISLAYING LINK LIST" << endl;
    cout << "PRESS 3 FOR SEARCHING VALUES IN LINKED LIST" << endl;
    cout << "PRESS 4 FOR INSERTING VALUES IN LINKED LIST" << endl;
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
            searchLL();
            break;
        case 4:
            cout << "PRESS 1 FOR INSERT VALUE AT FIRST POSITION" << endl;
            cout << "PRESS 2 FOR INSERT VALUE MID  POSITION" << endl;
            cout << "PRESS 3 FOR INSERT VALUE AT LAST  POSITION" << endl;
            cout << "PRESS 4 FOR INSERT VALUE AT RANDOM POSITION POSITION" << endl;
            cin >> i;
            switch (i)
            {
            case 1:
                insertFirst();
                break;
            case 2:
                insertMid();
                break;
            case 3:
                insertLast();
                break;
            case 4:
                insertPos();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    } while ((ch == 1) || (ch == 2) || (ch == 3) || (ch == 4));

    return 0;
}