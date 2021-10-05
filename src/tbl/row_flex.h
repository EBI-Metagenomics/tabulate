#ifndef TBL_ROW_FLEX_H
#define TBL_ROW_FLEX_H

struct tbl_row_flex
{
    char const *header;
    unsigned pos;
    char data[256];
};

#endif
