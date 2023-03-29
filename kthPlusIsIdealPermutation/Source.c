void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int kth(int* arr, int len, int k) {
    if (len <= 1) {
        return arr[0];
    }
    int p = 0;
    int pivot = arr[p];
    swap(arr, arr + p);
    int i = 0;
    for (int j = 1; j < len; j++) {
        if (arr[j] - pivot < 0) {
            i++;
            swap(arr + i, arr + j);
        }
    }
    swap(arr, arr + i);
    if (i + 1 > k)
        return kth(arr, i, k);
    if (i + 1 == k)
        return arr[i];
    return kth(arr + i + 1, len - i - 1, k - i - 1);
}

int findKthLargest(int* nums, int numsSize, int k) {
    return kth(nums, numsSize, numsSize - k + 1);
}



bool isIdealPermutation(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++)
        if (abs(nums[i] - i) > 1)
            return false;
    return true;
}