#include <iostream>
using namespace std;

class heap
{
public:
    int size;
    int capacity;
    int *arr;

    heap(int);
    void insert(int);
    void del();
    void print(int *, int);
};

heap::heap(int cap)
{
    size = -1;
    capacity = cap;
    arr = new int[capacity];
}
void heap::insert(int data)
{
    size = size + 1;
    int i = size; // i=index
    arr[i] = data;

    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (arr[parent] < arr[i])
        {
            swap(arr[i], arr[parent]);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

void heap::del()
{
    // deletion in heap means delete root element i.e element at 0 index
    if(size==-1)
        cout<<"Nothing to delete Maxheap is empty";
    arr[0] = arr[size];
    size--;

    int i = 0;
    while (i < size)
    {
        int leftChild = (2 * i) + 1;
        int rightChild = (2 * i) + 2;
        if (leftChild < size && arr[i] < arr[leftChild])
        {
            swap(arr[leftChild], arr[i]);
            i = leftChild;
        }
        else if (rightChild < size && arr[i] < arr[rightChild])
        {
            swap(arr[rightChild], arr[i]);
            i=rightChild;
        }
        else
        {
            break;
            //return;
        }
    }
    
}
void heap::print(int *arr, int size)
{
    for (int i = 0; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    heap h(100);

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print(h.arr, h.size);

    h.del();
 
    h.print(h.arr,h.size);

    return 0;
}