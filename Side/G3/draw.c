#include <stdio.h>

void pointyBOI(int a) {
  int s=0,b=1,line=0,column=0;
  char c='A';
  a=4;
  // 2(n-linha)(espacos)//
  while (line != a) {
    while (s != 2*(a-line)) {
      printf(" ");
      s++;
      // ** DEBUG ** printf("//DEBUG\\");
    }
    s = 0;
      while (column != b) {
        if (column >= (b/2)) {
        // ** DEBUG ** printf("DEBUG");
        printf(" %c",c);
        c--;
      }
      else{
        // ** DEBUG ** printf("DEBUG");
        printf(" %c",c);
        c++;
      }
      column++;

    }
    printf("\n");
    c = 'A';
    b = b + 2;
    line++;
    column = 0;
  }
  // ** DEBUG ** printf("%d\n",(b/2));
}

void /*kiteKun*/main(int a) {
  // ** DEBUG ** printf("%d\n",(b/2));
  a=4;
  int s=0,b=1,line=0,column=0;
  char c='A';
  while (line != (a*2)-1){
    if (line <= a) {
      while (s != 2*(a-line)) {
        printf(" ");
        s++;
        // ** DEBUG ** printf("//DEBUG\\");
      }
      s = 0;
        while (column != b) {
          if (column >= (b/2)) {
          // ** DEBUG ** printf("DEBUG");
          printf(" %c",c);
          c--;
        }
        else{
          // ** DEBUG ** printf("DEBUG");
          printf(" %c",c);
          c++;
        }
        column++;

      }
      printf("\n");
      c = 'A';
      b = b + 2;
      line++;
      column = 0;
    }
    else{
      while (s != 2*(a-line)) {
        printf(" ");
        s++;
        // ** DEBUG ** printf("//DEBUG\\");
      }
      s = 0;
        while (column != b) {
          if (column >= (b/2)) {
          // ** DEBUG ** printf("DEBUG");
          printf(" %c",c);
          c--;
        }
        else{
          // ** DEBUG ** printf("DEBUG");
          printf(" %c",c);
          c++;
        }
        column++;

      }
      printf("\n");
      c = 'A';
      b = b - 2;
      line++;
      column = 0;
    }
  }
}
/*void pentagonPlus1(int a) {
*/
