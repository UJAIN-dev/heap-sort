#include <iostream>
#include <vector>
using namespace std;

typedef vector <int> vec;

void heapifyCTR(vec arr, int index)
{
    int child = index;
    int parent = (child-1)/2;
    while (child != 0)
    {
        if(arr[child] > arr[parent])
        {
            swap(arr[child], arr[parent]);
        }
        child = parent;
        parent = (child-1)/2;
    }
}

void heapifyRTC(vec arr, int root)
{
    int l = 2*root+1;
    int r = 2*root+2;

    while (r < arr.size())
    {
        int larger = arr[l] > arr[r] ? l : r;
        if (arr[root] < arr[larger])
        {
            swap(arr[root], arr[larger]);
        }
        root = larger;
        l = 2*root+1;
        r = 2*root+2;
    }
}

void insert(vec arr, int val)
{
    arr.push_back(val);
    heapifyCTR(arr, arr.size() - 1);
}

void deleteRoot(vec &arr, int root)
{
    arr[0] = *arr.end();
    arr.pop_back();
    heapifyRTC(arr, root);
}

void printArray(vec arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
    vec arr = { 12, 7, 5, 4, 6};


    deleteRoot(arr, arr.size());
    printArray(arr, arr.size());
    deleteRoot(arr, arr.size());
    printArray(arr, arr.size());
    deleteRoot(arr, arr.size());
    printArray(arr, arr.size());
    deleteRoot(arr, arr.size());
    printArray(arr, arr.size());
    
    return 0;
}