#include "../include/const.h"
#include "../include/types.h"

#include <math.h>
#include <stdio.h>

Metadata get_metadata() {
	// the page size is always a power of 2
	Metadata metadata = {(unsigned char)log2(PAGE_SIZE)};
	return metadata;
}

unsigned long write_metadata(Metadata metadata, FILE* file) {
	return fwrite(&metadata, sizeof(metadata), 1, file);
}
