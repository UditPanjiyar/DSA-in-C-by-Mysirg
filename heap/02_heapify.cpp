#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left < n && arr[largest]<arr[left])
    {
        largest = left;
    }
    if(right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }




}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {54,53,55,52,50,10,95,25,70};
    int n= sizeof(arr)/sizeof(arr[0]);
    print(arr,n);

    for(int i=(n/2)-1; i>=0; i--)
    {
        heapify(arr,n,i);
    }

    print(arr,n);
    
    return 0;
}