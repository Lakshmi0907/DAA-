#include<stdio.h>
#include<stdlib.h>
void sort(int *a,int n) {
    int i, j;
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j]) {
                a[i] = a[i] + a[j];
                a[j] = a[i] - a[j];
                a[i] = a[i] - a[j];
            }                
}
int main() {
    int n, *a, i, k, l, m, h;
    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (int*) malloc(n * sizeof(int));
    printf("Enter %d elements\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, n);
    l = 0;
    h = n - 1;
    printf("Enter an element to search:\n");
    scanf("%d", &k);
    while(l < h){
        m = (l + h) / 2;
        if(a[m] == k) break;
        if(k < a[m]) h = m - 1;
        else l = m + 1;
    }
    if(l < h) printf("%d found\n", k);
    else printf("%d not found\n", k);
    return 0;
}
