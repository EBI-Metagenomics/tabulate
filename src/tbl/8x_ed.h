#ifndef TBL_8X_ED_H
#define TBL_8X_ED_H

#include "tbl/align.h"
#include "tbl/export.h"
#include "tbl/row_flex.h"
#include <stdbool.h>
#include <stdio.h>

struct tbl_8x_ed
{
    FILE *fd;
    unsigned width;
    unsigned cell_size;
    unsigned header_size;
    enum tbl_align header_align;
    unsigned nrows;
    struct tbl_row_flex rows[8];
};

TBL_API bool tbl_8x_ed_setup(struct tbl_8x_ed *tbl, FILE *fd, unsigned width,
                             unsigned cell_size, unsigned max_header_size,
                             enum tbl_align align, unsigned nrows,
                             char const *headers[nrows]);

TBL_API bool tbl_8x_ed_add_col(struct tbl_8x_ed *tbl, enum tbl_align align,
                               char const *rows[]);

TBL_API bool tbl_8x_ed_flush(struct tbl_8x_ed *tbl);

#endif
