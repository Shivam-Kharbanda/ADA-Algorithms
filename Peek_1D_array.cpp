#include<iostream>
using namespace std ;

int peek(int arr[], int n, int s, int e)
{
   
    if (s == e)  
    return arr[s];

    int mid = s + (e-s)/2 ;

    if(arr[mid] < arr[mid-1]) 
    {
        return peek(arr,n,s,mid-1) ;
    }
    if(arr[mid] < arr[mid+1]) 
    {
        return peek(arr,n,mid+1,e) ; 
    }
    return arr[mid] ;
}

int main()
{
    int arr[] = {10, 14, 15, 2, 23, 90, 67};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = peek(arr,n,0,n-1);
    cout<<"Peek element = "<<res<<endl ;

    return 0 ;
}