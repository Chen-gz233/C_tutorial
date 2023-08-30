

aux_source_directory(. LIB_SRCS)     # 添加当前目录下所有的源文件


add_library (src SHARED ${LIB_SRCS})   # 用指定文件编译库文件       当前目录下的文件生成一个链接库
                                        #用于指定从一组源文件 source1 source2 … sourceN 编译出一个库文件且命名为 name
