/*
 * =====================================================================================
 *
 *       Filename:  path_alloc.h
 *
 *    Description:  为路径名动态分配空间
 *
 *        Version:  1.0
 *        Created:  2018年05月31日 23时13分39秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#ifndef _PATH_ALLOC_H
#define _PATH_ALLOC_H

#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef PATH_MAX /* 如果定义了就执行 */
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif

static long posix_version = 0;
static long xsi_version = 0;

/* if PATH_MAX id indeterminate(不确定) , no guarantee(保证) this is adequate(适当) */
#define PATH_MAX_GUESS 1024

char* path_alloc(size_t* sizep) /* alse return allocated(分配) size , if nonnull */
{
    char* ptr;
    size_t size;

    if (posix_version == 0)
    {/* 如果posix版本不知道，则用sysconf返回其版本号 */
        posix_version = sysconf(_SC_VERSION);
    }

    if (xsi_version == 0)
    {/* 如果xsi版本不知道，则用sysconf返回版本号 */
        xsi_version = sysconf(_SC_XOPEN_VERSION);
    }

    if (pathmax == 0)
    {/* 如果PATH_MAX没有定义限制值 */
        errno = 0;
        if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) /* 返回基于工作目录的相对路径名的最大长度 */
        {/* 如果这个值小于0 */
            if (errno == 0) /* SUCESS */
            {
                pathmax = PATH_MAX_GUESS; /* 返回一个不确定值 */
            }
            else
            {
                err_sys("pathconf error for _PC_PATH_MAX"); /* 返回错误信息 */
            }
        }
        else /* 返回的这个值大于0 */
        {
            pathmax++;  /* 得到返回值+1的结果值 */
        }
    }

    if((posix_version < 200112L) && (xsi_version < 4))
    {/*+1是为了兼容先前版本标准，因为考虑路径名末尾有一个null字节 */
        size = pathmax + 1 ;
    }
    else
    {
        size = pathmax ;
    }

    if((ptr = malloc(size)) == NULL)/* 动态分配路径名存储空间 */
    {
        err_sys("malloc error for pathname");
    }

    if(sizep != NULL)
    {
        *sizep = size ;
    }

    return(ptr);
}
#endif
