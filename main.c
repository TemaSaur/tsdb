#include "const.h"
#include "meta.h"
#include "types.h"
#include "utils.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h> // for strerror()
#include <sys/stat.h>

int get_file_size(FILE* file) {
	fseek(file, 0, SEEK_END);
	int size = ftell(file);
	fseek(file, 0, SEEK_SET);
	return size;
}

void write_string(char* string, FILE* file) {
	unsigned char len = (unsigned char)strlen(string);

	fwrite(&len, sizeof(unsigned char), 1, file);
	fwrite(string, sizeof(char), len, file);
}

void create_table(Tabledata data) {
	FILE* tables_file = base_open("data/tables.data", "wb");

	if (tables_file == NULL) {
		printf("oh no");
		exit(1);
	}

	if (get_file_size(tables_file) == 0) {
		fwrite(data.title, sizeof(char), strlen(data.title), tables_file);
	} else {
	}

	fclose(tables_file);
}

int init() {
	mkdir(BASE_DIR, 0700);
	ensure_mkdir("data");
	// mkdir("data/data", 0700);

	FILE* metafile = base_open("meta.data", "wb");

	Metadata metadata = get_metadata();
	write_metadata(metadata, metafile);

	Tabledata tables_table = {"meta_tables"};
	create_table(tables_table);

	return 0;
}

int main() {
	init();
}
