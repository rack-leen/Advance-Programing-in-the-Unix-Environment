/*
 * =====================================================================================
 *       Filename:  tempNam.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年05月04日 19时05分22秒
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

int main(int argc , char *argv[])
{
  /* 第一个argc是命令,第一个参数是目录,第二个参数是前缀 */
  if(argc != 3)
  {
    err_quit("usage:a.out<directory><prefix>");
  }

  /*
      argv[1][0] != '' ? argv[1]:NULL  : 如果第一个参数不是空字符串则正常输出，如果是则输出为NULL
      argv[2][0] != ' '? argv[2]:NULL  : 如果第二个参数不是空字符串则正常输出，如果是则输出为NULL
   */
  printf("%s\n",tempnam(argv[1][0] != ' ' ? argv[1]:NULL , argv[2][0] != ' '?argv[2]:NULL));
  exit(0) ;
}
