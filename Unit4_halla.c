/*
Joseph Halla
9/10/2023
Unit 4: Linux Assignment
calculate mean and standard deviation for specified array
*/

#include <math.h>
#include <stdio.h>

int main() {
  int grades[] = {34, 47, 53, 88, 92, 67, 95, 83, 99, 72};
  int numGrades = 10;
  double sum = 0.0;
  double mean = 0.0;
  double variance = 0.0;
  double stdDeviation = 0.0;

  // Calculate the mean (average) of the grades
  for (int i = 0; i < numGrades; i++) {
    sum += grades[i];
  }
  mean = sum / numGrades;

  // Calculate the variance
  for (int i = 0; i < numGrades; i++) {
    variance += pow(grades[i] - mean, 2);
  }
  variance /= numGrades - 1;

  // Calculate the standard deviation
  stdDeviation = sqrt(variance);

  // Output the results
  printf("Mean: %.2lf\n", mean);
  printf("Standard Deviation: %.2lf\n", stdDeviation);

  return 0;
}
