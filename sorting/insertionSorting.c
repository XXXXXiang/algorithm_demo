void insertionSorting(int* arr, int len) {
    for (int i = 0;i<len;i++) {
        int key = arr[i];
        int j = i;
        while (key <arr[j-1] && j>0) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
