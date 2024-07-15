/*
index used 20min


*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1;i>=0;i--) {
            nums1[i+nums1.size()-m]=nums1[i];
        }
        int index2 = 0;
        for(int i=nums1.size()-m;i<nums1.size();i++) {
            while(index2<n&&nums2[index2]<nums1[i]){
                // [i,nums1.size())-> len1=nums1.size()-i;
                // [index2,n) ->len2 = n-index2;
                // cur index = nums1.size() - (nums1.size()-i) - (n-index2)
                // cur index = i-n+index2;
                nums1[i-n+index2]=nums2[index2];
                index2++;
            }
            nums1[i-n+index2]=nums1[i];
        }
        while (index2<n) {
            nums1[nums1.size()-n+index2]=nums2[index2];
            index2++;
        }
    }
};