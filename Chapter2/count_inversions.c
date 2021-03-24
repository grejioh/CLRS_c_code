#include <stdio.h>
int merge(int *A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int count = 0;
  int L[n1 + 2], R[n2 + 2];
  for (int i = 1; i <= n1; i++) {
    L[i] = A[p + i - 1];
  }
  for (int i = 1; i <= n2; i++) {
    R[i] = A[q + i];
  }
  int i = 1;
  int j = 1;
  int k = p;
  while (i <= n1 && j <= n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      k++;
      i++;
    } else {
      A[k] = R[j];
      j++;
      k++;
      count += n1 - i + 1;
    }
  }
  for (; i <= n1; i++) {
    A[k] = L[i];
    k++;
  }
  for (; j <= n2; j++) {
    A[k] = R[j];
    k++;
  }
  return count;
}
int count_inversions(int *A, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    int count = 0;
    count += count_inversions(A, p, q);
    count += count_inversions(A, q + 1, r);
    count += merge(A, p, q, r);
    return count;
  } else
    return 0;
}
int main() {
  int a[1000], n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int answer = count_inversions(a, 1, n);
  printf("%d", answer);
  return 0;
}
