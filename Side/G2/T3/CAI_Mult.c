#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void basic();
void intermediate();
void expert();
int rm();
int rm2();
int ra1();
int ra2();
int ra3();
int ra4();
int ra5();
int ra6();
int ra7();
int ra8();
void yey(int);
void error(int);

int main(char input) {
  printf("Mode\na - Basic\nb - Intermediate\nc - Expert\nd - Negatives\n");
  input = getchar();
  int result,buffer,message,messageW;
  // ** DEBUG ** printf("** DEBUG ** -- NO INPUT -- ** DEBUG **\n");
  if (input == 'a') {
    // ** DEBUG ** printf("** DEBUG ** -- %c -- ** DEBUG **\n",input);
    basic();
  }
  if (input == 'b') {
    // ** DEBUG ** printf("** DEBUG ** -- %c -- ** DEBUG **\n",input);
    intermediate();
  }
  if (input == 'c') {
    // ** DEBUG ** printf("** DEBUG ** -- %c -- ** DEBUG **\n",input);
    expert();
  }
  if (input == 'd') {
    // ** DEBUG ** printf("** DEBUG ** -- %c -- ** DEBUG **\n",input);
    buffer = 0;
    while (buffer != 5) {
      int a = ra7(),b = ra8();
      while (result != (a*b)) {
        printf("What is the result of %d times %d\n",a,b);
        scanf("%d",&result);
        message = rm();
        messageW = rm2();
        // ** DEBUG ** printf("%d\n",result);
        if (result == (a*b)) {
          yey(message);
        }
        else error(messageW);
      }
      result = -1;
      buffer++;
    }
  }
  if ((input != 'a')&&(input != 'b')&&(input != 'c')&&(input != 'd') ) {
     printf("*sad_smiley_face.png\n");
  }
  return 0;
}


void basic() {
  int result,buffer,message,messageW;
  buffer = 0;
  while (buffer != 5) {
    int a = ra1(),b = ra2();
    while (result != (a*b)) {
      printf("What is the result of %d times %d\n",a,b);
      scanf("%d",&result);
      message = rm();
      messageW = rm2();
      // ** DEBUG ** printf("%d\n",result);
      if (result == (a*b)) {
        yey(message);
      }
      else error(messageW);
    }
    result = -1;
    buffer++;
  }
}

void intermediate() {
  int result,buffer,message,messageW;
  buffer = 0;
  while (buffer != 5) {
    int a = ra3(),b = ra4();
    while (result != (a*b)) {
      printf("What is the result of %d times %d\n",a,b);
      scanf("%d",&result);
      message = rm();
      messageW = rm2();
      // ** DEBUG ** printf("%d\n",result);
      if (result == (a*b)) {
        yey(message);
      }
      else error(messageW);
    }
    result = -1;
    buffer++;
  }
}

void expert() {
  int result,buffer,message,messageW;
  buffer = 0;
  while (buffer != 5) {
    int a = ra5(),b = ra6();
    while (result != (a*b)) {
      printf("What is the result of %d times %d\n",a,b);
      scanf("%d",&result);
      message = rm();
      messageW = rm2();
      // ** DEBUG ** printf("%d\n",result);
      if (result == (a*b)) {
        yey(message);
      }
      else error(messageW);
    }
    result = -1;
    buffer++;
  }
}


int ra1() {
  srand(time(NULL));
  int r = rand() % 9 + 0;
  return r;
}
int ra2() {
  srand(time(NULL)*(time(NULL)));
  int r = rand() % 9 + 0;
  return r;
}
int ra3() {
  srand(time(NULL));
  int r = rand() % 99 + 0;
  return r;
}
int ra4() {
  srand(time(NULL)*(time(NULL)));
  int r = rand() % 99 + 0;
  return r;
}
int ra5() {
  srand(time(NULL));
  int r = rand() % 999 + 0;
  return r;
}
int ra6() {
  srand(time(NULL)*(time(NULL)));
  int r = rand() % 999 + 0;
  return r;
}

int ra7() {
  srand(time(NULL));
  int r = rand() % 9 + 0;
  return r;
}
int ra8() {
  srand(time(NULL)*(time(NULL)));
  int r = rand() % 9 + -9;
  return r;
}


int rm() {
  srand(time(NULL));
  int r = rand() % 3 + 1;
  return r;
}
int rm2() {
  srand(time(NULL)*(time(NULL)));
  int r = rand() % 3 + 1;
  return r;
}

void yey(int a) {
  if (a == 1) {
    printf("!!Great!!\nYou're killing it!\n");
  }
  else if (a == 2) {
    printf("!!Very Good!!\nYou got it right.\n");
  }
  else
  printf("!!Wow!!\nEven I couldn't do that one\n");
}
void error(int a) {
  if (a == 1) {
    printf("Oh No...\nTry again.\n");
  }
  else if (a == 2) {
    printf("BzzzzZZT...\n\n\n!!   ERROR   !!\n\n\nPlease try again.\n");
  }
  else if (a == 3) {
    printf("Don't give up.\nYou can do it.\n");
  }
}
