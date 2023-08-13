#include<iostream>
using namespace std;

int lastOcc(int arr[],int low,int high,int x,int n){
    if(low>high){
        return -1;
    }
    int mid = (high+low)/2;
    if(arr[mid]>x){
        return lastOcc(arr,low,mid-1,x,n);
    }
    else if(arr[mid]<x){
        return lastOcc(arr,mid+1,high,x,n);
    }
    else{//if arr[mid] = x now to check if its the last occurance.
        if(mid == (n-1) || arr[mid] != arr[mid+1]){
            return mid;
        }
        else{
            return lastOcc(arr,mid+1,high,x,n);
        }
    }
}
int main(){
    int arr[] = {5,10,10,10,10,10};
    int ans = lastOcc(arr,0,6,10,6);
    cout<<ans;
}