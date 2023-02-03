#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
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
    bubblesort(arr,n);
     for(int i=0;i<n;i++)
    {
        cout<<"Your "<<i+1<<" no is :"<<arr[i]<<endl;
    }
     return 0;


}
