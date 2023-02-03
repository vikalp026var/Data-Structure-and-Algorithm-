
#include<iostream>
using namespace std;
void merge(int Arr[], int low, int mid, int high ) {

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



void merge_sort(int Arr[], int N){

     int high,mid,low; 
    for(int i =2;i<N;i*=2)

    {
        for(int j=0; i+j-1<N; j+=i)

        {

            int high = i+j-1;
            int low =j;
            int mid=(high+low)/2;
            merge (Arr,low,mid,high);
        }if(i/2<N)
            merge(Arr, 0,i/2,N-1);

        }

}



int main()

{

    int i;
int n;
cout<<"Enter the number of elements ";
    cin>>n;
    int Arr[n];
    for(int i=0;i<n;i++)
       Arr[i]=rand()%100;
     

    cout<<"Unsorted Array: ";

    for(i=0;i<n;i++)

        cout<<Arr[i]<<" ";

    cout<<endl;
    merge_sort(Arr, n);
    cout<<"Sorted Array: ";

    for(i=0;i<n;i++)

        cout<<Arr[i]<<" ";

    return 0;

}


