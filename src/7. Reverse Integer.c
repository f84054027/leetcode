int reverse(int x){
    int sign, result = 0;
    int lim = INT_MAX / 10; 
    
    if (x == INT_MIN) {
        return 0;
    } 
    
    if (x < 0) {
        sign = -1;
        x = -x;
    } else {
        sign = 1;
    }
    
    while(x / 10 != 0) {
        result += x % 10;
        if (result > lim) {
            return 0;
        }
        result *= 10;
        x /= 10;
    }
    
    result += x;

    return sign * result;
}
