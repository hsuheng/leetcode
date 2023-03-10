/**
 * 22ms, 7.1MB
 */
int search(int* nums, int numsSize, int target);
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int rest = 0;
    int index2 = 0;
    int* index = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i = 0; i < numbersSize; i++){
        index2 = search(numbers, numbersSize, target - numbers[i]);
        if(index2 != -1 && i != index2){
            if(i > index2){
                index[0] = index2 + 1;
                index[1] = i + 1;
            }
            else{
                index[0] = i + 1;
                index[1] = index2 + 1;
            }
            return index; 
        }
    }
    return -1;
}
int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1;
    int mid = 0;
    while(left <= right){
        mid = left + (right - left)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1; 
}
/**
 * 19ms, 7.4MB
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left = 0, right = numbersSize - 1, sum = 0;
    *returnSize = 2;
    int* index = (int*)malloc(2 * sizeof(int));
    while(left < right){
        sum = numbers[left] + numbers[right];
        if(sum == target){
            index[0] = left + 1;
            index[1] = right + 1;
            return index;
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return -1;
}