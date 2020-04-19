#pragma once
#include "cstring.h"
#include "Nachklausur2019.h"

void testStringFunctions() {
  char cstring[] = "aaaaaaa";
  char cstring2[] = "bb";

  printf("String 1:\n");
    printString(cstring);
    printf("Length: %d\n", getStringLength(cstring));
  printf("String 2:\n");
    printString(cstring2);
    printf("Length: %d\n", getStringLength(cstring2));
  printf("String 1 + String 2:\n");
    printString(addString(cstring, cstring2));
    printf("Length: %d\n", getStringLength(addString(cstring, cstring2)));

  printf("Length of an empty cstring:\n");
    char* res = NULL;
    printf("%d\n", getStringLength(res));
  printf("Mixing String 1 and String 2 and testing Zuweisung to empty String:\n");
    res = mixString(cstring, cstring2);
    printString(res);
    printf("Length: %d\n", getStringLength(res));
  printf("Removing 'a' from result of mixing:\n");
    res = removeCharFromString(res, 'a');
    printString(res);
    printf("Length: %d\n", getStringLength(res));
    printf("Copying String 2 onto String 1 with n = 9: \n");
      res = stringCopy(cstring2, cstring, 9);
      printString(res);
    printf("Copying String 2 onto String 1 with n = 5: \n");
      res = stringCopy(cstring2, cstring, 5);
      printString(res);
    printf("cstring = cstring:\n");
      printf("%d\n", compareStrings(cstring, cstring));
    printf("cstring = cstring2:\n");
      printf("%d\n", compareStrings(cstring, cstring2));
    printf("cstring2 = cstring:\n");
      printf("%d\n", compareStrings(cstring2, cstring));
    printf("cstring2 = cstring2:\n");
      printf("%d\n", compareStrings(cstring2, cstring2));
    printf("res = cstring2:\n");
      printf("%d\n", compareStrings(res, cstring2));
    printf("res = res:\n");
      printf("%d\n", compareStrings(res, res));
    printf("aaa = bbb:\n");
      printf("%d\n", compareStrings("aaa", "bbb"));
    printf("aaa = aab:\n");
      printf("%d\n", compareStrings("aaa", "aab"));
    res = "aaccddeeffgghh";
    printf("Testing contains and count with \"aaccddeeffgghh\":\n");
      printf("containsChar e: %d\n", containsChar(res, 'e'));
      printf("containsChar b: %d\n", containsChar(res, 'b'));
      printf("containsChar a: %d\n", containsChar(res, 'a'));
      printf("containsChar h: %d\n", containsChar(res, 'h'));
      printf("countChar e: %d\n", countChar(res, 'e'));
      printf("countChar b: %d\n", countChar(res, 'b'));
      printf("countChar a: %d\n", countChar(res, 'a'));
      printf("countChar h: %d\n", countChar(res, 'h'));
      printf("Some tests, need to be changed later:\n");
        char* test = "iuzfhs";
        stringCopyReference(test, &test, 10);
        printString(test);
}

void testNachklausur2019() {
  int size_a = 5;
  int size_a1 = 0;
  int size_a2 = 0;
  int* a1 = 0;
  int* a2 = 0;
  int size_b = 3;
  int size = 0;
  int* a = malloc(size_a * sizeof(int));
    a[0] = 2;
    a[1] = 9;
    a[2] = 32;
    a[3] = 1;
    a[4] = 17;
  int* b = malloc(size_b * sizeof(int));
    b[0] = 111;
    b[1] = 222;
    b[2] = 111;

  int* res = arrcat(a, size_a, b, size_b, &size);
    printf("printing Result:\n");
      for (int i = 0; i < size; i++) {
        printf("%d\n", res[i]);
      }
  split(isEven, a, size_a, &a1, &size_a1, &a2, &size_a2);
    printf("printing a1:\n");
      for (int i = 0; i < size_a1; i++) {
        printf("%d\n", a1[i]);
      }
    printf("printing a2:\n");
      for (int i = 0; i < size_a2; i++) {
        printf("%d\n", a2[i]);
      }
}

//void strcpy(char* string1, char** copyTo) {
//  *copyTo = string1;
//  printf("%c", *copyTo[0]);
//}


int main(){

  testStringFunctions();
  testNachklausur2019();
  return 0;
}
