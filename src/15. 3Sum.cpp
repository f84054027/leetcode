/* brute force TLE
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        result.push_back({nums[i], nums[j], nums[k]});
                        for (int ind = 0; ind < result.size() - 1; ind++) {
                            if (result[ind][0] == nums[i] &&
                                result[ind][1] == nums[j] &&
                                result[ind][2] == nums[k]) {
                                result.pop_back();
                            }
                        }
                    }
                }
            }
        } 
        
        return result;
    }
};
*/
//from hints and discuss
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() <= 2) {
            return result;
        }
        int j, k;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2;) {
            int target = 0 - nums[i];
            int a = nums[i];
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                while (nums[j] + nums[k] > target && j < k) {
                    k--;
                } 
                while (nums[j] + nums[k] < target && j < k) {
                    j++;
                } 
                if (nums[j] + nums[k] == target && j < k) {
                    bool isIn = false;
                    for (int ri = 0; ri < result.size(); ri++) {
                       if (result[ri][0] < nums[i]) continue;
                       if (result[ri][0] > nums[i]) break;
                       if (result[ri][0] == nums[i] && 
                           result[ri][1] == nums[j] &&
                           result[ri][2] == nums[k]) {
                           isIn = true;
                       } 
                    }
                   if (result.size() == 0 || !isIn)  result.push_back({nums[i], nums[j], nums[k]});
                j++; 
                }
            }
                while(nums[i] == a && i < nums.size() -1) i++;
        }
         
        return result;
    }
};
