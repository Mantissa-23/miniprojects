#include <stdio.h>

int main() {
  char f[30000] = {0};
  char *p = f;

  while (*p) {
    *p = getchar();
    putchar(*p);
    while (*p) {
      putchar(*p);
    }
    *p = getchar();
    putchar(*p);
    putchar(*p);
    *p = getchar();
    *p = getchar();
    *p = getchar();
    ++*p;
    *p = getchar();
    --*p;
    *p = getchar();
    --p;
    ++p;
    *p = getchar();
    while (*p) {
    }
    putchar(*p);
    putchar(*p);
  }
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  while (*p) {
    ++p;
    ++*p;
    ++*p;
    ++*p;
    ++*p;
    while (*p) {
      ++p;
      ++*p;
      ++*p;
      ++p;
      ++*p;
      ++*p;
      ++*p;
      ++p;
      ++*p;
      ++*p;
      ++*p;
      ++p;
      ++*p;
      --p;
      --p;
      --p;
      --p;
      --*p;
    }
    ++p;
    ++*p;
    ++p;
    ++*p;
    ++p;
    --*p;
    ++p;
    ++p;
    ++*p;
    while (*p) {
      --p;
    }
    --p;
    --*p;
  }
  ++p;
  ++p;
  putchar(*p);
  ++p;
  --*p;
  --*p;
  --*p;
  putchar(*p);
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  ++*p;
  putchar(*p);
  putchar(*p);
  ++*p;
  ++*p;
  ++*p;
  putchar(*p);
  ++p;
  ++p;
  putchar(*p);
  --p;
  --*p;
  putchar(*p);
  --p;
  putchar(*p);
  ++*p;
  ++*p;
  ++*p;
  putchar(*p);
  --*p;
  --*p;
  --*p;
  --*p;
  --*p;
  --*p;
  putchar(*p);
  --*p;
  --*p;
  --*p;
  --*p;
  --*p;
  --*p;
  --*p;
  --*p;
  putchar(*p);
  ++p;
  ++p;
  ++*p;
  putchar(*p);
  ++p;
  ++*p;
  ++*p;
  putchar(*p);
}
