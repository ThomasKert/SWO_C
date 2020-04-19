#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
###############
###Aufgabe 1###
###############
*/

//1a
int* arrcat(int* a, int size_a, int* b, int size_b, int* size) {
  *size = 0;
  int* result = (int*)malloc(sizeof(int) * (size_a + size_b));
  if (result != NULL) {
    *size = size_a + size_b;
    for (int i = 0; i < size_a; i++) {
      result[i] = a[i];
    }
    for (int j = 0; j < size_b; j++) {
      result[size_a + j] = b[j];
    }
  }
  return result;
}

//1b:
typedef bool(*int_predicate_ptr)(int);
void split(int_predicate_ptr fctPtr, int* a, int size_a, int** a1, int* size_a1, int** a2, int* size_a2) {
  *size_a1 = 0;
  *size_a2 = 0;
  *a1 = (int*)malloc(sizeof(int) * size_a);
  *a2 = (int*)malloc(sizeof(int) * size_a);
  if (a1 != NULL && a2 != NULL) {
    for (int i = 0; i < size_a; i++) {
      if (fctPtr(a[i])) {
        (*a1)[*size_a1] = a[i];
        (*size_a1)++;
      }
      else {
        (*a2)[*size_a2] = a[i];
        (*size_a2)++;
      }
    }
  }
}

bool isEven(int number) {
  if (number % 2 == 0) {
    return true;
  }
  else {
    return false;
  }
}
/*
###############
###Aufgabe 2###
###############
*/