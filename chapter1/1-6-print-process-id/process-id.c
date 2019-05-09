/*
 * =====================================================================================
 *
 *       Filename:  process-id.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018年05月30日 20时58分56秒
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
    printf("hello world from process ID %ld\n", (long)getpid());

    exit(0);
}
