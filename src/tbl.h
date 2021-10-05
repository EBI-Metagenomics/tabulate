#ifndef TBL_H
#define TBL_H

#define MEMBER_SIZE(type, member) sizeof(((type *)0)->member)

#define MAX(a, b)                                                              \
    ({                                                                         \
        __typeof__(a) _a = (a);                                                \
        __typeof__(b) _b = (b);                                                \
        _a > _b ? _a : _b;                                                     \
    })

#define MIN(a, b)                                                              \
    ({                                                                         \
        __typeof__(a) _a = (a);                                                \
        __typeof__(b) _b = (b);                                                \
        _a <= _b ? _a : _b;                                                    \
    })

#endif
