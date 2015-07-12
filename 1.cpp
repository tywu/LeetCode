/* Two Sum
*  2015.07.12 published.
*  Author: Tai-Yi Wu.
*  Runtime 21ms 16/16 passed.
*/

/* Using Map to record visited int
*  One traverse only.
*  Time : O(n)
*  Space: O(n)
*/

class Solution {
 public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash_map;
        vector<int> res;
        for(int i = 0; i < nums.size();++i) {
            if(hash_map.count(target - nums[i])) {
                res.push_back(hash_map[target-nums[i]]);
                res.push_back(i+1);
                break;
            }
            else {
                hash_map[nums[i]] = i+1;
            }
        }
        return res;
    }
};
