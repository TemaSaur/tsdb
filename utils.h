#pragma once

#include <stdio.h>

int join_path(char* base, char* path, char** full_path);

int ensure_mkdir(char* path);

FILE* base_open(char* path, const char* mode);
