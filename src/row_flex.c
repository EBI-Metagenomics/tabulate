#include "row_flex.h"
#include "tbl.h"
#include "tbl/align.h"
#include "tbl/row_flex.h"
#include <assert.h>
#include <stdio.h>

void row_flex_init(struct tbl_row_flex *row, char const *header)
{
    row->header = header;
    row->pos = 0;
    row->data[0] = '\0';
}

bool row_flex_add(struct tbl_row_flex *row, unsigned cell_size,
                  enum tbl_align align, char const *val)
{
    assert(cell_size > 0);
    unsigned r = (unsigned)(MEMBER_SIZE(struct tbl_row_flex, data) - row->pos);
    if (r < cell_size) return false;

    char *buf = row->data + row->pos;
    int sz = (int)(cell_size - 1);
    int n = 0;
    if (align == TBL_LEFT)
        n = sprintf(buf, "%*.*s ", -sz, -sz, val);
    else
        n = sprintf(buf, "%*.*s ", +sz, +sz, val);
    if (n < 0) return false;
    buf[cell_size] = '\0';

    row->pos += (unsigned)n;
    return true;
}

void row_flex_reset(struct tbl_row_flex *row)
{
    row->pos = 0;
    row->data[0] = '\0';
}

unsigned row_flex_remain(struct tbl_row_flex const *row, unsigned width)
{
    if (width > row->pos) return (unsigned)(width - row->pos);
    return 0;
}
