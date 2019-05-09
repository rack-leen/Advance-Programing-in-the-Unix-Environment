/*************************************************************************
* > File Name: print_fd.c
* > Author   : rack
* > Function : 程序第一个参数指定文件描述符，并对于该描述符打印其所选择的文
*              件标志说明，例如：read only 、write only
*              fcntl(int fd , int cmd , ...):改变已打开文件属性
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2018年06月03日 星期日 14时00分11秒
**************************************************************************/

/*************************************************************************
* > 头文件
**************************************************************************/

#include "apue.h"
#include "standard_error.h"
#include <fcntl.h>


/* 图3-12函数:对一个文件描述符开启一个或多个文件状态标志 */
void set_fl(int fd , int flags) /* flags are file status flags to turn on */
{
    int     val ;

    /* 返回对应的文件状态标志 */
    if((val = fcntl(fd , F_GETFL , 0)) < 0)
    {
        err_sys("fcntl F_GETFL error");
    }

    /* 打开多个文件标志 */
    val |= flags ; /* turn on flags */
    /* val &= ~flags turn flags off */

    /* 将文件状态标志设置为val */
    if(fcntl(fd , F_SETFL , val) < 0)
    {
        err_sys("fcntl F_SETFL error");
    }
}
int main(int argc , char *argv[])
{
    int         val ;

    if(argc != 2)
    {
        err_quit("usage: print_id <descriptor#>");
    }

    /* 返回对应于fd的文件状态标志 */
    if((val = fcntl(atoi(argv[1]) , F_GETFL , 0)) < 0)/* atoi把字符串转换成整型数 */
    {
        err_sys("fcntl error for fd %d", atoi(argv[1]));
    }

    switch(val & O_ACCMODE) /* O_ACCMODE 作为一个掩码与文件状态标识值做AND运算，产生一个表示文件访问模式的值 */
    {
        case O_RDONLY :
            printf("read only");
            break;
        case O_WRONLY :
            printf("write only");
            break;
        case O_RDWR :
            printf("read write");
            break;
        default:
            err_dump("unknow access mode");
    }

    /* O_APPEND 与文件状态标识值做AND运算，追加写 */
    if(val & O_APPEND)
    {
        printf(", append");
    }

    /* O_NONBLOCK 非阻塞模式 */
    if(val & O_NONBLOCK)
    {
        printf(", nonblocking");
    }

    /* O_SYNC 等待写完成（数据和属性） */
    if(val & O_SYNC)
    {
        printf(", synchronous writes");
    }

    /* _POSIX_C_SOURCE 功能测试宏 O_FSYNC与O_SYNC功能类似但仅freebsd和macos */
#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if(val & O_FSYNC)
    {
        printf(", synchronous writes");
    }
#endif

    putchar('\n');

    exit(0);
}
