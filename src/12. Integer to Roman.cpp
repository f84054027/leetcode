class Solution {
public:
    string intToRoman(int num) {
        string s;
        int arr[12] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4};
        string r[12] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV"};
        int n; 
        for (int i = 0; i < 12; i++) {
            n = num / arr[i];
            
            num %= arr[i];
             
            while(n > 0) {
               s += r[i];
               n--; 
            }
        }
        
        while(num > 0) {
           s += "I";
           num--; 
        }
       
        return s;
    }
};
