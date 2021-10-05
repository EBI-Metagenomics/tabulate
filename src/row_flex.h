#ifndef ROW_FLEX_H
#define ROW_FLEX_H

#include "tbl/align.h"
#include "tbl/rc.h"
#include <stdbool.h>

struct tbl_row_flex;

void row_flex_init(struct tbl_row_flex *tbl, char const *header);

bool row_flex_add(struct tbl_row_flex *row, unsigned cell_size,
                  enum tbl_align align, char const *val);

void row_flex_reset(struct tbl_row_flex *tbl);

unsigned row_flex_remain(struct tbl_row_flex const *row, unsigned width);

#endif
