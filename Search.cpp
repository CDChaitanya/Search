#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}

int main()
{
    int n,x;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements of the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nEnter a number to be searched : ";
    cin>>x;

    cout<<"\nLinear Search"<<endl;;
    int result = search(arr, n, x);
       (result == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<result;

    cout<<endl;

    cout<<"\nBinary Search"<<endl;
    int answer = binarySearch(arr, 0, n - 1, x);
       (answer == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<answer;

    cout<<endl;

    return 0;

   }

