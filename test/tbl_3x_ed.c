#include "hope/hope.h"
#include "tbl/tbl.h"
#include <limits.h>

void test_example1(void);
void test_example2(void);
void test_example3(void);
void test_example4(void);
void test_example5(void);
void test_example6(void);
void test_break1(void);

int main(void)
{
    test_example1();
    test_example2();
    test_example3();
    test_example4();
    test_example5();
    test_example6();
    test_break1();
    return hope_status();
}

void test_example1(void)
{
    struct tbl_3x_ed tbl = {.fd = stdout};

    char const *headers[3] = {"Homoserine_dh", "pcodon", "state"};
    tbl_3x_ed_setup(&tbl, 88, 6, 32, TBL_RIGHT, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_3x_ed_flush(&tbl);
}

void test_example2(void)
{
    struct tbl_3x_ed tbl = {.fd = stdout};

    char const *headers[3] = {"Homoserine_dh", "pcodon", "state"};
    tbl_3x_ed_setup(&tbl, 88, 6, 32, TBL_RIGHT, headers);

    for (unsigned i = 0; i < 15; ++i)
    {
        char const *rows0[3] = {"P", "CT", "CCT"};
        tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows0);

        char const *rows1[3] = {"i", "ATC", "ATC"};
        tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows1);

        char const *rows2[3] = {"C", "A", "ATCGC"};
        tbl_3x_ed_add_col(&tbl, TBL_RIGHT, rows2);

        char const *rows3[3] = {"C", "A", "ATCGC"};
        tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows3);
    }

    tbl_3x_ed_flush(&tbl);
}

void test_example3(void)
{
    struct tbl_3x_ed tbl = {.fd = stdout};

    char const *headers[3] = {"Homoserine_dh very very very very long name",
                              "pcodon", "state"};
    tbl_3x_ed_setup(&tbl, 88, 6, 32, TBL_RIGHT, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_3x_ed_flush(&tbl);
}

void test_example4(void)
{
    struct tbl_3x_ed tbl = {.fd = stdout};

    char const *headers[3] = {"Homoserine_dh", "pcodon", "state"};
    tbl_3x_ed_setup(&tbl, 88, 2, 32, TBL_RIGHT, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_3x_ed_flush(&tbl);
}

void test_example5(void)
{
    struct tbl_3x_ed tbl = {.fd = stdout};

    char const *headers[3] = {"", "pcodon", "state"};
    tbl_3x_ed_setup(&tbl, 88, 6, 32, TBL_RIGHT, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_3x_ed_flush(&tbl);
}

void test_example6(void)
{
    struct tbl_3x_ed tbl = {.fd = stdout};

    char const *headers[3] = {"", "", ""};
    tbl_3x_ed_setup(&tbl, 88, 6, 32, TBL_RIGHT, headers);

    char const *rows0[3] = {"P", "CT", "CCT"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows0);

    char const *rows1[3] = {"i", "ATC", "ATC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows1);

    char const *rows2[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_RIGHT, rows2);

    char const *rows3[3] = {"C", "A", "ATCGC"};
    tbl_3x_ed_add_col(&tbl, TBL_LEFT, rows3);

    tbl_3x_ed_flush(&tbl);
}

void test_break1(void)
{
    struct tbl_3x_ed tbl = {.fd = stdout};

    char const *headers[3] = {"", "", ""};
    COND(!tbl_3x_ed_setup(&tbl, UINT_MAX, 6, 32, TBL_RIGHT, headers));
    COND(!tbl_3x_ed_setup(&tbl, 88, UINT_MAX, 32, TBL_RIGHT, headers));
    COND(!tbl_3x_ed_setup(&tbl, 88, 6, UINT_MAX, TBL_RIGHT, headers));
}
