#include<bits/stdc++.h>
using namespace std;
// binary search 
int find(vector<int>&arr,int element){
    int n =arr.size();int start=0;int end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==element){return mid;}
        if(arr[mid] < element){start = mid+1;}
        if(arr[mid] > element){end = mid-1;}
    }return -1;
}
// recursive binary search 
int BSREcursive(vector<int>&arr,int element,int start,int end){
    if(start>end){return -1;}
    int mid = start + (end-start)/2;
    if(arr[mid]==element){return mid;}
    if(arr[mid ] < element){return BSREcursive(arr,element,mid+1,end);}
    if(arr[mid] > element){return BSREcursive(arr,element,start,mid-1);}
}
// find the square root of a number 
int findSqrt(int X){
    int start=0;int end=X;int ans=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(mid <= X/mid){ans=mid;start=mid+1;}
        else{end=mid-1;}
    }return ans;
}
// find the last and first occurence of an element 
vector<int>findFirstAndLast(vector<int>&arr,int element){
    int n=arr.size();int start=0;int end=n-1;int first=-1;int second=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==element){first=mid;end=mid-1;}
        if(arr[mid] < element){start=mid+1;}
        if(arr[mid] > element){end=mid-1;}
    }
    start=0;end=n-1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==element){second=mid;start=mid+1;}
        if(arr[mid] < element){start=mid+1;}
        if(arr[mid] > element){end= mid-1;}
    }
    vector<int>ans;ans.push_back(first);ans.push_back(second);return ans;
}
// search for position of an element in the array 
int findIndex(vector<int>&arr,int X){
    int n = arr.size();int start=0;int end=n-1;int ans=n;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]>=X){ans=mid;end=mid-1;}
        else{start=mid+1;}
    }return ans;
}
// find an element in 2D matrix using binary search 
bool isPresent(vector<vector<int>>&matrix,int element){
    int r = matrix.size();int c = matrix[0].size();
    for(int i=0;i<r;i++){
        int start=0;int end = c-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(matrix[i][mid]==element){return true;}
            if(matrix[i][mid] < element){start = mid+1;}
            if(matrix[i][mid] > element){end = mid-1;}
        }
    }return false;
}
// find the peak element in mountain array 
int findPeakElement(vector<int>&arr){
    int n = arr.size();int start=0;int end=n-1;
    while(start<=end){
        int mid = end+(start-end)/2;
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){return mid;}
        if(arr[mid] > arr[mid-1]){start=mid+1;}
        else{end=mid-1;}
    }return -1;
}
// search for an element in rotated sorted array 
bool findInRotated(vector<int>&arr,int element){
    int n=arr.size();int start=0;int end=n-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==element){return true;}
        else if(arr[mid]==arr[start] && arr[mid]==arr[end]){
            start++;end--;
        }
        else if(arr[mid]>arr[start]){
            if(element>=arr[start]&&element<arr[mid]){end=mid-1;}
            else{start=mid+1;}
        }
        else if(arr[end]>arr[mid]){
            if(element>arr[mid]&&element<arr[end]){start=mid+1;}
            else{end=mid-1;}
        }else{end=mid-1;}
    }return false;
}
// implement binary search in 2d arrays
