#include <stdio.h>
void selection_sort(int *a, int n) {
  for (int i = 1; i <= n - 1; i++) {
    int min = i;
    for (int j = i + 1; j <= n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int swap = a[i];
    a[i] = a[min];
    a[min] = swap;
  }
}
int main() {
  int n, a[1000];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  selection_sort(a, n);
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  return 0;
}
