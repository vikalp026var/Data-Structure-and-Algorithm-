#include<iostream>
using namespace std;
void selection(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
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
    selection(arr,n);
     for(int i=0;i<n;i++)
    {
        cout<<"Your "<<i+1<<" no is :"<<arr[i]<<endl;
    }
     return 0;


}
