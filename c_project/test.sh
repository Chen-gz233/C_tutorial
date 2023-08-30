#!/bin/bash

read -p "file number : " number #读取文件的名称，（按照提示）
test -e cmake_test$number && echo "cmake_test$number is exist"  || "cmake_test$number is not exist"  #检测变量name这个文件名是否存在，若存（&&）打印存在，若不存在（||）打印不存在
int=1
while(( $int <= $number ))
do
    rm -rf cmake_test$int/build/*
    echo "$int"
    let "int++"
done

#根据上面的例子，读取第一个字符串，和第二个字符串，比较字符串是否相同，若相同，输出match，不相同，输出 no match
#read -p "first string :"  fstring
#read -p "second string : "  sstring
#test $fstring == $sstring && echo "match" || echo "no match"  