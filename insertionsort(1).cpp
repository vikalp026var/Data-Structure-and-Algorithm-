#include<iostream>
using namespace std;
void insertion(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(arr[j]>temp && j>=0 )
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
}
int main()
{    int n;
     cout<<"Enter the size of array "<<endl;
    cin>>n; 
     int arr[n];
     cout<<"Enter the Elements"<<endl;
     for(int i=0;i<n;i++)
     {
        cout<<"Enter the Elements at "<<i+1<<":";
        cin>>arr[i];
     }
    cout<<"Sorted array"<<endl;
    insertion(arr,n);
     for(int i=0;i<n;i++)
    {
        cout<<"Your "<<i+1<<" no is :"<<arr[i]<<endl;
    }
     return 0;


}