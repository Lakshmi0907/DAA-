#include<stdio.h>
#include<stdlib.h>

void min_max(int *a, int l, int h, int *min, int *max) {
    int m, p, q;
    if(l == h) *min = *max = a[l];
    else if(l == h + 1) {
        if(a[l] < a[h]) {
            *min = a[l];
            *max = a[h];
        }
        else {
            *min = a[h];
            *max = a[l];
        }
    }
    else if(l < h) {
        m = (l + h) / 2;
        min_max(a, l, m, min, max);
        min_max(a, m + 1, h, &p, &q);
        if(p < *min) *min = p;
        if(q > *max) *max = q;
    }
}

int main() {
    int n, *a, i, min, max;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++) scanf("%d", a + i);
    min_max(a, 0, n - 1, &min, &max);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    return 0;
}