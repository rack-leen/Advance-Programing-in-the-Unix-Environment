/*
 * =====================================================================================
 *       Filename:  createTmp.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年05月04日 18时33分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Github:  http://github.com/rack-leen
 *           Blog:  http://rack-leen.github.io
 *          Email:  1740234864@qq.com
 *         Author:  rack-leen
 *   Organization:  
 * =====================================================================================
 */

#include "../../include/standard_error.h"
#include <stdio.h>

int main(void)
{
  char name[L_tmpnam] , line[MAXLINE] ;
  FILE *fp ;

  /* 使用tmpnam创建一个有效的路径名字符串，放入静态区中，指向该静态区的指针作为函数返回值 */
  printf("tmp1:%s\n",tmpnam(NULL));

  /* 将产生的有效路径名字符串放入name数组中，并将name返回 */
  tmpnam(name);
  printf("tmp2:%s\n",name);

  /* 创建一个临时二进制文件,返回临时文件对象，关闭程序时将自动删除 */
  if((fp = tmpfile()) == NULL)
  {
    err_sys("tmpfile error");
  }
  /* 将字符串写入文件对象中 */
  fputs("one line of output\n",fp);
  /* 将指针复位到起始地址，从起始地址开始读取 */
  rewind(fp);
  /* 从文件对象中一行一行的获取数据，并放到line数组中 */
  if(fgets(line , sizeof(line) , fp) == NULL)
  {
    err_sys("fgets error");
  }
  /* 从line数组中去除数据放入标准输出中 */
  fputs(line , stdout);
  exit(0);
}

