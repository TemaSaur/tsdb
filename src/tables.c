#include "../include/file_utils.h"
#include "../include/types.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_table(Tabledata data) {
	FILE* tables_file = base_open("data/tables.data", "wb");

	if (tables_file == NULL) {
		printf("Failed to open tables.data");
		exit(1);
	}

	if (get_file_size(tables_file) == 0) {
		fwrite(data.title, sizeof(char), strlen(data.title), tables_file);
	} else {
		// todo: check if table exists
	}

	fclose(tables_file);
}
