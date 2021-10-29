void bubbleSorting(int* arr, int len) {
    for (int i = 0;i<len;i++) {
        bool sorted = true;
        for (int j = 1; j < len - i;j++) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}
