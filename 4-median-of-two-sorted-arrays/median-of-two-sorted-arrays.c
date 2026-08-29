double findMedianSortedArrays(
    int* nums1, 
    int nums1Size, 
    int* nums2, 
    int nums2Size) {
    if(nums1Size > nums2Size) {
        int* temp = nums1;
        nums1 = nums2;
        nums2 = temp;

        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }
    int total = nums1Size + nums2Size;
    int half = (total + 1) / 2;

    int left = 0;
    int right = nums1Size;

    while(left <= right) {
        int i = (left + right) / 2;
        int j = half - i;

        if(i>0 && j < nums2Size && nums1[i-1] > nums2[j]) {
            right = i - 1;
        } else if (j>0 && i < nums1Size && nums2[j-1] > nums1[i]) {
            left = i + 1;
        } else {
            int leftMax;
            if (i == 0) {
                leftMax = nums2[j - 1];
            } else if(j == 0) {
                leftMax = nums1[i - 1];
            } else {
                if(nums1[i - 1] > nums2[j -1]) {
                    leftMax = nums1[i - 1];
                } else {
                    leftMax = nums2[j - 1];
                }
            }
            if (total % 2 == 1) {
                return(double)leftMax;
            }

            int rightMin;

            if (i == nums1Size) {
                rightMin = nums2[j];
            } else if(j == nums2Size) {
                rightMin = nums1[i];
            } else {
                if(nums1[i] < nums2[j]) {
                    rightMin = nums1[i];
                } else {
                    rightMin = nums2[j];
                }
            }

            return ((double)leftMax + rightMin) / 2.0;
        }
    }

    return 0.0;
}