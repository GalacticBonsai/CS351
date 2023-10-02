/*
Joseph Halla
9/17/2023
Unit 5: Linux Assignment
calculate mean and standard deviation for user specified array
*/
#include <math.h>
#include <stdio.h>

int main() {
  int input, count = 0;
  int sum = 0, sumOfSquares = 0;
  int max = 0, min = __INT_MAX__;

  printf("Enter non-negative integers (terminate with a negative value):\n");

  while (1) {
    scanf("%d", &input);

    if (input < 0) {
      break; // Terminate the loop when a negative value is encountered
    }

    // Update statistics
    count++;
    sum += input;
    sumOfSquares += input * input;

    // Update min and max
    if (input < min) {
      min = input;
    }
    if (input > max) {
      max = input;
    }
  }

  if (count == 0) {
    printf("No proper inputs were provided.\n");
  } else {
    // Calculate mean and standard deviation
    double mean = (double)sum / count;
    
    // This is gets the real variance, I verified with variance and standard deviation calculators online. 
    // I'm having trouble reproducing your results because you're using the wrong equation.
    double variance = ((double)sumOfSquares / (count )) - (mean * mean);
    double stdDeviation = sqrt(variance);

    // Output the results
    printf("Number of proper inputs: %d\n", count);
    printf("Mean: %.2lf\n", mean);
    printf("Standard Deviation: %.2lf\n", stdDeviation);
    printf("Range: [%d, %d]\n", min, max);
  }

  return 0;
}
