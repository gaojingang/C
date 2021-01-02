cmake_minimum_required(VERSION 3.18.0)
project("outProject" VERSION 1.0.0)

# 一个依赖类的编译
# add_executable(outProject main.cpp swap.cpp)

# 两个依赖类的编译  圆与与圆心的关系
# add_executable(outProject 008Classfengzhuang/TestMain.cpp  008Classfengzhuang/Point.cpp   008Classfengzhuang/Circel.cpp )


# 类的初始化，构造函数 析构函数
# add_executable(outProject 008ClassInit/Test.cpp)

# 类的初始化，函数分类调用
# add_executable(outProject 008ClassInit/Classinit03.cpp)

# 类的初始化，函数的浅拷贝与深拷贝
# add_executable(outProject 008ClassInit/ClassCopyMethod.cpp)

# 类的初始化，初始化列表
# add_executable(outProject 008ClassInit/ClassInitMethodList.cpp)

# 类的初始化，类对象作为类成员
# add_executable(outProject 008ClassInit/ClassInit04.cpp)

# 类的初始化，静态成员函数
# add_executable(outProject 008ClassInit/ClassStatic05.cpp)


# 文件写1 
# add_executable(outProject 009FileRead/textWrite01.cpp)
# 文件读1
# add_executable(outProject 009FileRead/FileRead01.cpp)

# 文件 二进制 写入
# add_executable(outProject 009FileRead/binWrite01.cpp)

# 文件 二进制 读取
# add_executable(outProject 009FileRead/binRide01.cpp)

# 文件 二进制 读取2
# add_executable(outProject 009FileRead/binRead02.cpp)


# 引入 openssl

set(OPENSSL_INC_DIR D:/dev/lib/openssl-1.1/x86/include/)  
set(OPENSSL_LINK_DIR D:/dev/lib/openssl-1.1/x86/lib)
set(SRC_LIST  009FileRead/binWite03.cpp )

# 去哪里找头文件 相当于gcc/clang 中的-I(i的大写字母)参数
include_directories(${OPENSSL_INC_DIR})  
# include_directories(${OPENSSL_LINK_DIR})  

find_library(crypto_lib crypto ${OPENSSL_LINK_DIR})
# 去哪里找库文件 .so .dll .dylib 相当于gcc 中的-L参数
link_directories(${OPENSSL_LINK_DIR})
# 要链接的库文件的名字 相当于gcc中的-l(小写的l)参数


# 文件 二进制 读取3
add_executable(outProject 009FileRead/binWrite03.cpp)
target_link_libraries(outProject LINK_PUBLIC ${crypto_lib})

# 文件 二进制 文件头信息读取编辑 test
# add_executable(outProject 009FileRead/binWrite03.cpp)