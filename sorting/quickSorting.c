void quickSorting(int* arr, int len) {
    int pivot = arr[0];
    int i = 1;
    int j = len - 1;
    if (len <= 1 || i>=j)
        return;
    while (i<j){
        while (arr[j] >= pivot && i < j)
            j--;
        while (arr[i] <= pivot && i<j)
            i++;
        if (i == j)
            break;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    arr[0] = arr[i];
    arr[i] = pivot;
    quickSorting(arr,i-1);
    quickSorting(arr + i + 1, len - 1 - i);
}
