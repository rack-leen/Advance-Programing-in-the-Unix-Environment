/*
 * =====================================================================================
 *
 *       Filename:  copyfile.c
 *
 *    Description:  read file from stdin and write file to stdout
 *
 *        Version:  1.0
 *        Created:  2018年05月30日 14时56分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  rack
 *   Organization:
 *
 * =====================================================================================
 */
#include "apue.h"
#include "standard_error.h"
#define BUFFSIZE 4096

/*不带缓冲，只能输出一个字符*/
int main(void)
{
    int n;
    char buf[BUFFSIZE]; /* 标准输入缓冲区 */

    while (n = read(STDIN_FILENO, buf, BUFFSIZE) > 0) /* 从标准输入读取字符，大于0表示字符不为空 */
    {
        if (write(STDOUT_FILENO, buf, n) != n) /* 如果写到标准输出的字符不等于从标准输入读取的字符 */
        {
            err_sys("write error!");
        }
    }

    if (n < 0) /* 如果标准输入的字符小于0，表示读取错误 */
    {
        err_sys("read error");
    }

    exit(0);
}
