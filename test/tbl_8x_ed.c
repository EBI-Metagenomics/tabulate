#include "hope/hope.h"
#include "tbl/tbl.h"
#include <limits.h>

void test_example1(void);
void test_example2(void);
void test_example3(void);
void test_example4(void);
void test_example5(void);
void test_example6(void);
void test_example7(void);
void test_break1(void);

int main(void)
{
    test_example1();
    test_example2();
    test_example3();
    test_example4();
    test_example5();
    test_example6();
    test_example7();
    test_break1();
    return hope_status();
}

void test_example1(void)
{
    struct tbl_8x_ed tbl = {0};

    char const *headers[3] = {"Homoserine_dh", "pcodon", "state"};
    tbl_8x_ed_setup(&tbl, stdout, 88, 6, 32, TBL_RIGHT, 3, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_8x_ed_flush(&tbl);
}

void test_example2(void)
{
    struct tbl_8x_ed tbl = {0};

    char const *headers[3] = {"Homoserine_dh", "pcodon", "state"};
    tbl_8x_ed_setup(&tbl, stdout, 88, 6, 32, TBL_RIGHT, 3, headers);

    for (unsigned i = 0; i < 15; ++i)
    {
        char const *rows0[3] = {"P", "CT", "CCT"};
        tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows0);

        char const *rows1[3] = {"i", "ATC", "ATC"};
        tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows1);

        char const *rows2[3] = {"C", "A", "ATCGC"};
        tbl_8x_ed_add_col(&tbl, TBL_RIGHT, rows2);

        char const *rows3[3] = {"C", "A", "ATCGC"};
        tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows3);
    }

    tbl_8x_ed_flush(&tbl);
}

void test_example3(void)
{
    struct tbl_8x_ed tbl = {0};

    char const *headers[3] = {"Homoserine_dh very very very very long name",
                              "pcodon", "state"};
    tbl_8x_ed_setup(&tbl, stdout, 88, 6, 32, TBL_RIGHT, 3, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_8x_ed_flush(&tbl);
}

void test_example4(void)
{
    struct tbl_8x_ed tbl = {0};

    char const *headers[3] = {"Homoserine_dh", "pcodon", "state"};
    tbl_8x_ed_setup(&tbl, stdout, 88, 2, 32, TBL_RIGHT, 3, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_8x_ed_flush(&tbl);
}

void test_example5(void)
{
    struct tbl_8x_ed tbl = {0};

    char const *headers[3] = {"", "pcodon", "state"};
    tbl_8x_ed_setup(&tbl, stdout, 88, 6, 32, TBL_RIGHT, 3, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_8x_ed_flush(&tbl);
}

void test_example6(void)
{
    struct tbl_8x_ed tbl = {0};

    char const *headers[3] = {"", "", ""};
    tbl_8x_ed_setup(&tbl, stdout, 88, 6, 32, TBL_RIGHT, 3, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_8x_ed_flush(&tbl);
}

void test_example7(void)
{
    struct tbl_8x_ed tbl = {0};

    char const *headers[4] = {"", "", "", ""};
    tbl_8x_ed_setup(&tbl, stdout, 88, 6, 32, TBL_RIGHT, 4, headers);

    char const *rows0[4] = {"P", "CT", "CCT", "CT"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[4] = {"i", "ATC", "ATC", "ATC"};
    tbl_8x_ed_add_col(&tbl, TBL_LEFT, rows1);

    tbl_8x_ed_flush(&tbl);
}

void test_break1(void)
{
    struct tbl_8x_ed tbl = {0};
    char const *hdrs[3] = {"", "", ""};
    COND(!tbl_8x_ed_setup(&tbl, stdout, UINT_MAX, 6, 32, TBL_RIGHT, 3, hdrs));
    COND(!tbl_8x_ed_setup(&tbl, stdout, 88, UINT_MAX, 32, TBL_RIGHT, 3, hdrs));
    COND(!tbl_8x_ed_setup(&tbl, stdout, 88, 6, UINT_MAX, TBL_RIGHT, 3, hdrs));
}
