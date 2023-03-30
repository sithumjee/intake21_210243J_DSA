#include <iostream>
#include <chrono>
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

int main(){
    int size,median;
    double result;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++){
        cout<<"Enter the array elements: ";
        cin>>arr[i];}
    for (int i=1;i<=size;i++){
        int *arr1=new int[i];
        for(int j=0;j<i;j++){
            arr1[j]=arr[j];}
        quicksort(arr1,0,i-1);
        for(int k=0;k<i;k++){cout<<arr1[k]<<" ";}
        cout<<endl;
        if (i%2==0){
            result=(arr1[i/2]+arr1[(i-1)]/2)/2.0;
            }
        else{
            result=arr1[(i)/2];
            }
        printf("%.1f\n",result);
    }

}




