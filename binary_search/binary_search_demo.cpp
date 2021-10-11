#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* creatSortedRandomList(int);
int* bubbleSorting(int*,int);
void printList(int*,int);
int binarySearch(int*, int, int);
void printBinarySearch(int*,int, int, int);
void printInfo();

int main() {
    
    int* list;
    int list_length = 0;
    int target = 0;
    int option = 0;
    int index = 0;
    bool run = true;
    while (run) {
        printInfo();
        scanf("%d", &option);
        switch (option) {
        case 1:
            //Creat a random length-decided list.
            printf("Decide the list length.\n");
            scanf("%d", &list_length);
            printf("\n");
            list = creatSortedRandomList(list_length);
            printList(list, list_length);

            //Decide the target.
            printf("Decide the target num.\n");
            scanf("%d", &target);
            printf("\n");
            //Binary Searching
            index = binarySearch(list, list_length, target);
            printf("The index of target is: %d\n\n", index);
            break;
        case 2:
            run = false;
            break;
        default:
            printf("Please input 1 or 2.\n");
        }
    }
    return 0;
}
void printInfo() {
    printf("\
############ Binary Search Demo ###########\n\
<1> Start Binary Search\n\
<2> Exit\n\
###########################################\n");
}

int* creatSortedRandomList(int len) {
    srand(time(NULL));
    int* list = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        list[i] = rand() % 100;
    }
    bubbleSorting(list, len);
    return list;
}

void printList(int* list,int len) {
    for (int i = 0; i < len;i++) {
        printf("%d ",list[i]);
    }
    printf("\n");
}

//argument *list and the length of such list, sort such list and return.
int* bubbleSorting(int* list,int len) {
    int temp = 0;
    bool sorted = true;
    for (int i = 0; i < len; i++) {
        sorted = true;
        for (int j = 1; j < len-i; j++) {
            if (list[j-1] > list[j]) {
                temp = list[j - 1];
                list[j - 1] = list[j];
                list[j] = temp;
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
    return list;
}

int binarySearch(int* list, int len, int target) {
    int a = 0;
    int b = len - 1;
    int mid = (a + b) / 2;
    printf("Searching process is shown as below, head and tail are marked by *.\n");
    while (list[a] != list[b]) {
        printBinarySearch(list, len, a, b);
        mid = (a + b) / 2;
        if (target > list[mid])
            a = mid;
        else if (target < list[mid])
            b = mid;
        else
            return mid;
        //printBinarySearch(list,len,a,b);
    }
    printf("\n");
    return a;
}

//print out the process of Binary search.
void printBinarySearch(int* list,int len,int a,int b) {
    for (int i = 0;i<len;i++) {
        if (i == a || i ==b)
            printf("%d* ",list[i]);
        else
            printf("%d ", list[i]);
    }
    printf("\n");
}
