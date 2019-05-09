/*
 * =====================================================================================
 *
 *       Filename:  process-error.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018年05月30日 23时51分35秒
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
#include <errno.h> /* 提供出错处理函数 */

int main(int argc, char* argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES)); /* 打印出错处理消息，stderr是标准错误 ， stderror返回一个出错消息字符串 */
    errno = ENOENT;

    perror(argv[0]); /* 基于errno当前值，在标准错误产生一个出错信息 */
    exit(0);
}
