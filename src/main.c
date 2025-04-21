#include "../include/const.h"
#include "../include/file_utils.h"
#include "../include/meta.h"
#include "../include/tables.h"
#include "../include/types.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int init() {
	mkdir(BASE_DIR, 0700);
	ensure_mkdir("data");

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
