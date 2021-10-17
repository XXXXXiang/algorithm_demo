#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void showBinary(unsigned int);
unsigned int BinaryToDecimial(unsigned __int32);
void showbinary(__int32);

struct node {
    int data;
    struct node* next;
};
typedef struct node NODE;

//int main() {
//  showBinary(1234);
//  BinaryToDecimial(0b10011010010);
//  return 0;
//}
//
void showBinary(unsigned int num) {
    int digit = 0;
    NODE* pre = NULL;
    NODE* cur = NULL;
    bool first = true;
    while (num) {
        cur = (NODE*)malloc(sizeof(NODE));
        digit = num % 2;
        num = num / 2;
        cur->data = digit;//creat the linked list by "steping back"
        cur->next = pre;
        pre = cur;
    }
    printf("\n");

    unsigned int sum = 0;
    for (NODE* ptr=cur;ptr!=NULL;ptr=ptr->next) {
        printf("%d",ptr->data);
        //sum = (sum << 1) | (ptr->data); //Build a binary number.
    }
    printf("\n");
    //printf("%d", sum);
}

void showbinary(__int32 num) {
    for (int i = 31;i>=0;i--) {
        printf("%d",(num>>i)&1);
    }
    printf("\n");
}


unsigned int BinaryToDecimial(unsigned __int32 biNum) {
    unsigned int sum = 0;
    int bit = 0;
    for (int i = 0;i<32;i++) {
        bit = biNum & 1;
        sum += bit * pow(2, i);
        biNum = biNum >> 1;
    }
    printf("%d\n",sum);
    return sum;
}
