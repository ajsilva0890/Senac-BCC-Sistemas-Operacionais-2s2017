#include <stdio.h>
#include <stdlib.h>

int main (){
  FILE *p;
  p = fopen("sbr.bin","rb");
  char c;
  int i = 0;

  if (!p) {
    printf("Erro na abertura de arquivo");
    exit(1);
  }

  while (feof(p)) {
    c = getc(p);
    if (i%4 == 0) {
      printf(" ");
    }
    printf("%02X", (unsigned char)c);
  }
  int fclose (FILE *p);
  return 0
}
