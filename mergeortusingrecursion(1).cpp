#include<iostream>
using namespace std;
void merge(int Arr[], int low, int high ) {
  int mid=(low+high)/2;
   int i, j, k;
   int n1 = mid - low + 1;
   int n2 = high - mid;
   int L[n1], R[n2];
   for (i = 0; i < n1; i++)
{
      L[i] = Arr[low + i];
}
   for (j = 0; j < n2; j++)
{
      R[j] = Arr[mid + 1+ j];
}
   i = 0, j = 0, k = low;

   while (i < n1 && j< n2) {

      if (L[i] <= R[j]) {
         Arr[k] = L[i];
         i++;
      } else 
      {
         Arr[k] = R[j];
         j++;
      }
      k++;

   }
   while (i < n1  ) {
      Arr[k] = L[i];
      i++;
      k++;

   }
   while (j < n2 ) {
      Arr[k] = R[j];
      j++;
      k++;
   }
}



void merge_sort(int Arr[], int s,int e){

     if(s>=e)
     {
        return;
     }
     int mid=(s+e)/2;
     merge(Arr,s,mid);
     merge(Arr,mid+1,e);
     merge_sort(Arr,s,e);
    

}
int main()
{
    cout<<"enter the size"<<endl;
    int n;
    cin>>n;
    int Arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>Arr[i];
    }
    merge_sort(Arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<Arr[i]<<" ";
    }return 0;


}