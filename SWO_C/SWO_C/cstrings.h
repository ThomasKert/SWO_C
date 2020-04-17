#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getStringLength(char *cstring) {
  int length = 0;
  if (cstring == NULL) {
    return 0;
  }
  while (*(cstring + length) != NULL) {
    length++;
  }
  return length;
}
void printString(char *cstring) {
  int length = getStringLength(cstring);
  for (int i = 0; i < length; i++) {
      printf("%c", *(cstring + i));
  }
  printf("\n");
}

char* addString(char* a, char* b) {
  int resLength = getStringLength(a) + getStringLength(b);
  char* result = malloc((resLength + 1) * sizeof(char));
  int j = 0;
  for (int i = 0; i < getStringLength(a); i++) {
    result[i] = a[i];
  }
  for (int i = getStringLength(a); i < resLength; i++) {
    result[i] = b[j];
    j++;
  }
  result[resLength] = '\0';
  return result;
}

char* mixString(char *a, char *b) {
  int i = 0;
  int curLength = 0;
  int resLength = getStringLength(a) + getStringLength(b);
  char* result = malloc((resLength + 1) * sizeof(char));
  while (curLength < resLength) {
    if (a[i] != NULL && i < getStringLength(a)){
      result[curLength] = a[i];
      curLength++;
    }
    if (b[i] != NULL && i < getStringLength(b)) {
      //generell beides möglich
      result[curLength] = b[i];
      //*(result + curLength) = *(b + i);
      curLength++;
    }
    i++;
  }
  result[resLength] = '\0';
  return result;
}

char* removeCharFromString(char* string, char rmChar) {
  int length = getStringLength(string);
  int resIndex = 0;
  char* resultString = malloc((length + 1) * sizeof(char));
  for (int i = 0; i < length; i++) {
    if (string[i] != rmChar) {
      resultString[resIndex] = string[i];
      resIndex++;
    }
  }
  resultString[resIndex] = '\0';
  return resultString;
}

bool compareStrings(char* string1, char* string2) {
  int maxLength = 0;
  if (getStringLength(string1) != getStringLength(string2)) {
    return false;
  }
  if (getStringLength(string1) > getStringLength(string2)) {
    maxLength = getStringLength(string1);
  }
  else {
    maxLength = getStringLength(string2);
  }
  for (int i = 0; i < maxLength; i++) {
    if (string1[i] != string2[i]){
      return false;
    }
  }
  return true;
}

char* stringCopy(char* copyFrom, char *copyTo, size_t n) {
  int index = 0;
  char* result = malloc((n) * sizeof(char));
  while (index <= n && index < getStringLength(copyTo)) {
    result[index] = copyTo[index];
    index++;
  }
  int secondIndex = 0;
  while (index <= n && index < (getStringLength(copyFrom) + getStringLength(copyTo))) {
    result[index] = copyFrom[secondIndex];
    secondIndex++;
    index++;
  }
  result[n] = '\0';
  return result;
}

bool containsChar(char* string, char c) {
  for (int i = 0; i < getStringLength(string); i++) {
    if (string[i] == c) {
      return true;
    }
  }
  return false;
}

int countChar(char* string, char c) {
  int count = 0;
  for (int i = 0; i < getStringLength(string); i++) {
    if (string[i] == c) {
      count++;
    }
  }
  return count;
}