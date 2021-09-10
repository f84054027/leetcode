/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int cmp(const void *a, const void *b) {
   return *(int *)a - *(int *)b;
}
    
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    
    int *sortednums = malloc(sizeof(int) * numsSize);
    int *result = malloc(sizeof(int) * 2);
    int end = numsSize - 1;
    int n1, n2;
    
    for (int i = 0; i < numsSize; i++) {
        sortednums[i] = nums[i];
    }
    qsort(sortednums, numsSize, sizeof(sortednums[0]), cmp);
 
    for (int i = 0; i < numsSize -1; i++) {
        
        while (sortednums[i] + sortednums[end] > target) {
            end--;
        }
        if (sortednums[i] + sortednums[end] == target) {
            n1 = sortednums[i];
            n2 = sortednums[end];
            break;
        }

    }
    
    int s = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == n1 || nums[i] == n2) {
            result[s++] = i;
        }
    }
    
    free(sortednums);
    *returnSize = 2;
    return result;
}
