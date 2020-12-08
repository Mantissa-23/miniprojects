#!/bin/sh
a=$(tr -cd "'[<>+-.,\[\]']'" < $1 |
sed '
s/'"'"'//g;
s/\+/++*p;/g;
s/-/--*p;/g;
s/>/++p;/g;
s/</--p;/g;
s/\./putchar(*p);/g;
s/,/*p=getchar();/g;
s/\[/while(*p){/g;
s/\]/}/g;');
printf "#include <stdio.h>\nint main(){char f[30000]={0};char *p=f;$a}" | gcc -x c - && ./a.out
