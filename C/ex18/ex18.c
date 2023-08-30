#include <stdio.h>
#include "ex18.h"
#include "dbg.h"

int THE_SIZE = 1000;

static int THE_AGE = 37;

int get_age()
{
    return THE_AGE;
}

void set_age(int age)
{
    THE_AGE = age;
}


double update_ratio(double new_ratio)
{
    static double ratio = 1.0;
    //这个关键词某种意义上是extern的反义词，
    //意思是这个变量只能在当前的.c文件中使用，程序的其它部分不可访问。
    //要记住文件级别的static（比如这里的THE_AGE）和其它位置不同。

    //如果你使用static在函数中声明变量，它和文件中的static定义类似，但是只能够在该函数中访问。
    //它是一种创建某个函数的持续状态的方法，但事实上它很少用于现代的C语言，因为它们很难和线程一起使用。

    
    double old_ratio = ratio;
    ratio = new_ratio;

    return old_ratio;
}

void print_size()
{
    log_info("I think size is: %d", THE_SIZE);
}