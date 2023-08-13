#include<iostream>
using namespace std;
//!Time complexity wise recursive and iterative both same o(log n)
//!but recursive call space complexity is more.
int BinSearch(int arr[],int low,int high,int x){
    if(low>high)
        return -1;//base case
    int mid = (high+low)/2;
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid]>x){
        BinSearch(arr,low,mid-1,x);
    }
    else if(arr[mid]<x){
        BinSearch(arr,mid+1,high,x);
    }
    
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int ans = BinSearch(arr,0,5,2)  ;
    cout<<ans;
}