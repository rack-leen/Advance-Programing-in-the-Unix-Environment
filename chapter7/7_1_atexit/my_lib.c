/*
 * =====================================================================================
 *       Filename:  my_lib.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年05月05日 19时46分59秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Github:  http://github.com/rack-leen
 *           Blog:  http://rack-leen.github.io
 *          Email:  1740234864@qq.com
 *         Author:  rack-leen
 *   Organization:  
 * =====================================================================================
 */

#include "my_lib.h"
#include <stdio.h>

void welcome(void)
{
  printf("Welcome to libmylib\n");
}

void outstring(const char *str)
{
  if(str != NULL)
  {
    printf("%s\n",str);
  }
}
