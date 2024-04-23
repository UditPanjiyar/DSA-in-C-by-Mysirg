#include <iostream>
using namespace std;

class array
{
private:
    int capacity;
    int lastindex;
    int *ptr;

public:
    array();
    array(array &c); // copy constructor
    void createarray(int cap);
    void insert(int index, int value);
    void append(int data);
    void getitem(int index);
    int isEmpty();
    int isFull();
    void del(int index);
    void getCapacity();
    void count();
    void edit(int index, int newdata);
    void display();
    int search(int data);
    ~array(); // destructor
};
array::array(array &c)  //copy constructor for deep copy
{
    capacity = c.capacity;
    lastindex = c.lastindex;
    ptr = new int[capacity];
    for (int i = 0; i <= lastindex; i++)
    {
        ptr[i] = c.ptr[i];
    }
}
array::array()
{
    ptr = NULL;
}
array::~array()
{
    delete[] ptr;
}

void array::display()
{
    for (int i = 0; i <= lastindex; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}

void array::createarray(int cap)
{
    capacity = cap;
    if (ptr != NULL)
    {
        delete[] ptr; // prevent memory leak
    }
    lastindex = -1;
    ptr = new int[capacity];
}

int array::isFull()
{
    if (lastindex == capacity - 1)
    {
        return 1;
    }
}

int array::isEmpty()
{
    if (lastindex == -1)
    {
        return 1;
    }
}

void array::append(int data)
{
    if (isFull() != 1)
    {
        lastindex++;
        ptr[lastindex] = data;
    }
}

void array::insert(int index, int value)
{
    int i;
    if (isFull() == 1)
    {
        cout << "overload" << endl;
    }

    if (index > lastindex + 1 || index < 0)
    {
        cout << "invalid index" << endl;
    }

    else
    {
        for (i = lastindex; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = value;
        lastindex++;
    }
}

void array::getitem(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "invalid index" << endl;
    }
    else
    {
        cout << ptr[index] << endl;
    }
}
void array::getCapacity()
{
    cout << capacity << endl;
}
void array::count()
{
    cout << lastindex + 1 << endl;
}

void array::edit(int index, int newdata)
{
    if (index < 0 || index > lastindex)
    {
        cout << "invalid index" << endl;
    }
    else
    {
        ptr[index] = newdata;
    }
}
void array::del(int index)
{
    if (index < 0 || index > lastindex)
    {
        cout << "invalid index" << endl;
    }
    else
    {
        for (int i = index; i < lastindex; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        lastindex--;
    }
}

int array::search(int data)
{
    for (int i = 0; i <= lastindex; i++)
    {
        if (ptr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    array obj1;
    obj1.createarray(15);

    for (int i = 0; i < 5; i++)
    {
        obj1.append(i + 1);
    }

    obj1.display();

    // obj1.insert(2, 10);
    // obj1.display();

    // obj1.del(2);
    // obj1.display();

    // obj1.getCapacity();

    // obj1.count();

    // obj1.getitem(0);

    array obj2 = obj1;
    obj2.display();
    obj1.~array(); // calling distructor
    obj2.append(6);
    obj2.display();
    // obj1.display();

    // int pos=obj1.search(4);
    // cout<<pos;



    obj2.~array(); // calling distructor
    return 0;
}