/**************************************************************************\
* > File Name: file_type.c
* > Author   : rack
* > Function :
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2019年04月02日 星期二 15时53分54秒
\**************************************************************************/

/**
    stat
        返回一个与此命名文件有关的信息结构
    fstat
        函数获得已在描述符上打开的文件的有关信息
    lstat
        类似于stat，但是当命名的文件是一个符号链接时，返回该符号链接的有关信息，而不是符号链接引用的文件信息
*/

/**************************************************************************\
* > 头文件
\**************************************************************************/
#include <sys/types.h> /* 文件类型 */
#include <sys/stat.h> /* 文件信息 */
#include "apue.h"
#include "standard_error.h"
int main(int argc, char *argv[])
{
    int         i       ; /* 用于循环打印所有输入的文件 */
    struct stat buf     ; /* 文件信息结构 */
    char        *ptr    ; /* 文件指针 */

    //命令行参数从第二个参数开始
    for(i=1 ; i<argc ; i++)
    {
        //打印从命令行输入的参数（文件名）
        printf("%s:",argv[i]);
        if(lstat(argv[i], &buf) < 0)
        {
            err_ret("lstat error");
            continue ;
        }

        if(S_ISREG(buf.st_mode)) /* 如果是普通文件的文件类型 */
        {
            ptr = "regular" ; /* 指针指向一个常量字符串 */
        }
        else if(S_ISDIR(buf.st_mode)) /* 如果是目录文件 */
        {
            ptr = "directory" ;
        }
        else if(S_ISCHR(buf.st_mode)) /* 如果是字符类型 */
        {
            ptr = "character special" ;
        }
        else if(S_ISLNK(buf.st_mode)) /* 如果是链接 */
        {
            ptr = "block special" ;
        }
        else if(S_ISFIFO(buf.st_mode)) /* 如果是管道 */
        {
            ptr = "fifo" ;
        }
    #ifdef S_ISLNK
        else if(S_ISLNK(buf.st_mode))
        {
            ptr = "symbolic link" ;
        }
    #endif // S_ISLNK

    #ifdef S_ISSOCK
        else if(S_ISSOCK(buf.st_mode))
        {
            ptr = "socket" ;
        }
    #endif // S_ISSOCK
        else
        {
            ptr = "unknown mode" ;
        }

        printf("%s\n",ptr) ;
    }

    exit(0) ;
}

