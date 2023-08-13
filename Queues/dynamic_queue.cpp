#include <iostream>
using namespace std;
template <typename T>
class QueueUsingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;//no. of elements in the queue
    int capacity;

    public:
    QueueUsingArray(int sizeOfqueue){
        data = new T[sizeOfqueue];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;   
        capacity = sizeOfqueue;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == -1;
    }
    //insert element
    void enqueue(T ele){
        if(size == capacity){
            //cout<<"Queue is full"<<endl;
            //return;
            T *newData = new T[2*capacity];
            int j = 0;
            for(int i = firstIndex;i<capacity;i++){
                newData[j] = data[i];
                j++; 
            }
            for(int i = 0;i<firstIndex;i++){
                newData[j] = data[i];
                j++;
            }
        }   
        data[nextIndex] = ele;
        nextIndex = (nextIndex + 1) % capacity;//eg: (4+1) % 5 = 0
        //eg: (0+1) % 5 = 1. so it will go to the next index and if nextIndex+1 is equal to capacity then it will go to the first index.
        if(firstIndex == -1){
            firstIndex = 0;
        }
        size++;
    }
    T front(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;//dry run 30 40 - 10 20.
        size--;
        if(size  == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

};