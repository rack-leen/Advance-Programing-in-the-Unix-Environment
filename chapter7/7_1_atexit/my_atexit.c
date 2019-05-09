/*
 * =====================================================================================
 *       Filename:  my_atexit.c
 *    Description:  
 *        Version:  1.0
 *        Created:  2019年05月05日 15时44分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Github:  http://github.com/rack-leen
 *           Blog:  http://rack-leen.github.io
 *          Email:  1740234864@qq.com
 *         Author:  rack-leen
 *   Organization:  
 * =====================================================================================
 */

#include "../../include/apue.h"
#include "../../include/standard_error.h"

static void my_exit1(void) , my_exit2(void) ;


/***********************************************
  程序首先打印main is done , 之后调用atexit来注册函数，
  并将这些函数压栈，依次从前往后压栈。
  最终，main函数调用exit函数返回值,exit函数依次从栈中
  取出被注册的函数，依次销毁，最终返回状态码

  因此，程序运行为：

    main is done
    can't register my_exit2
    can't register my_exit2
    can't register my_exit1
************************************************/
int main(void)
{
  if(atexit(my_exit1) != 0)
  {
    err_sys("can't register my_exit1");
  }

  if(atexit(my_exit2) != 0)
  {
    err_sys("can't register my_exit2");
  }
  if(atexit(my_exit2) != 0)
  {
    err_sys("can't register my_exit2");
  }

  printf("main is done\n");
  return 0 ;
}

static void my_exit1(void)
{
  printf("first exit handler\n");
}

static void my_exit2(void)
{
  printf("second exit handler\n");
}
