#include <memory>
#include <stdio.h>
#include <iostream>
#include <fstream>

#include <engine/filesystem.hpp>

#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <limits.h>
#include <unistd.h>
#endif

string getexepath()
{
  // Get the absolute path of the executable
  char result[PATH_MAX];

#ifdef _WIN32
  GetModuleFileName(NULL, result, PATH_MAX);
#elif __linux__
  ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
#endif
  string str = string(result);

  // Strip the name of the executable
  size_t positionOfExecutable = str.find("main");
  return str.substr(0, positionOfExecutable);
}

string getPath(string relativePath)
{
  static string projectPath = getexepath();
  string absolutePath = projectPath + relativePath;
  return absolutePath;
}

char *readFile(string filename)
{
  // Open the file
  FILE *fp = fopen(filename.c_str(), "r");

  if (fp == NULL)
  {
    cerr << "Can't open file " << filename << endl;
    return NULL;
  }

  // Move the file pointer to the end of the file and determing the length
  fseek(fp, 0, SEEK_END);
  long file_length = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *contents = new char[file_length + 1];

  // Here's the actual read
  fread(contents, 1, file_length, fp);

  // This is how you denote the end of a string in C
  contents[file_length] = '\0';
  fclose(fp);

  return contents;
}