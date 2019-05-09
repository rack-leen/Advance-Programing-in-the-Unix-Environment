/*************************************************************************
* > File Name: create_hole.c
* > Author   : rack
* > Function : 创建具有文件洞的文件; 文件洞就是普通字符中包含空字符的那部分
*              在磁盘上并不会使用任何数据块保存这部分数据
*              lseek(int fd , off_t offset , int whence)
*              SEEK_SET(绝对偏移量) SEEK_CUR（当前偏移量）
*              SEEK_END（相对于当前位置的偏移量）
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2018年06月02日 星期六 17时39分03秒
**************************************************************************/

/*************************************************************************
* > 头文件
**************************************************************************/
#include "apue.h"
#include "standard_error.h"
#include <fcntl.h> /* 包含文件控制选项 */


/* 两个缓存变量 */
char        buf1[] = "abcdefghij" ;  /* 10个字符 */
char        buf2[] = "ABCDEFGHIJ" ;

int main(void)
{
    int     fd ;  /* file descriptor 文件描述符 */

    /* 创建一个file.hole文件，并返回一个文件描述符 */
    if((fd = creat("file.hole" , FILE_MODE)) < 0 )
    {/* 如果文件描述符是负数 */
        err_sys("creat error");
    }

    /* 从buf1数组中写入是个字符到fd文件描述符指向的文件 */
    if(write(fd , buf1 , 10) != 10)
    {/* 如果写入的不是10字符 */
        err_sys("buf1 write error"); /* offset now = 10 */
    }

    /* SEEK_SET 文件偏移量设置为据文件开始处offset字节
     * 绝对偏移量,总偏移量为16384
     */
    if(lseek(fd , 16384 , SEEK_SET) == -1) /* offset now = 16384 */
    {
        err_sys("lseek error");
    }

    /* 同上 */
    if(write(fd , buf2 , 10) != 10) /* offset now = 16394 */
    {
        err_sys("buf2 write error");
    }

    exit(0);
}

