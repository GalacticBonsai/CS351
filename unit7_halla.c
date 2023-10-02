/*
 * Unit7_halla.c
 *
 * Author: Joseph Halla
 * Date: 2023-10-01
 * Assignment: CS351 Computer Operating Systems, Unit 7 Assignment
 * Description: A program to display specific system information fetched from
 * various /proc files.
 * run with gcc Unit7_YourLastName.c -o myProgram -std=c11
 * ./myProgram
 */

#include <stdio.h>
#include <string.h>

int main() {
  FILE *file;
  char hostname[256];
  char dateTimeLine[256];
  char version[256];
  char totalMemLine[256], freeMemLine[256];
  double uptime, idletime;

  // For extracting machine name
  file = fopen("/proc/sys/kernel/hostname", "r");
  fscanf(file, "%s", hostname);
  fclose(file);

  // Parsing dateTimeLine to extract time and date
  char time[50], date[50];
  file = fopen("/proc/driver/rtc", "r"); // reopening file to get date

  fgets(dateTimeLine, sizeof(dateTimeLine), file);
  sscanf(dateTimeLine, "rtc_time\t: %s", time);
  fgets(dateTimeLine, sizeof(dateTimeLine), file);
  sscanf(dateTimeLine, "rtc_date\t: %s", date);

  fclose(file);

  // For extracting kernel version
  file = fopen("/proc/version", "r");
  fgets(version, sizeof(version), file);
  fclose(file);

  // For extracting memory information
  file = fopen("/proc/meminfo", "r");
  fgets(totalMemLine, sizeof(totalMemLine), file);
  fgets(freeMemLine, sizeof(freeMemLine), file);
  fclose(file);

  // Extracting values from strings
  int totalMem, freeMem;
  sscanf(totalMemLine, "MemTotal: %d kB", &totalMem);
  sscanf(freeMemLine, "MemFree: %d kB", &freeMem);

  // For extracting uptime information
  file = fopen("/proc/uptime", "r");
  fscanf(file, "%lf %lf", &uptime, &idletime);
  fclose(file);

  // Calculations
  double memUtilizedPercentage =
      (double)(totalMem - freeMem) / totalMem * 100.0;
  double busyTimePercentage = (uptime - idletime) / uptime * 100.0;

  // Displaying the information
  printf("Machine name: %s\n", hostname);
  printf("System time and date: %s %s\n", time, date);
  printf("%s", version);

  printf("Memory usage:\n");
  printf("    total: %d Kb\n", totalMem);
  printf("    free: %d Kb\n", freeMem);
  printf("    %%_used: %.2lf%%\n", memUtilizedPercentage);

  printf("System usage (time):\n");
  printf("    Total up time: %.2lf seconds\n", uptime);
  printf("    Total idle time: %.2lf seconds\n", idletime);
  printf("    %%_busy: %.2lf%%\n", busyTimePercentage);

  return 0;
}
