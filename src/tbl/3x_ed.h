#ifndef TBL_3X_ED_H
#define TBL_3X_ED_H

#include "tbl/align.h"
#include "tbl/export.h"
#include "tbl/row_flex.h"
#include <stdbool.h>
#include <stdio.h>

struct tbl_3x_ed
{
    FILE *fd;
    unsigned width;
    unsigned cell_size;
    unsigned header_size;
    enum tbl_align header_align;
    struct tbl_row_flex rows[3];
};

TBL_API bool tbl_3x_ed_setup(struct tbl_3x_ed *tbl, unsigned width,
                             unsigned cell_size, unsigned max_header_size,
                             enum tbl_align align, char const *headers[3]);

TBL_API bool tbl_3x_ed_add_col(struct tbl_3x_ed *tbl, enum tbl_align align,
                               char const *rows[3]);

TBL_API bool tbl_3x_ed_flush(struct tbl_3x_ed *tbl);

#endif
