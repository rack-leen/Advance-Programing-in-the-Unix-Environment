/*
 * =====================================================================================
 *
 *       Filename:  print-limit.c
 *
 *    Description:  打印所有可能的sysconf和pathconf值
 *
 *        Version:  1.0
 *        Created:  2018年05月31日 21时15分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include "print_limit.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        err_quit("usage: print_limit <dirname>");
    }

#ifdef ARG_MAX /* 限制名 ， exec函数的参数最大长度 */
    printf("ARG_MAX defined to be %ld\n", (long)ARG_MAX + 0);
#else
    printf("no symbol for ARG_MAX\n");
#endif

#ifdef _SC_ARG_MAX /* sysconf pathsysconf 的name参数 */
    pr_sysconf("ARG_MAX = ", _SC_ARG_MAX);
#else
    printf("no symbol for _SC_ARG_MAX\n");
#endif

/* similar processing for all the rest of the sysconf symbols... */
#ifdef MAX_CANON /* 终端规范输入队列的最大字节数 */
    printf("MAX_CANON defined to be %ld\n", (long)MAX_CANON + 0);
#else
    printf("no symbol for MAX_CANON\n");
#endif

#ifdef _PC_MAX_CANON /* name参数，同上 */
    pr_pathconf("MAX_CANON = ", argv[1], _PC_MAX_CANON);
#else
    printf("no symbol for _PC_MAX_CANON\n");
#endif

    /* similar processing for all the rest of the pathconf symbols... */

    exit(0);
}
