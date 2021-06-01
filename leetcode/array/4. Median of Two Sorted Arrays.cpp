/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
Follow up: The overall run time complexity should be O(log (m+n)).
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000

=========================>>>>My approach 
I used 2 pointer approach in which 1 pointer is pointing to starting point of 1st array and other pointer is pointing to starting point to
2nd array.
now as we have to middle element than we can reach there by traversing from lowest to highest
so we incresing that pointer whose next value is smaller
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        
        bool ch=false;
        if((n1+n2)%2==0)ch=true;
        int cnt = 0,p1=-1,p2=-1;
        double ans =0;
        
        while(p1+p2<(n1+n2)){
            
            if(ch==false&&cnt==(n1+n2)/2){
                //cout<<p1<<" "<<p2<<endl;
                if(p1==n1-1)ans=nums2[p2+1];
                else if(p2==n2-1)ans=nums1[p1+1];
                else ans = min(nums1[p1+1],nums2[p2+1]);
            }
            
            else if(ch==true&&cnt==(n1+n2)/2){
                cout<<p1<<" "<<p2<<endl;
                if(p1==-1)ans=nums2[p2];
                else if(p2==-1)ans=nums1[p1];
                else ans = max(nums1[p1],nums2[p2]);

                if(p1==n1-1){ans+=nums2[p2+1];}
                else if(p2==n2-1){ans+=nums1[p1+1];}
                else if(nums1[p1+1]>nums2[p2+1]){ans+=nums2[p2+1];}
                else {ans+=nums1[p1+1];}
                
                ans = ans/2;
            }
            
            if(p1==n1-1)p2++;
            else if(p2==n2-1)p1++;
            else if(nums1[p1+1]>nums2[p2+1])p2++;
            else p1++;
            cnt++;
        }
        
        return ans;
    }
};

