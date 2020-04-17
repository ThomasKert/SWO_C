#include <stdio.h>
#include "cstrings.h"

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
    //ToTest:
    res = "aaccddeeffgghh";
    printf("Testing contains and count with \"aaccddeeffgghh\":\n");
    printf("containsChar e: %d\n", containsChar(res, 'e'));
    printf("containsChar b: %d\n", containsChar(res, 'b'));
    printf("countChar e: %d\n", countChar(res, 'e'));
    printf("countChar b: %d\n", countChar(res, 'b'));
      //StringCount
}


int main(){

  testStringFunctions();
  return 0;
}
