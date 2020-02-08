#include<stdio.h>
#include<stdlib.h>

void merge(int *a, int l, int m, int h) {
    int *b, n, i, j, k;
    n = h -l + 1;
    b = (int*) malloc(n * sizeof(int));
    i = l;
    j = m + 1;
    k = 0;
    while(i <= m && j <= h) {
        if(a[i] < a[j]) b[k++] = a[i++];
        else if(a[i] > a[j]) b[k++] = a[j++];
        else {
            b[k++] = a[i++];
            j++;
        }
    }
    while(i <= m) b[k++] = a[i++];
    while(j <= h) b[k++] = a[j++];
    for(i = 0; i < n; i++) a[l + i] = b[i];
}

void merge_sort(int *a, int l, int h) {
    int m;
    if(l < h) {
        m = (l + h) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, h);
        merge(a, l, m, h);
    }
}

int main() {
    int *a, n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d", a + i);
    merge_sort(a, 0, n - 1);
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}