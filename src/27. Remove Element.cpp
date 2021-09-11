/*class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start, k = 0;
        bool found = false; 
        sort(nums.begin(), nums.end());
         
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                if (!found) {
                    start = i;
                    found = true; 
                }
                k++;
            } 
        }
        
        if (found) {
            for (int i = start + k; i < nums.size(); i++) {
               nums[i - k] = nums[i];
            }
        }
        
        return nums.size() - k;
    }
};

*/
//from hints
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        
        if (nums.size() == 0) {
            return 0;
        } 
        
        while(nums[j] == val && j > 0) {
            j--;
        }
        j = (nums[j] == val)? j - 1 : j;
        while (i < j) {
            if (nums[i] == val) {
               nums[i] = nums[j];
               nums[j] = val;
               j--;
               while (nums[j] == val) {
                   j--;
               }
            }
            i++;
        }
        if (j < 0) {
            return 0;
        } 
        return j + 1;
    }
};
