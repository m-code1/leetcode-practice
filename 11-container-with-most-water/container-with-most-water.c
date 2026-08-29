int maxArea(int* height, int heightSize) {
    int i = 0;
    int j = heightSize - 1;
    int max = 0;

    while (i < j) {

        int h;

        if (height[i] < height[j]) {
            h = height[i];
        } else {
            h = height[j];
        }

        int width = j - i;
        int area = h * width;

        if (area > max) {
            max = area;
        }

        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }

    return max;
}