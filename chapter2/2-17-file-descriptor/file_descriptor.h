/*************************************************************************
* > File Name: file_descriptor.h
* > Author   : rack
* > Function : 确定文件描述符个数
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2018年06月01日 星期五 16时36分04秒
**************************************************************************/

#ifndef _FILE_DESCRIPTOR_H
#define _FILE_DESCRIPTOR_H

/*************************************************************************
* > 头文件
**************************************************************************/
#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef OPEN_MAX
static long openmax = OPEN_MAX ;
#else
static long openmax = 0 ;
#endif

/*
 * if OPEN_MAX is indeterminate(不确定) , this is might be inadequate(适应).
 */
#define OPEN_MAX_GUESS = 256

long open_max(void)
{
    if(openmax == 0) /* first time through */
    {/* OPEN_MAX 没有定义 */
        errno = 0 ;
        if((openmax = sysconf(_SC_OPEN_MAX)) < 0) /* sysconf返回一个限制值 */
        {/* 如果这个限制值小于0 */
            if(errno == 0) /* SUCCESS */
            {
                openmax = OPEN_MAX_GUESS ; /* 返回一个不确定值 */
            }
            else
            {
                err_sys("openmax error for _SC_OPEN_MAX");
            }
        }
    }

    return(openmax);
}
#endif
