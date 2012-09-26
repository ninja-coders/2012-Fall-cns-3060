// 
// CS 3060 - Project 2 (unix cat)
//
// Author: Michael Wright
//
// This code is for educational purposes only, students should only use this as a learning tool but create their own solution.
//
#include <stdio.h>
#include <string.h>

// These are helpful commands for me to be readable 
#define success 0
#define error 1

#define on 1
#define off 0

typedef struct
{
  int displayLines;
} Options;

int isOption(const char* item);
int parseOptions(int argc, char* argv[], Options *options);
int displayFile(FILE* file, Options options, int *lineCount);
int displayFileByName(const char* filename, Options options, int *lineCount);

int main(int argc, char* argv[]) {
  
  Options catOptions;
  memset(&catOptions, 0, sizeof(Options));
  if (parseOptions(argc, argv, &catOptions) != success) {
    perror("Invalid option was specified for command");
    return error;
  }

  int lineCount = 0;
  if (argc == 1 || (argc == 2 && catOptions.displayLines)) {
    displayFile(stdin, catOptions, &lineCount);
  } else {
    int i = 1; 
    while (i < argc) {
      const char* item = argv[i++];
      if (isOption(item)) {
        continue;
      }

      if (!displayFileByName(item, catOptions, &lineCount)) {
        char errorMessage[256];
        snprintf(errorMessage, sizeof(errorMessage), "Failed to display file %s", item);
        perror(errorMessage);
        return error;
      }
    }
  }

  return success;
}

int displayFileByName(const char* filename, Options options, int *lineCount) {
  FILE* currentFile = fopen(filename, "r");
  if (currentFile == NULL) {
    return error;
  }

  int displaySuccess = displayFile(currentFile, options, lineCount);
  if (!fclose(currentFile) || (displaySuccess != success)) {
    return error;
  }

  return success; 
}

int displayFile(FILE* file, Options options, int *lineCount) {
  char nextChar;
  int newLine = on;
  while ((nextChar = fgetc(file)) != EOF) {
    if (options.displayLines && newLine) {
      printf("%6d  ", (*lineCount)++);
      newLine = off;
    }

    fputc(nextChar, stdout);
    if (nextChar == '\n') {
      newLine = on;
    }
  }

  return ferror(file);
}

int isOption(const char* item) {
  return item[0] == '-';
}

int parseOptions(int argc, char* argv[], Options* options) {
  while (argc-- > 0) {
    const char* item = *argv++;

    if (!isOption(item)) {
      continue;
    }

    if (item[1] == 'n') {
      options->displayLines = 1;
    } else {
      return error;
    }
  }

  return success;
}
