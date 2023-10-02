/*
Joseph Halla
2023-09-24
CS351 Computer Operating Systems - Unit 6 Linux Assignment
Program to calculate system time and statistics for random numbers
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILE_PATH "/proc/uptime"
#define NUM_COUNT 100000
#define MAX_RAND 1000

int main() {
  // Read start times
  double startTotalTime, startIdleTime;
  FILE *file = fopen(FILE_PATH, "r");
  if (!file) {
    perror("Failed to open /proc/uptime");
    return 1;
  }
  fscanf(file, "%lf %lf", &startTotalTime, &startIdleTime);
  fclose(file);

  // Generate 100,000 random integers in range [1, 1000]
  srand(time(NULL));
  int i;
  double sum = 0, squaredSum = 0;
  for (i = 0; i < NUM_COUNT; i++) {
    int randNum = (rand() % MAX_RAND) + 1;
    sum += randNum;
    squaredSum += randNum * randNum;
  }
  double mean = sum / NUM_COUNT;
  double variance = (squaredSum / NUM_COUNT) - (mean * mean);
  double stdDev = sqrt(variance);

  // Read end times
  double endTotalTime, endIdleTime;
  file = fopen(FILE_PATH, "r");
  if (!file) {
    perror("Failed to open /proc/uptime");
    return 1;
  }
  fscanf(file, "%lf %lf", &endTotalTime, &endIdleTime);
  fclose(file);

  // Calculate CPU stats
  double programTotalTime = endTotalTime - startTotalTime;
  double programIdleTime = endIdleTime - startIdleTime;
  double programWorkTime = programTotalTime - programIdleTime;
  double percentage =
      programTotalTime ? (programWorkTime / programTotalTime) * 100 : 0;

  // Display results
  printf("Mean of 100,000 numbers: %.2lf\n", mean);
  printf("Standard Deviation: \t%lf\n", stdDev);
  printf("Start Total Time: \t%lf\n", startTotalTime);
  printf("Start Idle Time: \t%lf\n", startIdleTime);
  printf("End Total Time: \t%lf\n", endTotalTime);
  printf("End Idle Time: \t\t%lf\n", endIdleTime);
  printf("Percentage of time CPU was busy: %.2lf%%\n", percentage);

  return 0;
}
