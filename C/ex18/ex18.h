#ifndef _ex22_h
#define _ex22_h

// makes THE_SIZE in ex22.c available to other .c files
extern int THE_SIZE;
//这个关键词告诉编译器“这个变量已存在，但是他在别的‘外部区域’里”。
//通常它的意思是一个.c文件要用到另一个.c文件中定义的变量。

// gets and sets an internal static variable in ex22.c
int get_age();
void set_age(int age);

// updates a static variable that's inside update_ratio
double update_ratio(double ratio);

void print_size();

#endif