#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int> arr){
    for(int i = 1;i<arr.size();i++){
        int curr = arr[i];
        int j= i-1;
        while(j>=0 && arr[j]>curr){
            arr[j+1] = arr[j];
            j--;
        }//all elements greater than curr are shifted to the right
        arr[j+1] = curr;
    }
    return arr;
}
int main(){
    vector<int> arr = {5,4,3,2,1};
    vector<int> sorted = InsertionSort(arr);
    for(int i = 0;i<sorted.size();i++){
        cout<<sorted[i]<<" ";
    }
    cout<<endl;
}