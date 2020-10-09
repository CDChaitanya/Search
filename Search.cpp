#include <bits/stdc++.h>
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

int sentinelSearch(int arr[], int n, int x)
{
    int last = arr[n - 1];

    arr[n - 1] = x;
    int i = 0;

    while (arr[i] != x)
        i++;

    arr[n - 1] = last;

    if ((i < n - 1) || (x == arr[n - 1]))
        return i;
    return -1;
}

int min(int x, int y)
{
     return (x<=y)? x : y;
}

int fibonacciSearch(int arr[], int x, int n)
{
   int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;


    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset+fibMMm2, n-1);

        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (arr[i] > x)
        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        else return i;
    }

    if(fibMMm1 && arr[offset+1]==x)return offset+1;

    return -1;

}

int jumpSearch(int arr[], int x, int n)
{
    int step = sqrt(n);

    int prev = 0;
    while (arr[min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;

        if (prev == min(step, n))
            return -1;
    }
    if (arr[prev] == x)
        return prev;

    return -1;
}


int main()
{
    char reply;
    do
    {
    int n,x;
    cout<<"\nEnter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements of the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nEnter a number to be searched : ";
    cin>>x;

    int choice,result,answer,solution,response,select;

    cout<<"\nEnter which Search you want"<<endl;
    cout<<"1.Linear Search"<<endl;
    cout<<"2.Binary Search"<<endl;
    cout<<"3.Sentinel Search"<<endl;
    cout<<"4.Fibonacci Search"<<endl;
    cout<<"5.Jump Search"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:

    result = search(arr, n, x);
       (result == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<result;

                 break;

    case 2:

    answer = binarySearch(arr, 0, n - 1, x);
       (answer == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<answer;

                 break;

    case 3:

    solution = sentinelSearch(arr, n, x);
       (solution == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<solution;

                 break;

    case 4:

    response = fibonacciSearch(arr, x, n);
        (response == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<response;

                break;

    case 5:

    select = jumpSearch(arr, x, n);
        (select == -1)? cout<<"Element is not present in array"
                 : cout<<"Element is present at index " <<select;

                 break;

   }
   cout<<"\nDo you want to continue(Y/N) : ";
   cin>>reply;
    }while(reply == 'Y');

    return 0;
}


