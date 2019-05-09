/*************************************************************************
* > File Name: myls.c
* > Author   : rack
* > Function : ls , using to display direntories
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2018年05月29日 星期二 23时50分47秒
**************************************************************************/

#include "apue.h"
#include <dirent.h>
#include <sys/types.h>
/*#include "log_error.h"*/
#include "standard_error.h"
int main(int argc, char* argv[])
{
    DIR* dp;             /*代表一个目录流 ， 这是一个不完整的类型 */
    struct dirent* dirp; /* 目录结构体 */

    if (argc != 2) /* 命令行参数数目不对 例子： ls ./  */
    {
        err_quit("Usage: ls direntory_name"); /* 在apue.h中定义，在standard_error.h中实现 */
    }                                         /* opendir()函数返回一个指向DIR结构的指针dp */
    if ((dp = opendir(argv[1])) == NULL)      /* 打开的目录如果为空 */
    {
        err_sys("can't open %s", argv[1]); /* 与err_quit一样 */
    }                                      /* 将指针dp传送给readdir()函数 */
    while ((dirp = readdir(dp)) != NULL)   /* dirp读取的目录不为空 */
    {
        printf("%s\n", dirp->d_name); /* 打印目录名称 */
    }
    closedir(dp); /* 关闭目录 */
    exit(0);      /* 退出程序 ，0表示成功执行；1-255表示出错 */
}
