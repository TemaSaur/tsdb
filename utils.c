#include "const.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int join_path(char* base, char* path, char** full_path) {
	if (!base || !path || !full_path) {
		return 1;
	}
	size_t base_len = strlen(base);
	size_t path_len = strlen(path);
	size_t sep_len = 1;
	size_t terminator_len = 1;

	*full_path = malloc(base_len + path_len + sep_len + terminator_len);
	if (*full_path == NULL) {
		return 1; // todo: redo errors
	}

	if (base[base_len - 1] == SEP) {
		snprintf(
			*full_path, base_len + path_len + terminator_len, "%s%s", base, path
		);
		return 0;
	}

	snprintf(
		*full_path, base_len + path_len + sep_len + terminator_len, "%s%c%s",
		base, SEP, path
	);
	return 0;
}

int ensure_mkdir(char* path) {
	char* full_path;

	if (join_path(BASE_DIR, path, &full_path) != 0) {
		return 1;
	}

	int result = mkdir(full_path, 0700);

	free(full_path);
	return result;
}

FILE* base_open(char* path, const char* mode) {
	char* full_path;

	if (join_path(BASE_DIR, path, &full_path) != 0) {
		fprintf(stderr, "oh no open");
		exit(1);
	}

	FILE* file = fopen(full_path, mode);

	free(full_path);
	return file;
}
