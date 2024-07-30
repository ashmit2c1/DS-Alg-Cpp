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
bool findIn2D(vector<vector<int>>&arr,int element){
    int n = arr.size();int m = arr[0].size();
    for(int i=0;i<n;i++){
        int start=0;int end=m-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[i][mid]==element){return true;}
            if(arr[i][mid] < element){start=mid+1;}
            if(arr[i][mid] > element){end=mid-1;}
        }
    }return false;
}
// find the minimum element in rotated sorted array 
int findMin(vector<int>&arr){
    int n=arr.size();int start=0;int end=n-1;int ans=arr[0];
    if(arr[start]<=arr[end]){return ans;}
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[end]>=arr[mid]){ans=arr[mid];end=mid-1;}
        else{start=mid+1;}
    }return ans;
}
// find the kth positive missing number 
int findKthPositive(vector<int>&arr,int k){
    int n = arr.size();int start=0;int end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        int missingNumber = arr[mid]-(mid+1);
        if(k>missingNumber){start=mid+1;}
        else{end=mid-1;}
    }return start+k;
}
// book allocation problem 
bool isPossible(vector<int>&pages,int students,int books,int mid){
    int studentCount=1;int pageSum=0;int n = pages.size();
    for(int i=0;i<n;i++){
        if(pages[i]>mid){return false;}
        if(pageSum+pages[i]<=mid){pageSum+=pages[i];}
        else{
            studentCount++;if(studentCount>students){return false;}
            pageSum=pages[i];
        }
    }return true;
}
int findPages(vector<int>&pages,int students,int books){
    int sum=0;int n=pages.size();
    for(int i=0;i<n;i++){sum+=pages[i];}
    int start=0;int end=sum;int ans=-1;
    while(start<=end){
        int mid = start + (end-start/2);
        if(isPossible(pages,students,books,mid)==true){ans=mid;end=mid-1;}
        else{start=mid+1;}
    }return ans;
}
// capacity to ship packages in D days
int capacity(vector<int>&weights,int days){
    int sum=0;int n=weights.size();
    for(int i=0;i<n;i++){sum+=weights[i];}
    int start=0;int end=sum;
    while(start<end){
        int mid = start + (end-start)/2;
        int time=1;int currentWeight=0;
        for(int i = 0; i<n ; i++){
            if(currentWeight+weights[i]>mid){time++;currentWeight=0;}
            currentWeight+=weights[i];
        }
        if(time>days){start=mid+1;}
        else{end=mid-1;}
    }return start;
}
// find the lower bound for an array element 
int findLowerBound(vector<int>&arr,int X){
    int n = arr.size();int start=0;int end=n-1;int ans=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(X>=arr[mid]){ans=mid;start=mid+1;}
        else{end=mid-1;}
    }return ans;
}
// find the upper bound for an array element  
int findUpperBound(vector<int>&arr,int X){
    int n = arr.size();int start=0;int end=n-1;int ans=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]>X){ans=mid;end=mid-1;}
        else{start=mid+1;}
    }return ans;
}
// count the number of occurences of an element 
int countOccurence(vector<int>&arr,int X){
    int n=arr.size();int start=0;int end=n-1;int first=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(X==arr[mid]){first=mid;end=mid-1;}
        if(X>arr[mid]){start=mid+1;}
        if(X<arr[mid]){end=mid-1;}
    }
    start=0;end=n-1;int second=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(X==arr[mid]){second=mid;start=mid+1;}
        if(X>arr[mid]){start=mid+1;}
        if(X<arr[mid]){end=mid-1;}
    }int ans = second-first+1;return ans;
}
// koko eating banana brute force solution 
int solve(vector<int>&piles,int hours){
    int n = piles.size();int maxPile=INT_MIN;
    for(int i=0;i<n;i++){maxPile=max(maxPile,piles[i]);}
    int ans = maxPile;
    for(int i=1;i<maxPile;i++){
        int current=0;
        for(int j=0;j<n;j++){current+=ceil((double)piles[j]/i);}
        if(hours>=current){ans=i;break;}
    }return ans;
}
// koko eating banana binary search solution 
bool canEat(vector<int>&piles,int hours,int mid){
    int time=0;int n=piles.size();
    for(int i=0;i<n;i++){time+=ceil(double(piles[i]/mid));}
    if(time<=hours){return true;}else{return false;}
}
int solve(vector<int>&piles,int hours){
    int n = piles.size();int maxSpeed = *max_element(piles.begin(),piles.end());
    int minSpeed=1;int ans=-1;
    while(minSpeed<maxSpeed){
        int mid = minSpeed+(maxSpeed-minSpeed)/2;
        if(canEat(piles,hours,mid)==true){ans=mid;maxSpeed=minSpeed-1;}
        else{minSpeed=mid+1;}
    }return ans;
}
// painter partition problem 
bool isPossible(vector<int>&boards,int k,int mid){
    int paintersCount=1;int n=boards.size();int time=0;
    for(int i=0;i<n;i++){
        if(boards[i]>mid){return false;}
        if(boards[i]+time<=mid){time+=boards[i];}
        else{paintersCount++;if(paintersCount>k){return false;}
        time=boards[i];
        }
    }return true;
}
int minTime(vector<int>&boards, int k){
    int sum=0;int n= boards.size();
    for(int i=0;i<n;i++){sum+=boards[i];}
    int start=0;int end=sum;int ans=-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isPossible(boards,k,mid)==true){ans=mid;end=mid-1;}
        else{start=mid+1;}
    }return ans;
}
// triangular height with n coins 
int height(int n){
    int start = 1;int end = n;int ans=0;
    while(start<=end){
        int mid = start + (end-start)/2;
        int coinsNeeded = (mid*(mid+1))/2;
        if(coinsNeeded <= n){ans = mid;start = mid+1;}
        else{end = mid-1;}
    }return ans;
}
// aggressive cows brute force solution 
bool canPlaceCows(const vector<int>& stalls, int k, int minDist) {
    int count = 1;int lastPosition = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= minDist) {count++; // Place a cow here
            lastPosition = stalls[i];
        }
        if (count == k) {return true;}
    }return false;
}
int solve(int n, int k, vector<int>& stalls) {
    sort(stalls.begin(), stalls.end());int maxMinDist = 0;
    for (int minDist = 1; minDist <= stalls[n-1] - stalls[0]; minDist++) {
        if (canPlaceCows(stalls, k, minDist)) {maxMinDist = minDist;}
    }return maxMinDist;
}
// aggressive cows binary search solution 
bool canPlaceCows(const vector<int>& stalls, int k, int minDist) {
    int count = 1;int lastPosition = stalls[0];
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= minDist) {
            count++;lastPosition = stalls[i];}
        if (count == k) {return true; }
    }return false;
}

int solve(int n, int k, vector<int>& stalls) {
    sort(stalls.begin(), stalls.end());
    int left = 1; int right = stalls[n-1] - stalls[0]; 
    int result = 0; 
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canPlaceCows(stalls, k, mid)) {result = mid; left = mid + 1;
        } else {right = mid - 1;}
    }return result;
}