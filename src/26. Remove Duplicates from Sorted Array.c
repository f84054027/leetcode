int removeDuplicates(int* nums, int numsSize){
    
    int k = 0;
    if (numsSize == 0) {
        return 0;
    } 
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[k]) {
            k++;
            nums[k] = nums[i];
        }
    }
    
    return k + 1;

}
