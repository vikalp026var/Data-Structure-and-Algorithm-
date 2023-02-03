#include<iostream>
#include<queue>
using namespace std;
#define max 100 
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;

    }
};
node*insertbst(node*&root,int data)
{
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    if(data> root->data)
    {
        root->right=insertbst(root->right,data);

    }else 
    {
        root->left=insertbst(root->left,data);

    }return root;
}
void takeinputs(node*&root)
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    while(data!=-1)
    {
        root=insertbst(root,data);
        cin>>data;
    }
}
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

          if(temp == NULL) { 
                               //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                               //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
node*minval(node*root)
{
    node*temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
node* deletefrombst(node*&root,int val)
{
  if(root==NULL)
  return root;
  if(root->data==val)
  {
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        node*temp=root->left;
        delete temp;
    }
    if(root->left!=NULL && root->right!=NULL)
    {
        int mini=minval(root->right)->data;
        root->data=mini;
        root->right=deletefrombst(root->right,mini);
        return root;
    }
    }
    else if(root->data > val)
    {
        root->left=deletefrombst(root->left,val);
        return root;
    }
  
}
void maxheap( int arr[],int n,int i)
{
    int largest=i;
    int l=2*i;
    int r=2*i+1;
    while(l<n && arr[l]>arr[largest])
    {
        largest =l;

    }
    while(r<n && arr[r]>arr[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;

        maxheap(arr,n,largest);
    }
}
void sort(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        maxheap(arr,n,i);
    }
    for(int i=n-1;i>=0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        maxheap(arr,i,0);
    }
    cout<<"Heap sort is completelty successfull"<<endl;
}
int main()
{    node*root=NULL;
    int n,data;
    while(1)
    {   cout<<"Enter Your choice :"<<endl;
        cout<<"1:Insertion in Binary search Tree."<<endl;
   cout<<"2.Deletion in Binary search Tree."<<endl;
        cout<<"3.Display in order ."<<endl;
    cout<<"4. Sorting (Heap Sort):"<<endl;
        cout<<"5.Exit"<<endl;
        cin>>n;
     switch(n)
     {  
     
        case 1: cout<<"You choose Insertion in binary search:"<<endl;
                cout<<"Enter data to create BST"<<endl;
                takeinputs(root);
                break;
       case 2: cout<<"You choose Deletion in Binary Search tree:"<<endl;
                cout<<"Enter the element that you want to delete"<<endl;
                cin>>data;
                root = deletefrombst(root,data);
                break;
        case 3:cout<<"You choose display :"<<endl;
               levelOrderTraversal(root);
               break;
       case 4: cout<<"You choose sorting (Heap sorting): "<<endl;
                  int arr[max], k;
                  cout << "Enter Number of heap Elements : ";
                  cin >> k;
                  cout << "Enter Heap Elements: " << endl;
                for(int j=0;j<k;j++)
                {
                  cin >> arr[j];
                }
                  sort(arr,k);
                  cout<<"Sorted array is :"<<endl;
                    for( int  i=0; i<k;i++)
                   {
                        cout<<arr[i]<<"     ";
                    }
                    cout<<endl;       
                    break; 
        case 5: cout<<"You are terminated your program successfully:"<<endl; 
               exit(0);
               break; 
     }
    }
    
return 0;


}