/* TLE
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int max = 0;
        if (height.size() == 0) {
            return 0;
        }
        
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int h = (height[i] < height[j]) ? height[i] : height[j];
                if (max < (j - i) * h) {
                    max = (j - i) * h;
                }
            }
        }
        
        return max;
    }
};
*/ // solution from discuss
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max = 0;
        while (i < j) {
            int h = (height[i] < height[j]) ? height[i] : height[j];
            if (max < (j - i) * h) {
                max = (j - i) * h;
            }
            while(height[i] <= h && i < j) {
                i++;
            }
            while(height[j] <= h && i < j) {
                j--;
            }
        }
        
        return max;
    }
};
