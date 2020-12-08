#include <stdio.h>

FILE *i;
char a[30000] = {0};
char *p = a;

void interpret(char c) {
  switch(c) {
    case '>':
      ++p;
      break;
    case '<':
      --p;
      break;
    case '+':
      ++*p;
      break;
    case '-':
      --*p;
      break;
    case '.':
      putchar(*p);
      break;
    case ',':
      *p=getchar();
      break;
    case '[':
      if(p)

  }
}

int main(int argc, char *argv[]) {
  FILE *fp;
  fp = fopen(argv[1], "r");
  i = fp;
}
