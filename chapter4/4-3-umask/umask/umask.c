#include "apue.h"
#include "standard_error.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

/*
	umask函数
	函数原型： mode_t umask(mode_t cmask) ;
	功能：创建屏蔽字，cmask是要禁止的权限状态
	返回  以前的文件方式创建屏蔽字
*/

int main(int argc , char **argv)
{
	umask(0) ;
	/* 为创建的文件赋予这些权限 */
	if(creat("foo" , S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) < 0)
	{
		err_sys("create error for foo") ;
	}

	/* 禁止所有组和其他存取权限 */
	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) ;
	if(creat("bar" , S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) < 0)
	{
		err_sys("create error for bar") ;
	}

	exit(0) ;
}
