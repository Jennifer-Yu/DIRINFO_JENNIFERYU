/**

You will write a program that will gather various information about a directory, specifically:
list all the files in the directory
specify which files are directories (if any)
show the total size of all the regular files the directory
note that you do not have to recursively go through any subdirectories to find their size for this part (unless you want to, but that is not a simple task)
Have the program scan the current directory
Possible enhancements:
Recursively list the files in any subdirectories, update the total to include the total size of subdirectories
Print out the size in a more readable format (like using KB, MB, GB for -byte prefixes)

**/

//Jennifer Yu
//11-02-16

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

/**
int is_file(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

int is_dir(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}
**/

int isdir(struct dirent *file) {
  return (file->d_type == DT_DIR);
}

int isreg(struct dirent *file) {
  return (file->d_type == DT_REG);
}

int dsize(char *path) {

  int size = 0;
  DIR *temp = opendir(".");
  struct dirent *entry = readdir(temp);

  while (entry) {
    if (isreg(entry)) {
      struct stat buf;
      size += buf.st_size;
    }
    entry = readdir(temp);
  }

  return size;
}


int main() {

    //struct stat *buf;
    //stat("testdir",&buf);

    DIR *dummy = opendir(".");
    struct dirent *temp = readdir(dummy);
    printf("DIRSIZE: %d\n", dsize(temp));

    while (temp) {
        printf("%s: ", temp->d_name);
        printf("%d\n", temp->d_ino);
        if (isdir(temp)) {
            printf("%s\n", "THIS IS A DIRECTORY DUNDUNDUNNNN");
        }
        if (isreg(temp)) {
            printf("%s\n", "THIS IS A REGFILE");
        }
        //printf("File Size : %ld bytes\n", buf->st_size);
        temp = readdir(dummy);
    }

    return 0;
}