#include<iostream>
using namespace std;
//Naive solution O(n)
// int FirstOccurance(int arr[],int n,int x){
//     for(int i =0;i<n;i++){
//         if(arr[i] == x){
//             return i;
//         }
//     }
//     return -1;//if not found
// }

//we write solution in O(log n)
int firstOcc(int arr[],int low,int high,int x){
    if(low>high){
        return -1;
    }
    int mid = (high+low)/2;
    if(arr[mid] == x){//now we check if it is the first occurance or not
        if(mid!=0){
            if(arr[mid-1] == x){
                return mid-1;
            }
        }
        else{
            return mid;
        }
    }
    else if(arr[mid]<x){
        firstOcc(arr,mid+1,high,x);
    }
    else if(arr[mid>x]){
        firstOcc(arr,low,mid-1,x);
    }
}
int main(){
    int arr[] = {1,2,3,4,20,20};
    int arr2[] = {5,5,5};
    int ans = firstOcc(arr2,0,2,5);
    cout<<ans;
}