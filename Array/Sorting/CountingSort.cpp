#include <iostream>
#include <vector>
using namespace std;

void countSort(int arr[],int n){
    int k = arr[0];
    for(int i = 0;i<n;i++){
        if(arr[i]>=k){
            k = arr[i];
        }
    }
    int count[k+1]= {0};
    for(int i = 0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i =1;i<k+1;i++){
        count[i]+=count[i-1];   
    }
    int output[n];
    for(int i = n-1;i>=0;i--){
        count[arr[i]]--;
        output[count[arr[i]]] = arr[i];
    }
    for(int i = 0;i<n;i++){
        arr[i] = output[i];
    }
}
int main(){
    int arr[] = {1,4,4,1,0,1};
    countSort(arr,6);
    for(int i = 0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}