#include<iostream>
using namespace std ;
void binarysearch(int arr[],int n,int key)
{   int temp=-1;
    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(arr[mid]==key)
        {
            cout<<"Element found at position "<<mid+1<<endl;
            temp=0;
            break;

        }
        else 
        if(arr[mid]<key)
        {
            s=mid+1;
        }
        else 
        {
            e=mid-1;
        }
    }
    if(temp==-1)
    {
        cout<<"Elemnet not found"<<endl;
    }

}
int main()
{    int n;
     cout<<"Enter the size of array "<<endl;
    cin>>n; 
     int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     for(int i=0;i<n;i++)
    {
        cout<<"Your "<<i+1<<" no is :"<<arr[i]<<endl;
    }
    cout<<"Enter the key that you want to search"<<endl;
    int key;
    cin>>key;
     binarysearch(arr,n,key);
     
        
    
     
     return 0;


}
