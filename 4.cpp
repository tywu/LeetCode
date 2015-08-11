/* Median of Two Sorted Arrays
* 2015.8.10 published.
* Author Tai-Yi Wu.
* Runtime 40ms 2078/2078 passed.
*/

/* Time:  O(N)
*  Space: O(1)
*/
class Solution {
public:
    double FindKthNum(const vector<int>& nums1, const vector<int>& nums2, int ith, int* prev) {
        int cur1 = 0;
        int cur2 = 0;
        int value = 0;
        while(cur1 + cur2 < ith){
            if(cur1 == nums1.size()){
                *prev = value;
                value = nums2[cur2++];
            }
            else if(cur2 == nums2.size()){
                *prev = value;
                value = nums1[cur1++];
            }
            else if(nums1[cur1] <= nums2[cur2]){
                *prev = value;
                value = nums1[cur1++];
            }else {
                *prev = value;
                value = nums2[cur2++];
            }
        }
        return double(value);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_num = nums1.size() + nums2.size();
        int prev = INT_MIN;
        double kth = FindKthNum(nums1, nums2, total_num/2+1, &prev);
        if(total_num%2 == 1) return kth;
        return (kth+double(prev) )/2;
    }
};
