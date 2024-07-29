#include<bits/stdc++.h>
using namespace std;
/*
SELECTION SORT 
Time Complexity - O(N^2) Space Complexity - O(1)
Not stable, swapping might change order of equal elements
*/
void selectionSort(vector<int>&arr){
    int n = arr.size();
    int minIndex;
    for(int i=0;i<n;i++){
        minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex] > arr[j]){
                minIndex=j;
            }
        }
        if(minIndex!=i){
            swap(arr[minIndex],arr[i]);
        }
    }
}
/*
INSERTION SORT  
Time Complexity - O(N^2) Space Complexity - O(1)
Stable, swapping will not change order of elements
*/
void insertionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int current = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > current){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}
/*
BUBBLE SORT 
Time Complexity - O(N^2) Space Complexity - O(1)
Stable, swapping will not change order of elements
*/
void bubbleSort(vector<int>&arr){
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        bool flag = false;
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                flag = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(flag==false){
            return;
        }
    }
}
/*
MERGE SORT 
Time Complexity - O(N Log N) Space Complexity - O(N)
Stable, swapping will not change order of elements
*/
void merge(vector<int>&arr,int start,int mid,int end){
    int sizeA = mid-start+1;
    int sizeB = end-mid;
    vector<int>a(sizeA);
    vector<int>b(sizeB);
    for(int i=0;i<sizeA;i++){
        a[i] = arr[start+i];
    }
    for(int i=0;i<sizeB;i++){
        b[i] = arr[mid+1+i];
    }
    int i=0;int j=0;int k=start;
    while(i<sizeA && j<sizeB){
        if(a[i] < b[j]){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    while(i<sizeA){
        arr[k++] = a[i++]; 
    }
    while(i<sizeB){
        arr[k++] = b[j++];
    }
}
void mergeSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
/*
QUICK SORT  
Time Complexity - O(N Log N) Space Complexity - O(N Log N)
Not stable, swapping might change order of equal elements
*/
int partition(vector<int>&arr,int start,int end){
    int pivot = arr[end];
    int i = start-1;
    for(int j=start; j<end;j++){
        if(pivot > arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}
void quickSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return;
    }
    int pivot = partition(arr,start,end);
    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);
}
