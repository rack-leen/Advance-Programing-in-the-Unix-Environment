#include "apue.h"
#include "standard_error.h"
#include <sys/fcntl.h>
#include <sys/types.h>

/**
	access函数
	函数原型： int access(const char *pathname , int mode) ;
	pathname: 需要访问的文件名
	mode :访问文件的权限 R_OK(读权限) W_OK（写权限） X_OK（执行权限） F_OK（文件是否存在）
	return : 返回0表示成功，返回-1表示失败
*/

int main(int argc , char **argv)
{
	if(argc != 2)
	{
		err_quit("usage:a.out <pathname>") ;
	}

	if(access(argv[1],R_OK) < 0)
	{
		err_ret("access error for %s",argv[1]) ;
	}
	else
	{
		printf("read OK !") ;
	}

	if(open(argv[1],O_RDONLY) < 0)
	{
		err_ret("open error for %s",argv[1]) ;
	}
	else
	{
		printf("open for reading OK !") ;
	}

    exit(0) ;
}
