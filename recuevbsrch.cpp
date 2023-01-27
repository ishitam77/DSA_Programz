#include <iostream>
using namespace std;
int srch(int arr[],int l,int h,int k){
 if(l>h){
     return -1;
 }   
 int m=(l+h)/2;
 if(k==arr[m]){
     return m;
 }
 else if(k>arr[m]){
     return srch(arr,m+1,h,k);
     
 }
 else{
  return srch(arr,l,m-1,k);   
 }
}
int main() {
int n,arr[100],key;
cout<<"enter the no. of terms:";
cin>>n;
cout<<"enter the elements";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"Enter the key:";
cin>>key;
int l=0,h=n-1;
int z=srch(arr,l,h,key);
if(z==-1){
    cout<<"not found";
}
else{
    cout<<"element found";
}
 return 0;
}