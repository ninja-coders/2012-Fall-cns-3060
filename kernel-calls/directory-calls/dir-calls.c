#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SUCCESS 0
#define FAILURE 1

#define CURRENT_DIRECTORY "."

int printDirectory(const char* directory);

int main(int argc, char* argv[]) {

  const char* directory = argc > 1 ? argv[1] : CURRENT_DIRECTORY;

  DIR* directoryPointer = opendir(directory);
  if (directoryPointer == NULL) {
    perror("Can't open directory");
    return FAILURE;
  }

  struct dirent* currentEntry;
  while ((currentEntry = readdir(directoryPointer)) != NULL)
  {
    printf("Directory: '%-15s' Entry: '%15s'", directory, currentEntry->d_name);

    struct stat entryStats;
    if (stat(currentEntry->d_name, &entryStats) != SUCCESS) {
      perror("Failed to get file stats");
      continue;
    }

    printf(" Size: %lld b\n", (long long)entryStats.st_size);
  }

  if (closedir(directoryPointer) != SUCCESS) {
    perror("Failed to close the directory");
    return FAILURE;
  }

  return SUCCESS;
}

