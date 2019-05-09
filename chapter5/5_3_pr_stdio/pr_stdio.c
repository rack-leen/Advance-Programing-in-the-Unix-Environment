/*
 * =====================================================================================
 *       Filename:  pr_stdio.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年05月04日 16时17分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Github:  http://github.com/rack-leen
 *           Blog:  http://rack-leen.github.io
 *          Email:  1740234864@qq.com
 *         Author:  rack-leen
 *   Organization:  
 * =====================================================================================
 */
//#include "../../include/apue.h"
#include "../../include/standard_error.h"
#include <stdio.h>

/***************************************************
  const char * :  流的别名，由使用函数者命名
  FILE *fp     :  使用的流
  function     :  为特定的流命名，并输出流的缓存类型和缓存大小
****************************************************/
void pr_stdio(const char * , FILE *fp);

int main(void)
{
  FILE *fp ;
  /* 将一行字符串输出到标准输出 */
  fputs("enter any character\n" , stdout);
  /* 从标准输入读取字符，如果没有读取到结尾就结束，表示错误 */
  if(getchar() == EOF)
  {
    err_sys("getchar error");
  }
  fputs("one line to standard error\n",stderr);

  pr_stdio("stdin"  , stdin);  /* 由getchar放入标准输入 */
  pr_stdio("stdout" , stdout); /* fputs里的字符输出到标准输出 */
  pr_stdio("stderr" , stderr); /* fputs里的字符输出到标准错误 */

  if((fp = fopen("/etc/motd" , "r")) == NULL)
  {
    err_sys("fopen error");
  }

  /* 从文件流中一个字节一个字节的获取，直到遇上EOF */
  if(getc(fp) == EOF)
  {
    err_sys("getc error");
  }

  pr_stdio("/etc/motd" , fp);

  exit(0);
}

void pr_stdio(const char *name , FILE *fp)
{
  printf("stream = %s, " , name);
  if(fp->_flags & _IONBF)
  {
    printf("无缓存");
  }else if(fp->_flags & _IOLBF)
  {
    printf("行缓存");
  }else
  {
    printf("全缓存");
  }

  printf(", buffer size = %d\n" , fp->_fileno);
}

