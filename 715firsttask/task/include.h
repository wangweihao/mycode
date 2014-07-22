#ifndef INCLUDE_H
#define INCLUDE_h


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<dirent.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#define N 100


void my_error(char const *string, int line);
int my_readir(const char *path, char (*filename)[100]);
int my_readirt(const char *path, char (*filename)[100]);
void display_attribute(char *filename); 
void sort(char (*filename)[100]);

#endif //INCLUDE_h
