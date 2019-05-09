/*
 * =====================================================================================
 *
 *       Filename:  print-id.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018年05月31日 12时56分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include "apue.h"

int main(void)
{
    /* getuid()函数得到用户id , getgid()函数得到组id */
    printf("uid = %d,gid = %d\n", getuid(), getgid());
    exit(0);
}
