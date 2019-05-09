/*
 * =====================================================================================
 *
 *       Filename:  print-limit.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018年05月31日 22时59分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#ifndef _PRINT_LIMIT_H
#define _PRINT_LIMIT_H

#include "apue.h"
#include "standard_error.h"
#include <errno.h>
#include <limits.h>

/* functions prototypes */
static void pr_sysconf(char*, int); /*自定义打印限制函数 */
static void pr_pathconf(char*, char*, int);

/* functions implementation */
static void pr_sysconf(char* mesg, int name)
{ /* name参数标识系统限制  */
    long val;
    fputs(mesg, stdout); /* 将mesg从标准输出输出 */
    errno = 0;
    if ((val = sysconf(name)) < 0) /* sysconf返回的标识系统限制的值 */
    {                              /* val如果小于0 */
        if (errno != 0)            /* errno如果不等于0 */
        {
            if (errno = EINVAL) /* 无效参数 */
            {
                fputs("(not supported)\n", stdout);
            } else /*如果errno等于其他*/
            {
                err_sys("sysconf error");
            }
        } else /* errno等于0 */
        {
            fputs("(no limit)\n", stdout);
        }
    } else /*如果返回的val值 大于等于0*/
    {
        printf("%ld\n", val);
    }
}

static void pr_pathconf(char* mesg, char* path, int name)
{
    long val;
    fputs(mesg, stdout);
    errno = 0;
    if ((val = pathconf(path, name)) < 0) {
        if (errno != 0) {
            if (errno == EINVAL) {
                fputs("(not supported)\n", stdout);
            } else {
                err_sys("pathconf error , path = %s", path);
            }
        } else {
            fputs("(not limit)\n", stdout);
        }
    } else {
        printf("%ld\n", val);
    }
}

#endif
