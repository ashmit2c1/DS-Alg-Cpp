#include<bits/stdc++.h>
using namespace std;
// find the longest sub-array with the sum k ( assume array has only positives )
int findLongestSubArrayWithSumK(vector<int>&arr,int K){
    int n=arr.size();int left=0;int right=0;int sum=0;int len=0;
    while(right<n){
        sum+=arr[right];
        while(left<=right && sum>=K){
            if(sum==K){len=max(len,right-left+1);}
            sum-=arr[left];left++;
        }
        right++;
    }return len;
}
// find the longest sub-array with the sum k ( array has both positive and negative )
int findLongestSubArrayWithSumK(vector<int>&arr,int K){
    int n=arr.size();map<int,int>prefixMap;int sum=0;int len=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==K){len=max(len,i+1);}
        int remainder = sum-K;
        if(prefixMap.find(remainder)!=prefixMap.end()){
            int l = sum-prefixMap[remainder];
            len = max(len,l);
        }
        if(prefixMap.find(sum)==prefixMap.end()){
            prefixMap[remainder]=i;
        }
    }return len;
}
// find the max sum of the subarray of size k brute force 
int maxSum(vector<int>&arr,int K){
    int n=arr.size();int maxSum=INT_MIN;
    for(int i=0;i<=n-K;i++){
        int sum=0;
        for(int j=i;j<i+K;j++){sum+=arr[j];}
        maxSum=max(maxSum,sum);
    }return maxSum;
}
// find the max sum of subarray of size k optimal 
int maxSum(vector<int>&arr,int K){
    int n=arr.size();int maxSum=0;int sum=0;
    for(int i=0;i<K;i++){sum+=arr[i];}
    maxSum=sum;
    for(int i=K;i<n;i++){
        sum+=arr[i]-arr[i-K];maxSum=max(maxSum,sum);
    }return maxSum;
}
// find the max points you can obtain from cards
//https://www.geeksforgeeks.org/problems/maximum-point-you-can-obtain-from-cards/1?page=1&sortBy=newest&query=page1sortBynewest
int maxFromCard(vector<int>&arr,int K){
    int n=arr.size();int maxPoints=0;int left=0;int right=0;
    for(int i=0;i<K;i++){left+=arr[i];}maxPoints=left;
    int rightIndex=n-1;
    for(int i=K-1;i>=0;i--){
        left-=arr[i];right+=arr[rightIndex];
        maxPoints=max(maxPoints,left+right);
        rightIndex++;
    }return maxPoints;
}
// find the longest substring without repeating characters brute force  
int longestSubstring(string s){
    int n=s.size();int len=0;
    for(int i = 0; i<n ; i++){
        unordered_map<int,int>mp;int curr=0;
        for(int j=i;j<n;j++){
            char character=s[j];
            if(mp[character]>1){break;}
            mp[character]++;curr++;
            len=max(len,curr);
        }
    }return len;
}
// find the longest substring without repeating characters optimised solution 
int longestSubstring(string s){
    int n=s.size();int len=0;int first=0;int second=0;
    vector<bool>count(256,false);
    while(second<s.size()){
        char character=s[second];
        while(count[character]=true){
            count[s[first]]=false;first++;
        }
        count[character]=true;
        len=max(len,second-first+1);second++;
    }return len;
}
// fruits into basket // longest sub-array with at most K unique numbers
// https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/0
// brute force solution ( taking k as user input, question mentions 2, use k=2)
int totalFruits(vector<int>&arr,int k){
    int n=arr.size();int len=0;
    for(int i = 0; i<n ; i++){
        set<int>st;
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if(st.size()<=k){len=max(len,j-i+1);}
            else{break;}
        }
    }return len;
}
// optimal solution 
int totalFruits(vector<int>&arr,int k){
    int n=arr.size();unordered_map<int,int>mp;
    int len=0;int left=0;int right=0;
    for(right=0;right<n;right++){
        mp[arr[right]]++;
        while(mp.size()>2){
            mp[arr[left]]--;
            if(mp[arr[left]]==0){mp.erase(arr[left]);}
            left++;
        }
        len=max(len,right-left+1);
    }
}
// longest substring with at most k characters brute force 
// same as fruits into basket 
int longestSubstringK(string s,int k){
    int n=s.size();int len=0;
    for(int i = 0; i<n ; i++){
        set<char>st;
        for(int j=i;j<n;j++){
            st.insert(s[j]);
            if(st.size()<=k){len=max(len,j-i+1);}
            else{break;}
        }
    }return len;
}
// longest substring with at most k characters optimal 
int longestSubstringK(string s,int k){
    int n=s.size();unordered_map<char,int>mp;
    int len=0;int left=0;int right=0;
    for(right=0;right<n;right++){
        mp[s[right]]++;
        while(mp.size()>k){
            mp[s[left]]--;
            if(mp[s[left]]==0){mp.erase(s[left]);}
            left++;
        }
        len=max(len,right-left+1);
    }
}
// check if it is possible to make two numbers by multiplying either one of them by 2 
bool checkIfPossible(int a,int b){
    int small=min(a,b);int large=max(a,b);
    while(small!=large){
        small*=2;if(small>large){return false;}
    }return true;
}
// find the number of substring with all the three characters brute force 
int findSubstringWithTree(string s){
    int n =s.size();int cnt=0;
    for(int i=0;i<n;i++){
        int mp[3]={0};
        for(int j=i;j<n;j++){
            mp[s[j]-'a']++;
            if(mp[0]+mp[1]+mp[3]==1){cnt++;}
        }
    }return cnt;
}
// find the number of substring with all three characters optimal solution 
int findSubstringWithTree(string s){
    int n=s.size();int cnt=0;int lastidx[3]={-1};
    for(int i = 0; i<n ; i++){
        lastidx[s[i]-'a']=i;
        if(lastidx[0]!=-1 && lastidx[1]!=-1 && lastidx[3]!=-1){
            cnt=cnt+(1+min(lastidx[0],min(lastidx[1],lastidx[2])));
        }
    }return cnt;
}
// longest repeating character replacement brute force solution 
int longestRepeatingCharacter(string s,int k){
    int n=s.size();int len=0;
    for(int i = 0; i<n ; i++){
        int hash[26]={0};int maxFreq=0;
        for(int j=i;j<n;j++){
            int hashCharacter = hash[s[j]-'a'];
            maxFreq=max(maxFreq,hashCharacter);
            int changes = j-i+1-maxFreq;
            if(changes<=k){len=max(len,j-i+1);}
            else{break;}
        }
    }return len;
}
// longest repeating character replacement optimal solution 
int longestRepeatingCharacter(string s,int k){
    int n=s.size();int left=0;int maxfreq=0;
    int len=0;vector<int>count(26,0);
    for(int right=0;right<n;right++){
        count[s[right]-'a']++;
        maxfreq=max(maxfreq,count[s[right]-'a']);
        while((right-left+1)-maxfreq>k){
            count[s[left]-'a']--;left++;
        }
        len=max(len,right-left+1);
    }return len;
}
// count the number of sub-arrays with the sum K brute force 
int countsubArraysWithSumK(vector<int>&arr,int k){
    int n=arr.size();int cnt=0;
    for(int i = 0; i<n ; i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){cnt++;}
        }
    }return cnt;
}
// count the number of sub-arrays with the sum k optimal 
int countsubArrayWithSumK(vector<int>&arr,int k){
    int n=arr.size();int cnt=0;unordered_map<int,int>mp;
    int curr=0;
    for(int i = 0; i<n ; i++){
        curr+=arr[i];int diff=curr-k;
        if(mp.find(diff)!=mp.end()){cnt+=mp[diff];}
        mp[curr]++;
    }return cnt;
}
// binary subarray 
int binarySubArray(vector<int>& arr, int k) {
    if (k < 0) {
        return 0;
    }
    int left = 0;
    int right = 0;
    int sum = 0;
    int cnt = 0;
    while (right < arr.size()) {
        sum += arr[right];
        while (sum > k) {
            sum -= arr[left];
            left++;
        }
        cnt += (right - left + 1);
        right++;
    }
    return cnt;
}
// count the number of nice sub-array 
int niceSubArray(const vector<int>& nums, int k) {
    int left = 0;
    int right = 0;
    int oddCount = 0;
    int count = 0;
    
    while (right < nums.size()) {
        if (nums[right] % 2 != 0) {
            oddCount++;
        }
        while (oddCount > k) {
            if (nums[left] % 2 != 0) {
                oddCount--;
            }
            left++;
        }
        count += (right - left + 1);
        right++;
    }
    
    return count;
}
// find the sub-array with at most k distinct integers
// same as substring with at most k distinct characters
int countSubarraysWithKDistinctBruteForce(const vector<int>& nums, int k) {
    int count = 0;int n = nums.size();
    for (int start = 0; start < n; start++) {
        unordered_set<int> distinctSet;
        for (int end = start; end < n; end++) {
            distinctSet.insert(nums[end]);
            if (distinctSet.size() == k) {count++;}
            else if (distinctSet.size() > k) {break;}
        }
    }return count;
}
int atMostKDistinct(const vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    int left = 0;int count = 0;
    for (int right = 0; right < nums.size(); right++) {
        freq[nums[right]]++;
        while (freq.size() > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {freq.erase(nums[left]);}
            left++;
        }
        count += (right - left + 1);
    }return count;
}