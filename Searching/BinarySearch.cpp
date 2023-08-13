#include<iostream>
using namespace std;
int BinSearch(int arr[],int n, int x){
    int low = 0,high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid]>x){
            high = mid-1;
        }
        if(arr[mid]<x){
            low = mid+1;
        }
    }
    //if not found
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int ans = BinSearch(arr,6,4);
    cout<<ans;
    return 0;
}