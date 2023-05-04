#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root){
    int largest = root;  // setting largest as root
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // If right child is larger than largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If largest is not root
    if (largest != root) {
        swap(arr[largest],arr[root]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

  
// implementing heap sort
void heapSort(int arr[], int n)
{
    for (int root = n / 2 - 1; root >= 0; root--)
        heapify(arr, n, root);

    // One by one extract an element from heap
    for (int root = n - 1; root >= 0; root--) {
        swap(arr[0], arr[root]);

        heapify(arr, root, 0);
    }
}

  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    //getting inputs from the user
    int size,number;
    cout<<"Enter the size of the array : ";
    cin>>size;
   int heap_arr[size]  ;
    cout<<"Enter the elements : " ;
   for(int i=0;i<size;i++){
       cin>>number;
       heap_arr[i]=number;
   }

   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}