#include <stdio.h>
void insertion_sort(int *a, int n) {
  for (int j = 2; j <= n; j++) {
    int key = a[j];
    int i = j - 1;
    while (i > 0 && a[i] > key) {
      a[i + 1] = a[i];
      i--;
    }
    a[i + 1] = key;
  }
}
int main() {
  int n, a[1000];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  insertion_sort(a, n);
  for (int i = 1; i <= n; i++)
    printf("%d ", a[i]);
  return 0;
}
