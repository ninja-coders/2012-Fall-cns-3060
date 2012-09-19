#include <stdio.h>
#include <string.h>

struct Worker
{
  int id;
  char name[20];
  int bogus;
};

int readFile(const char* filename)
{
  FILE* tmp = fopen(filename, "r");
  if (tmp == NULL) {
    perror("Unable to open file");
    return -1;
  }

  Worker dude;
  long bytesRead;
  do
  {
    bytesRead = fread(&dude, sizeof(char), sizeof(Worker), tmp);
    printf("Worker: %d, %s\n", dude.id, dude.name);
    if (bytesRead != sizeof(Worker)) {
      printf("Only read %d instead of %d", (int)bytesRead, (int)sizeof(Worker));
    }
  } while (bytesRead == sizeof(Worker));

  fclose(tmp);
  return 0;
}

int writeFile(const char* filename, Worker& workerToSave) 
{
  FILE* tmp = fopen(filename, "a");
  if (tmp == NULL) 
  {
    perror("Unable to open file for writing");
    return -1;
  }

  int returnCode = 0;
  if (fwrite(&workerToSave, sizeof(char), sizeof(Worker), tmp) != sizeof(Worker))
  {
    perror("Unable to write the worker to disk");
    returnCode = -1;
  }

  if (fclose(tmp)) 
  {
    perror("Unable to close file, your saves may not be saved ;-)");
    returnCode = -1; 
  }
  return returnCode;
}

int main(int argc, char* argv[], char* env[])
{
  if (argc > 1) {
    readFile("/tmp/testfile");
  }
  else {
    Worker newGuy;
    newGuy.id = 1;
    strcpy(newGuy.name, "New Guy");
    writeFile("/tmp/testfile", newGuy);
  }

  return 0;
}


