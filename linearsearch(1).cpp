// PROGRAM  FOR LINAR SEARCH 
#include<iostream>
using namespace std ;
int  found(int arr[],int n,int key )
{    int temp=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
       { cout<<"Element found at position "<<i+1<<endl;
       temp=0;
       break;
       }}
       if(temp==-1)
       {
        cout<<"Element Not found"<<endl;
       } 
        
        
    
    return 0;
    
    
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
     found(arr,n,key);
     
        
    
     
     return 0;


}

        
