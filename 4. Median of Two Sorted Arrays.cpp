/*
给两个有序数组 A，B，长度分别为 m 和 n，求中位数，复杂度必须保证是O(log (m+n))

很奇怪的问题，
先考虑 m+n 为奇数的情况，需要找第(m+n)/2+1大的数字，
进一步描述这个问题，找一组数 0<=p<m 和 0<=q<n，
满足 p+q==(m+n)/2 && (A[p]<=B[q+1]||A[m-1]<=B[0]) && (B[q]<=A[p+1]||B[n-1]<=A[0])，
答案为 max(A[p],B[q]);


考虑 m+n 为偶数的情况，需要找第(m+n)/2和第(m+n)/2+1大的数字，
将上面的过程重复两遍，找到 p+q==(m+n)/2-1 和 p+q==(m+n)/2 的数值

| 0 | 1 | 2 | 3 |
0   1   2  m-1  m

| 0 | 1 | 2 |
0   1  n-1  n

下标异常的麻烦，需要把各种0, n, m之类的边界想清楚才能过。

*/
class Solution {
public:
    double findKMinSortedArrays(int K, vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        //  A[0] ...  A[mid-1] | A[mid]   ... A[m]
        //  B[0] ...B[K-mid-1] | B[K-mid] ... B[n]
        //  0<=mid<=m,  0<=K-mid<=n
        int low = max(0, K-n)-1, up = min(m, K);
        while(low+1<up) {
            int mid=(low+up)/2;
            if (nums1[mid]<nums2[K-mid-1])
                low = mid;
            else
                up = mid;
        }
        int ans;
        if (up==0)
            ans = nums2[K-up-1];
        else if (K-up==0)
            ans = nums1[up-1];
        else
            ans = max(nums2[K-up-1],nums1[up-1]);
        return 1.0*ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        if (tot%2) {
            return findKMinSortedArrays(tot/2+1, nums1, nums2);
        } else {
            return (findKMinSortedArrays(tot/2, nums1, nums2) +
                findKMinSortedArrays(tot/2+1, nums1, nums2)) / 2;
        }
    }
};