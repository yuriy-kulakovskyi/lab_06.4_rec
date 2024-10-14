#include "../include/main.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int CreateArray(int* a, int n, int i) {
  if (i < n) {
    cout << "Enter a value for a[" << i << "]: ";
    cin >> a[i];
    CreateArray(a, n, i + 1);
  }

  return 0;
}

int PrintArray(int* a, int n, int i) {
  if (i < n) {
    cout << setw(4) << a[i];
    PrintArray(a, n, i + 1);
  }

  return 0;
}

int FindTheLargest(int* a, int n, int i) {
  if (i == n - 1) {
    return a[i];
  }

  int max_in_rest = FindTheLargest(a, n, i + 1);

  if (abs(a[i]) > abs(max_in_rest)) {
    return a[i];
  } else {
    return max_in_rest;
  }
}

void SumHelper(int* a, int n, int i, int& sum, bool foundFirstPositive) {
  if (i == n) return;

  if (a[i] > 0) {
    if (foundFirstPositive) return;
    foundFirstPositive = true;
  } else if (foundFirstPositive) {
    sum += a[i];
  }

  SumHelper(a, n, i + 1, sum, foundFirstPositive);
}

int Sum(int* a, int n, int i, int sum) {
  SumHelper(a, n, i, sum, false);
  return sum;
}

void FillZeros(int* modified, int n, int& nonZeroIndex) {
  if (nonZeroIndex == n) return;
  modified[nonZeroIndex++] = 0;
  FillZeros(modified, n, nonZeroIndex);
}

void SortHelper(int* a, int* modified, int n, int i, int& nonZeroIndex) {
  if (i == n) return;

  if (a[i] != 0) {
    modified[nonZeroIndex++] = a[i];
  }

  SortHelper(a, modified, n, i + 1, nonZeroIndex);
}

void CopyBack(int* a, int* modified, int n, int i) {
  if (i == n) return;

  a[i] = modified[i];
  CopyBack(a, modified, n, i + 1);
}

void Sort(int* a, int n) {
  int* modified = new int[n];
  int nonZeroIndex = 0;

  SortHelper(a, modified, n, 0, nonZeroIndex);
  FillZeros(modified, n, nonZeroIndex);
  CopyBack(a, modified, n, 0);

  delete[] modified;
}