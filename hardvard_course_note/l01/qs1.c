static void iswap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void qs(int* array, int n) {
    if (n > 1) {
        int pivot = array[n / 2];
        iswap(&array[n - 1], &array[n / 2]);
        int left = 0, right = n - 1;
        while (left < right) {
            if (array[left] <= pivot)
                ++left;
            else if (array[right - 1] > pivot)
                --right;
            else
                iswap(&array[left], &array[right - 1]);
        }
        iswap(&array[left], &array[n - 1]);
        qs(&array[0], left);
        qs(&array[left + 1], n - (left + 1));
    }
}
