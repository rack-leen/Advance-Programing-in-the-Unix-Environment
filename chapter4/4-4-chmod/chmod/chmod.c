#include "apue.h"
#include "standard_error.h"
#include <sys/types.h>
#include <sys/stat.h>

/*
	fchmod : int fchmod(int files , mode_t mode) ;
	chmod : int chmod(const char pathname , mode_t mode) ;

	fchmod函数和chmod函数让我们能够更改文件的存取权限
	fchmod 是BSD的扩充部分 对已打开的文件进行操作
	chmod 在指定的文件上进行操作
*/
int main(int argc , char **argv)
{
    struct stat statbuf ;
    if(stat("foo" , &statbuf) < 0)
	{
		err_sys("stat error for foo") ;
	}

	/* 通过statbuf取得文件的权限信息，与取反后的执行权限，使得取消组执行权限，之后再加上组id位 */
	if(chmod("foo" , (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
	{
		err_sys("chmod error for foo") ;
	}

	if(chmod("bar" , S_IRUSR | S_IRGRP | S_IROTH) < 0)
	{
		err_sys("chmod error for bar") ;
	}
    exit(0) ;
}
