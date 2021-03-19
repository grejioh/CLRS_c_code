#include <stdio.h>
void add2binary(int *a, int *b, int *c, int n) {
  int carry = 0; //"carry" means 进位
  for (int i = n; i >= 1; i--) {
    c[i + 1] = a[i] ^ b[i] ^ carry;
    carry = (a[i] + b[i] + carry) >> 1;
    c[1] = carry;
  }
  return;
}
int main() {
  int a[1000], b[1000], c[1000];
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  add2binary(a, b, c, n);
  for (int i = 1; i <= n + 1; i++) {
    printf("%d", c[i]);
  }
  return 0;
}
