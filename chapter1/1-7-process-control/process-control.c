/*
 * =====================================================================================
 *
 *       Filename:  process-control.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  2018年05月30日 22时59分20秒
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
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE]; /* buf是输入的命令 */
    pid_t pid;         /* pid表示进程id */
    int status;        /* 进程所处状态：终止状态等 */

    printf("%% ");                             /* 打印% */
    while (fgets(buf, MAXLINE, stdin) != NULL) /* 当从标准输入得到的输入的字符不为空则继续循环 , 一次读取一行 */
    {                                          /* fgets返回一行都以换行符终结，后随一个NULL字节 */
        if (buf[strlen(buf) - 1] == '\n')      /* 如果输入的最后一个字符串是"\n" */
        {
            buf[strlen(buf) - 1] = 0; /* 将换行符替换为NULL，因为execlp函数返回一个NULL结束而不是换行符 */
        }

        if ((pid = fork()) < 0) /* 如果进程id小于0 */
        {
            err_sys("fork error");
        } else if (pid == 0) /* 子进程 */
        {
            /* 从PATH 环境变量所指的目录中查找符合参数file的文件名, 找到后便执行该文件,
        * 然后将第二个以后的参数当做该文件的argv[0]、argv[1]……, 最后一个参数必须用空指针(NULL)作结束 */
            execlp(buf, buf, (char*)0);
            err_ret("couldn't execute: %s", buf); /* 如果从path中没有找到命令 */
            exit(127);
        }
        /* 父进程 ， 子进程正在执行 ， 父进程需要等待子进程终止*/
        if ((pid = waitpid(pid, &status, 0)) < 0) /* waitpid函数实现父进程等待 ， “0”表示需要等待的子进程id */
        {
            err_sys("waitpid error");
        }
        printf("%%");
    }

    exit(0);
}
