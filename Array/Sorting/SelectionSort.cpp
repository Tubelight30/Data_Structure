#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectionSort(vector<int> arr){
    for(int i = 0;i<arr.size()-1;i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
            }
        }
    }
    return arr;
}
    
int main(){
    vector<int> arr = {5,4,3,2,1};
    vector<int> sorted = SelectionSort(arr);
    for(int i = 0;i<sorted.size();i++){
        cout<<sorted[i]<<" ";
    }
    cout<<endl;
}