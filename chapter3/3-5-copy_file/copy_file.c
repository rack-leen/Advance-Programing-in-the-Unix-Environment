/*************************************************************************
* > File Name: copy_file.c
* > Author   : rack
* > Function : write(int fd , const void *buf , size_t mbytes)
*              read(int fd , void *buf , size_t mbytes)
*              将标准输入复制到标准输出
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2018年06月03日 星期日 12时26分58秒
**************************************************************************/

/*************************************************************************
* > 头文件
**************************************************************************/
#include "apue.h"
#include "standard_error.h"


#define BUFSIZE 4096   /* 4096是Linux下磁盘块长度 */

int main(void)
{
    int     n;
    char    buf[BUFSIZE];

    /* 从标准输入缓存区中读取字符，返回到n */
    while((n = read(STDIN_FILENO , buf , BUFSIZE)) > 0 ) /* 如果n>0 */
    {/* 如果从标准输出缓存读取的字符数不等于标准输入n */
        if(write(STDOUT_FILENO , buf , n) != n)
        {
            err_sys("buf write error");
        }
    }

    if(n < 0)
    {/* 如果标准输入字符小于0 */
        err_sys("read error");
    }

    exit(0);
}
