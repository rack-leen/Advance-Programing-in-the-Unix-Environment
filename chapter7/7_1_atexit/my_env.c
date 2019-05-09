/*
 * =====================================================================================
 *       Filename:  my_env.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年05月05日 16时17分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Github:  http://github.com/rack-leen
 *           Blog:  http://rack-leen.github.io
 *          Email:  1740234864@qq.com
 *         Author:  rack-leen
 *   Organization:  
 * =====================================================================================
 */

#include <stdio.h>
extern char **environ ; 
int main(void)
{
  while(*environ)
  {
    printf("%s\n",*environ); /* 打印一行字符串 */
    *environ++ ; /* 一行行的增加 */
  }
  return 0 ;
}
