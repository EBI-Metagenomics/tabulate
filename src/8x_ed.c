#include "tbl/8x_ed.h"
#include "row_flex.h"
#include "tbl.h"
#include <assert.h>
#include <string.h>

static void header_setup(struct tbl_8x_ed *tbl, unsigned max_header_size,
                         enum tbl_align align, char const *headers[]);
static bool flush_header(struct tbl_8x_ed *tbl, struct tbl_row_flex const *row);

bool tbl_8x_ed_setup(struct tbl_8x_ed *tbl, FILE *fd, unsigned width,
                     unsigned cell_size, unsigned max_header_size,
                     enum tbl_align align, unsigned nrows,
                     char const *headers[nrows])
{
    if (width < cell_size) return false;

    unsigned const data_size = MEMBER_SIZE(typeof(tbl->rows[0]), data);
    if (width > data_size) return false;
    if (max_header_size > data_size) return false;
    if (max_header_size + cell_size > data_size) return false;

    tbl->fd = fd;
    tbl->width = width;
    tbl->cell_size = cell_size;
    tbl->nrows = nrows;

    header_setup(tbl, max_header_size, align, headers);

    for (unsigned i = 0; i < tbl->nrows; ++i)
        row_flex_init(tbl->rows + i, headers[i]);
    return true;
}

bool tbl_8x_ed_add_col(struct tbl_8x_ed *tbl, enum tbl_align align,
                       char const *rows[])
{
    if (tbl->cell_size > row_flex_remain(tbl->rows + 0, tbl->width))
        tbl_8x_ed_flush(tbl);

    for (unsigned i = 0; i < tbl->nrows; ++i)
    {
        if (!row_flex_add(tbl->rows + i, tbl->cell_size, align, rows[i]))
            return false;
    }
    return true;
}

bool tbl_8x_ed_flush(struct tbl_8x_ed *tbl)
{
    for (unsigned i = 0; i < tbl->nrows; ++i)
    {
        if (!flush_header(tbl, tbl->rows + i)) return false;
        if (EOF == fputs(tbl->rows[i].data, tbl->fd)) return false;
        if (EOF == fputc('\n', tbl->fd)) return false;
        row_flex_reset(tbl->rows + i);
    }
    if (EOF == fputc('\n', tbl->fd)) return false;
    return true;
}

static void header_setup(struct tbl_8x_ed *tbl, unsigned max_header_size,
                         enum tbl_align align, char const *headers[])
{
    tbl->header_size = 0;
    for (unsigned i = 0; i < tbl->nrows; ++i)
        tbl->header_size = MAX(tbl->header_size, (unsigned)strlen(headers[i]));
    tbl->header_size = MIN(tbl->header_size, max_header_size);
    tbl->header_align = align;
}

static bool flush_header(struct tbl_8x_ed *tbl, struct tbl_row_flex const *row)
{
    if (tbl->header_size == 0) return true;
    int sz = (int)(tbl->header_size);
    int n = 0;
    if (tbl->header_align == TBL_LEFT)
        n = fprintf(tbl->fd, "%*.*s ", -sz, -sz, row->header);
    else
        n = fprintf(tbl->fd, "%*.*s ", +sz, +sz, row->header);
    if (n < 0) return false;
    return true;
}
