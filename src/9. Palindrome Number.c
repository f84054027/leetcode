bool isPalindrome(int x){
    
    char *s = malloc(sizeof(char) * 10);
    int front = 0, end = 0; 
    float mid;
    
    if (x < 0) {
        return false;
    }
    
    while (x / 10 != 0) {
        s[end++] = x % 10 + 48; // ascii of '0' == 48
        x /= 10;
        
    }
    
    s[end] = x + 48;
    
    mid = ((float) end - front) / 2;
    
    while (front < mid && end > mid) {
        if (s[front] != s[end]) {
            return false;
        }
        front++;
        end--;
    }
    free(s); 
    return true;

}
