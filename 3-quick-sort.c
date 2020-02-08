#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int l, int h) {
    int pivot, i, j;
    pivot = a[l];
    i = l + 1;
    j = h;
    while(i <= j) {
        if(a[i] > pivot && a[j] < pivot) swap(&a[i], &a[j]);
        if(a[i] < pivot) i++;
        if(a[j] > pivot) j--;
    }
    swap(&a[l], &a[j]);
    return j;
}

void quick_sort(int *a, int l, int h) {
    int pi;
    if(l < h) {
        pi = partition(a, l, h);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, h);
    }
}

int main() {
    int *a, n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
    for(i = 0; i < n; i++) scanf("%d", a + i);
    quick_sort(a, 0, n - 1);
    printf("test\n");
    for(i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}