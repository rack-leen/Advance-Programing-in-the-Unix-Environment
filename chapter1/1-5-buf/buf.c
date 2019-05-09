/*
 * =====================================================================================
 *
 *       Filename:  buf.c
 *
 *    Description:  standard input copy to standard inout
 *
 *        Version:  1.0
 *        Created:  2018年05月30日 19时40分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include "apue.h"
#include "standard_error.h"
#include <stdio.h>
int main(void)
{
    int c;
    while ((c = getc(stdin)) != EOF) /* 从标准输入得到字符并放到c中，如果不是EOF则循环 */
    {
        if (putc(c, stdout) == EOF) /* 将c放入标准输出，如果标准输出遇到EOF */
        {
            err_sys("output error");
        }
    }

    if (ferror(stdin)) /* 检查和重置输入流状态 */
    {
        err_sys("input error");
    }

    exit(0);
}
