
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> dv;
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
#define ll long long
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

// * Double Pointers , not usable due to flaws in cache

void multiArrayPointers()
{
    int m = 3, n = 2;
    int **arr;
    arr = new int *[m];
    for (int i = 0; i < m; i++)
        arr[i] = new int[n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
            arr[i][j] = 10;
            cout << arr[i][j] << " ";
        }
    }
}

//  * Array of pointers

void arrayOfPointers()
{
    int m = 3, n = 2;
    int *arr[m];
    for (int i = 0; i < m; i++)
        arr[i] = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 10;
            cout << arr[i][j] << ' ';
        }
}

// * Array of vectors
// ! not a cache freiendly
// ? Individual rows are of dynamic rows
// ? Easy to pass

void arrayOfVectors()
{
    int m = 3, n = 2;
    vi v[m];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            v[i].push_back(10);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cout << v[i][j] << " ";

    cout << endl;
}

// * Vectors of Vectors
// ! not a cache friendly
// ? easy to pass in functions
// ? Number of rows can also be dynamic

void doublyVectors()
{
    dv arr;
    int m = 3, n = 2;
    for (int i = 0; i < m; i++)
    {
        vi v;
        for (int j = 0; j < n; j++)
            v.push_back(10);
        arr.push_back(v);
    }

    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << ' ';
    cout << endl;
}

// * passing 2d array as an arguement
// ! this method always static

// const int r = 4;
// const int c = 4;
// void print2DArray(int mat[r][c])
// {
//     for (int i = 0; i < r; i++)
//         for (int j = 0; j < c; j++)
//             cout << mat[i][j] << " ";
//     cout << endl;
// }

// // ? Double pointer matrix

void print2DArrayPoint(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << ' ';
    cout << endl;
}

// ? using arry to pointer

void pointerArray(int *arr[], int m, int n) {}

// ? using array to vector

void printVector(vector<int> arr[], int m) {}

// ? using vectors to vectors

void printVectorVec(vector<vector<int>> &arr) {}

// * print a matrix in a snake pattern
// O(r*c)
// void printSnake(int mat[r][c])
// {
//     for (int i = 0; i < r; i++)
//     {
//         if (i % 2 == 0)
//         {
//             for (int j = 0; j < c; j++)
//                 cout << mat[i][j] << " ";
//         }
//         else
//         {
//             for (int j = c - 1; j >= 0; j--)
//                 cout << mat[i][j] << " ";
//         }
//     }
//     cout << endl;
// }

// * print bo=undary taraversal
void printBoundaryTraversal(int *arr[], int r, int c)
// θ(r+c) time complexity
{
    if (r == 1)
    {
        for (int i = 0; i < c; i++)
            cout << arr[0][i] << " ";
    }
    else if (c == 1)
    {
        for (int i = 0; i < r; i++)
            cout << arr[i][0] << " ";
    }
    else
    {
        for (int i = 0; i < c; i++)
            cout << arr[0][i] << " ";
        for (int i = 1; i < r; i++)
            cout << arr[i][c - 1] << " ";
        for (int i = c - 2; i >= 0; i--)
            cout << arr[r - 1][i] << " ";
        for (int i = r - 2; i >= 1; i--)
            cout << arr[i][0] << " ";
    }
}

void displayMatrix(int *arr[], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// *Print Transpose of Matrix

void printMatrixTranspose(int *arr[], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    // displayMatrix(arr,r,c);
}
// Naive Method  -O(n*n) ,O(n*n)
// * Rotate MAtrix by 90
void rotateMatrixNaive(int *arr[], int r, int c)
{
    int temp[r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            temp[c - j - 1][i] = arr[i][j];
        }
    }

    displayMatrix(arr, r, c);
}

void rotateMatrixEff(int *arr[], int r, int c)
{
    printMatrixTranspose(arr, r, c);
    for (int i = 0; i < r; i++)
    {
        int low = 0, high = r - 1;
        while (low < high)
        {
            swap(arr[low][i], arr[high][i]);
            low++;
            high--;
        }
    }
    displayMatrix(arr, r, c);
}

// O(r*c)
void spiralMatrix(int *arr[], int r, int c)
{
    int top = 0, right = c - 1, left = 0, bottom = r - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            cout << arr[top][i] << " ";
        top++;
        for (int i = top; i <= bottom; i++)
            cout << arr[i][right] << " ";
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                cout << arr[bottom][i] << " ";
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                cout << arr[i][left] << " ";
            left++;
        }
    }
}


// O(r+c)
void sortedMatrix(int *arr[], int r, int c, int key)
{
    int i = 0, j = c - 1;
    bool flag = 0;
    while (i < r && j >= 0)
    {
        if (arr[i][j] == key)
        {
            cout << "(" << i << "," << j << ")" << endl;
            flag = 1;
            return;
        }
        else if (arr[i][j] > key)
        {
            j--;
        }
        else
            i++;
    }
    if (!flag)
        cout << "Not Found" << endl;
}

int main()
{
    FIO;
    OJ;
    // * therw are many ways to create thee multidimension aaray
    // ? first one is double pointer araay
    // multiArrayPointers();
    // arrayOfPointers();
    // arrayOfVectors();
    // doublyVectors();

    // * passing array to function
    // int mat[r][c];
    // for (int i = 0; i < r; i++)
    //     for (int j = 0; j < c; j++)
    //         cin >> mat[i][j];
    int m, n, key;
    cin >> m >> n;

    int *arr[m];

    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];

        for (int j = 0; j < n; j++)
        {

            cin >> arr[i][j];
        }
    }

    // print2DArray(mat);
    // printSnake(mat);
    // printBoundaryTraversal(arr, m, n);
    // printMatrixTranspose(arr, m, n);
    // rotateMatrixNaive(arr, m, n);
    // rotateMatrixEff(arr, m, n);
    // spiralMatrix(arr, m, n);
    // cin >> key;
    // sortedMatrix(arr, m, n, key);
    cout << endl;
    return 0;
}