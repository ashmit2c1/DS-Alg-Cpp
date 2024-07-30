#include<bits/stdc++.h>
using namespace std;
// find the last occurence of element 
int findLastOcc(vector<int>&arr,int element){
    int n = arr.size();int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]==element){index=i;break;}
    }return index;
}
// find the total number of pairs whose sum is x ( brute force )
int findPairs(vector<int>&arr,int X){
    int n = arr.size();int count=0;
    for(int i = 0; i<n ; i++){
        for(int j=0;j<n;j++){
            if((arr[i]+arr[j])==X){count++;}
        }
    }return count;
}
// find the total number of pairs whose sum is x ( optimised )
int findPairs(vector<int>&arr,int X){
    int n = arr.size();unordered_map<int,int>mp;int count=0;
    for(int i = 0; i<n ; i++){
        int complement = X-arr[i];
        if(mp.find(complement)!=mp.end()){count+=mp[complement];}
        mp[arr[i]]++;
    }return count;
}
// find the element that does have a duplicate ( brute force )
int findElement(vector<int>&arr){
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){arr[i]=arr[j]=-1;}
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=-1){return arr[i];}
    }
}
// find the element that does have not a duplicate ( optimised )
int findElement(vector<int>&arr){
    int n = arr.size();unordered_map<int,int>mp;
    for(int i=0;i<n;i++){mp[arr[i]]++;}
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second=1){return it->first;}
    }
}
// find the second largest element in the array 
int secondLargest(vector<int>&arr,int element){
    int n = arr.size();int max=INT_MIN;int maxIndex=-1;
    for(int i=0;i<n;i++){
        if(arr[i]>max){max=arr[i];maxIndex=i;}
    }
    arr[maxIndex]=INT_MIN;int max2=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max2 && i!=maxIndex){max2=arr[i];}
    }return max2;
}
// rotate an array by k steps
void rotateByK(vector<int>&arr,int k){
    int n = arr.size();k=k%n;int temp[n];int j=0;
    for(int i=n-k;i<n;i++){temp[j++]=arr[i];}
    for(int i=0;i<=k;i++){temp[j++]=arr[i];}
    int k=0;
    for(int i=0;i<n;i++){arr[k++]=temp[i];}
}
// sort an array with 0 and 1
vector<int> sortO1(vector<int>&arr){
    int n = arr.size();int zeroCount=0;
    for(int i=0;i<n;i++){if(arr[i]==0){zeroCount++;}}
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(i<zeroCount){ans.push_back(0);}
        else{ans.push_back(1);}
    }return ans;
}
// sort an array with 0 and 1 using 2 pointer 
vector<int>sortO1(vector<int>&arr){
    int n = arr.size();int left=0;int right=n-1;
    while(left<right){
        if(arr[left]==1 && arr[right]==0){
            swap(arr[left],arr[right]);left++;right--;
        }
        if(arr[left]==0){left++;}
        if(arr[right]==1){right--;}
    }return arr;
}
// given an array place all the even integers first 
vector<int>placeEvenInFront(vector<int>&arr){
    int n = arr.size();int left=0;int right=n-1;
    while(left<right){
        if(arr[left]%2!=0 && arr[right]%2==0){
            swap(arr[left],arr[right]);left++;right--;
        }
        if(arr[left]%2==0){left++;}
        if(arr[right]%2!=0){right--;}
    }return arr;
}
// given an integer array return the sorted squared array 
vector<int>sortedSquared(vector<int>&arr){
    int n = arr.size();int left=0;int right=n-1;
    vector<int>ans(n);int index=n-1;
    while(left<right){
        if(abs(arr[left])<abs(arr[right])){
            ans[index]=arr[right]*arr[right];right--;index--;
        }
        else{
            ans[index]=arr[left]*arr[left];left++;index--;
        }
    }return ans;
}
// given an integer array return the prefix sum array
vector<int>prefixSum(vector<int>&arr){
    int n = arr.size();vector<int>ans(n);
    ans[0]=arr[0];int j=1;
    for(int i=1;i<n;i++){
        ans[j]=arr[i]+arr[i-1];j++;
    }return ans;
}
// given an integer array check if we can partition the array into two halves with equal sum
bool yesOrNo(vector<int>&arr){
    int sum = 0;int n = arr.size();
    for(int i=0;i<n;i++){sum+=arr[i];}
    int prefixSum,suffixSum=0;
    for(int i=0;i<n;i++){
        prefixSum+=arr[i];suffixSum=sum-prefixSum;
        if(prefixSum==suffixSum){return true;}
    }return false;
}
// find the max sum of sub-array size k { brute force }
int maxSum(vector<int>&arr,int k){
    int maxSum=0;int n = arr.size();
    for(int i=0;i<n-k;i++){
        int currentSum=0;
        for(int j=i;j<i+k;j++){
            currentSum+=arr[j];
            maxSum=max(maxSum,currentSum);
        }
    }return maxSum;
}
// find the max sum of the sub-array size k { optimised }
int maxSum(vector<int>&arr,int k){
    int maxSum=0;int n = arr.size();int sum=0;
    for(int i=0;i<k;i++){sum+=arr[i];}
    maxSum=sum;
    for(int i=k;i<n;i++){
        sum=sum+arr[i]-arr[i-k];
        maxSum=max(maxSum,sum);
    }return maxSum;
}
// find the index of the sub-array with the sum 
vector<int>findIndex(vector<int>&arr,int X){
    int n = arr.size();int start=0;int end=n-1;int current =0;
    vector<int>ans;
    for(int i=0;i<n;i++){
        current+=arr[i];
        if(current>=X){
            end=i;
            while(current>X && start<end){
                current-=arr[start];start++;}}
        if(current==X){
            ans.push_back(start+1);ans.push_back(end+1);return ans;
        }
    }ans.push_back(-1);return ans;
}
// find the nunber of operation required to change all the elements
int numOfOperations(vector<int>&arr){
    int n = arr.size();int occ=1;int maxOcc=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){occ++;maxOcc=max(maxOcc,occ);}
        else{occ=1;}
    }int ans=n-maxOcc;return ans;
}
// find the nunber of operations required to change all the elements using map
int numOfOperations(vector<int>&arr){
    int n = arr.size();unordered_map<int,int>mp;
    for(int i=0;i<n;i++){mp[arr[i]]++;}int ans=0;
    for(auto it=mp.begin();it!=mp.end();it++){ans=max(ans,it->second);}
    return ans;
}
// find the max sub-array sum ( brute force )
int maxSubArray(vector<int>&arr){
    int n = arr.size();int maxSum=INT_MIN;;
    for(int i=0;i<n;i++){int currentSum=0;
    for(int j=0;j<n;j++){
        currentSum+=arr[j];maxSum=max(maxSum,currentSum);
    }}return maxSum;
}
// kadane's algorithm for max sub-array sum ( optimised )
int maxSubarray(vector<int>&arr){
    int n = arr.size();int maxHere=0;int maxSoFar=INT_MIN;
    for(int i = 0; i<n ; i++){
        maxHere+=arr[i];
        if(maxHere<arr[i]){maxHere=arr[i];}
        if(maxSoFar<maxHere){maxSoFar=maxHere;}
    }return maxSoFar;
}
// find the union of two sorted arrays
vector<int>findUnion(vector<int>&arr1,vector<int>&arr2){
    int n1=arr1.size();int n2=arr2.size();int i,j=0;vector<int>ans;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(ans.size()==0 || ans.back()!=arr1[i]){
                ans.push_back(arr1[i]);
            }i++;
        }
        else{if(ans.size()==0 || ans.back()!=arr2[j]){ans.push_back(arr2[j]);}j++;}
    }
    while(i<n1){
        if(ans.size()==0 ||ans.back()!=arr1[i]){ans.push_back(arr1[i]);}i++;
    }
    while(j<n2){
        if(ans.size()==0 || ans.back()!=arr2[j]){ans.push_back(arr2[j]);}j++;
    }return ans;
}
// find the intersection of two sorted arrays
vector<int>findIntersection(vector<int>&arr1,vector<int>&arr2){
    int n1 = arr1.size();int n2=arr2.size();vector<int>ans;int i,j=0;
    while(i<n1 && j<n2){
        if(arr1[i] > arr2[j]){j++;}
        else if(arr1[i] < arr2[j]){j++;}
        else{
            if(ans.size()==0 || ans.back()!=0){ans.push_back(arr1[i]);}i++;j++;
        }
    }return ans;
}
// cyclically rotate an array by one place
vector<int>rotate(vector<int>&arr){
    int n= arr.size();vector<int>ans;ans.push_back(arr[n-1]);
    for(int i=1;i<n-1;i++){ans.push_back(arr[i]);}return ans;
}
// check whether the given array is sorted or not 
bool checkIfSorted(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){if(arr[i] > arr[i+1]){return false;}
    }return true;
}
// find an element in sorted array in less than O(N) time complexity 
bool find(vector<int>&arr,int element){
    int n = arr.size();int start=0;int end=n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==element){return true;}
        if(arr[mid] < element){start=mid+1;}
        if(arr[mid] > element){end=mid-1;}
    }return false;
}
// find the missing number 
int findMissingNumber(vector<int>&arr){
    int n = arr.size();int n2=n+1;int sum,sum1=0;
    for(int i=1;i<=n2;i++){sum+=i;}
    for(int i=0;i<n;i++){sum1+=arr[i];}
    int ans = sum-sum1;return ans;
}
// find the max ones by flipping at most  m zeros
int findZeroes(vector<int>&arr,int M){
    int j,zero,ans=0;int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==0){zero++;}
        while(zero>M){if(arr[j]==0){zero--;}j++;}
        ans=max(ans,i-j+1);
    }return ans;
}
// find the longest sub-array with the sum K assuming array only has positives
int lenOfLongestSubArray(vector<int>&arr,int K){
    int left,right,maxLen,sum=0;
    while(right<arr.size()){
        sum+=arr[right];
        while(left<=right && sum>=K){
            if(sum==K){maxLen = max(maxLen,right-left+1);}
            sum-=arr[left];left++;
        }right++;
    }return maxLen;
}
// search for an element in 2D matrix
bool find(vector<vector<int>>&arr,int element){
    int n = arr.size();int m = arr[0].size();
    for(int i=0;i<n;i++){
        int start=0;int end=m-1;
        while(start<=end){
            int mid = start + (end-start/2);
            if(arr[i][mid]==element){return true;}
            if(arr[i][mid] < element){start=mid+1;}
            if(arr[i][mid] > element){end = mid-1;}
        }}return false;
}
// find the number that appears once while others twice ( brute force )
int findElement(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j]){arr[i]=arr[j]=-1;}
        }
    }for(int i=0;i<n;i++){if(arr[i]!=-1){return arr[i];}}
}
// find the element that appears once while other twice 
int findElement(vector<int>&arr){
    int n = arr.size();unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second==1){return it->first;}
    }
}
// find the row with the max 1s
int rowsWithMax(vector<vector<int>>&matrix,int r,int c){
    int n = matrix.size();
    int m = matrix[0].size();
    int r = 0;int c = m-1;
    int index = -1;
    while(r < n && c>=0){
        if(matrix[r][c]==1){index=r;c--;}
        else{r++;}
    }return index;
}
// two sum with two arrays
vector<pair<int,int>>allPairs(vector<int>&arr1,vector<int>&arr2,int X){
    vector<pair<int,int>>ans;int n = arr1.size();
    unordered_set<int>st;int m=arr2.size();
    for(int i=0;i<n;i++){st.insert(arr1[i]);}
    for(int i=0;i<m;i++){int complement = X-arr2[i];
    if(st.find(complement)!=st.end()){ans.push_back(make_pair(complement,arr2[i]));}
    }return ans;
}
// find the majority element ( brute force )
int findMajority(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int count=0;int candidate=arr[i];
        for(int j=0;j<n;j++){
            if(arr[j]==candidate){count++;}
        }
        if(count>n/2){return candidate;}
    }return -1;
}
// find the majority element ( optimised moore voting approach )
int findMajority(vector<int>&arr){
    int n=arr.size();int element=-1;int cnt=0;int cnt2=0;
    for(int i=0;i<n;i++){
        if(cnt==0){element=arr[i];cnt=1;}
        else{if(arr[i]==element){cnt++;}else{cnt--;}}
    }
    for(int i=0;i<n;i++){
        if(arr[i]==element){cnt2++;}
    }if(cnt2>n/2){return element;}else{return -1;}
}
// stock buy and sell
int stockBuySell(vector<int>&prices){
    int n=prices.size();int profit=0;
    for(int i=1;i<n;i++){
        if(prices[i]>prices[i-1]){
            int sell = prices[i]-prices[i-1];profit+=sell;}
    }return profit;
}
// re-arrange the positive and negative elements in the array 
vector<int>rearrange(vector<int>&arr){
    int n = arr.size();vector<int>positive;vector<int>negative;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){positive.push_back(arr[i]);}
        else{negative.push_back(arr[i]);}
    }
    int index=0;int positiveIndex=0;int negativeIndex=0;
    while(positiveIndex<positive.size()&&negativeIndex<negative.size()){
        if(index%2==0){arr[index++]=positive[positiveIndex++];}
        else{arr[index++]=negative[negativeIndex++];}
    }
    while(positiveIndex<positive.size()){arr[index++]=positive[positiveIndex++];}
    while(negativeIndex<negative.size()){arr[index++]=negative[negativeIndex++];}
    return arr;
}
// merge two sorted arrays
vector<int>mergeTwoSorted(vector<int>&arr1,vector<int>&arr2){
    int n = arr1.size();int m=arr2.size();map<int,int>mp;
    for(int i=0;i<n;i++){mp[arr1[i]]++;}
    for(int i=0;i<m;i++){mp[arr2[i]]++;}
    vector<int>ans;
    for(auto it=mp.begin();it!=mp.end();it++){
        for(int i=0;i<it->second;i++){ans.push_back(it->first);}
    }return ans;
}