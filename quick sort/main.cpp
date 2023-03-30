#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
using namespace ::chrono;

int partition(int arr[],int start,int end){
    int partition_index=start;
    int pivot =arr[end];
    for(int i=start;i<end;i++){
        if(arr[i]<=pivot){
            swap(arr[i],arr[partition_index]);
            partition_index++;
        }
    }
    swap(arr[partition_index],arr[end]);
    return partition_index;
}

void quicksort(int arr[],int start, int end){
    if (start>=end){return;}
    int partition_index = partition(arr,start,end);
    quicksort(arr,start,partition_index-1);
    quicksort(arr,partition_index+1,end);
}


void iterative_quicksort(int arr[],int array_size){
    stack<pair<int, int>> s;
    int start = 0;
    int end = array_size - 1;
    // push the start and end index of the array into the stack
    s.push(make_pair(start, end));
    // loop till stack is empty
    while (!s.empty())
    {
        start = s.top().first, end = s.top().second;
        s.pop();
        // rearrange elements across pivot
        int pivot = partition(arr, start, end);
        // push subarray indices containing elements that are
        // less than the current pivot to stack
        if (pivot - 1 > start) {
            s.push(make_pair(start, pivot - 1));
        }

        // push subarray indices containing elements that are
        // more than the current pivot to stack
        if (pivot + 1 < end) {
            s.push(make_pair(pivot + 1, end));
        }
    }
}


int main(){
    int arr1[]={89876,98564,6984149,58956,7841529};
    auto start1 = high_resolution_clock::now();
    quicksort(arr1,0,sizeof(arr1)/sizeof(int)-1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "Elapsed time recursion arr1: " << duration1.count() << " nanoseconds" << endl;
    auto start2 = high_resolution_clock::now();
    iterative_quicksort(arr1,sizeof(arr1)/sizeof(int)-1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "Elapsed time iteration arr1: " << duration2.count() << " nanoseconds" << endl;
    cout<<endl;
    for(int i:arr1){cout<<i<<" ";}
    return 0;
}
