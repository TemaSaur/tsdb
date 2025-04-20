#pragma once

#include "types.h"
#include <stdio.h>

Metadata get_metadata();

unsigned long write_metadata(Metadata metadata, FILE* file);
