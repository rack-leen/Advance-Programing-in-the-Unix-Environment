/*************************************************************************
* > File Name: log_error.c
* > Author   : rack
* > Function :
* > Type     :
* > Github   : https://github.com/rack-leen
* > Date     : 2018年05月30日 星期三 11时27分46秒
**************************************************************************/

#include "apue.h"
#include <errno.h>
#include <stdarg.h>
#include <syslog.h>

static void log_doit(int, int, int, const char*, va_list ap);

/*
 * Caller must define and set this : nonzero if
 * interactive , zero if daemon
 */
extern int log_to_stderr;

/*
 * Initialize syslog(),if running as daemon.
 */
void log_open(const char* ident, int option, int facility)
{
    //如果日志输出到标准错误
    if (log_to_stderr == 0)
        openlog(ident, option, facility); //打开日志
}

/*
 * Nonfatal error related to a system call.
 * Print a message with the system's errno value and return.
 */
void log_ret(const char* fmt, ...)
{
    va_list ap; //参数列表指针
    va_start(ap, fmt); //对ap初始化，让它指向可变参数列表的第一个参数
    log_doit(1, errno, LOG_ERR, fmt, ap);
    va_end(ap);//设置输入的参数设置为空
}

/*
 * Fatal error related to a system call.
 * Print a message and terminate.
 */
void log_sys(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    log_doit(1, errno, LOG_ERR, fmt, ap);
    va_end(ap);
    exit(2);
}

/* Nonfatal error unrelated to a system call.
 * Print  a message and return.
 */
void log_msg(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    log_doit(0, 0, LOG_ERR, fmt, ap);
    va_end(ap);
}

/*
 * Fatal error unrelated to a system call.
 * Print a message and terminate.
 */
void log_quit(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    log_doit(0, 0, LOG_ERR, fmt, ap);
    va_end(ap);
    exit(2);
}

/*
 * Fatal error related to a system call.
 * Error number passed as an explict parameter.
 * Print a message and terminate.
 */
void log_exit(int error, const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    log_doit(1, error, LOG_ERR, fmt, ap);
    va_end(ap);
    exit(2);
}

/*
 * Print a message and return to caller.
 * Caller apecifies "errnoflag" and "priority".
 */
static void log_doit(int errnoflag, int error, int priority, const char* fmt, va_list ap)
{
    char buf[MAXLINE];

    vsnprintf(buf, MAXLINE - 1, fmt, ap);
    if (errnoflag)
        snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": %s", strerror(error));
    strcat(buf, "\n");
    if (log_to_stderr) {
        fflush(stdout);
        fputs(buf, stderr);
        fflush(stderr);
    } else {
        syslog(priority, "%s", buf);
    }
    return;
}
