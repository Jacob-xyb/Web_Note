# 驱动

# 编译

# 配置环境 32位

## C/C++ 预处理器

设定四个参数

```cpp
MONGO_HAVE_STDINT
MONGO_HAVE_UNISTD
MONGO_USE_INT64
MONGO_USE_LONG_LONG_INT
```

## VC++目录 包含目录

```cpp
...\mongo-c-driver\include\libbson-1.0
...\mongo-c-driver\include\libmongoc-1.0
```

## 链接器 输入添加依赖项

```cpp
...\mongo-c-driver\lib\mongoc-1.0.lib
...\mongo-c-driver\lib\bson-1.0.lib
```

注意：**...\win10x64mongoc\lib\bson-static-1.0.lib**  只有在以静态链接方式时才使用，一般不使用。

## 配置dll

**将libbson-1.0.dll 及libmongoc-1.0.dll 复制到工作目录下**

# 配置环境 64位

## C/C++ 预处理器

设定四个参数

```cpp
MONGO_HAVE_STDINT
MONGO_HAVE_UNISTD
MONGO_USE_INT64
MONGO_USE_LONG_LONG_INT
```

## VC++目录 包含目录

```cpp
...\win10x64mongoc\include\libbson-1.0
...\win10x64mongoc\include\libmongoc-1.0
```

## 链接器 输入添加依赖项

```cpp
...\win10x64mongoc\lib\mongoc-1.0.lib
...\win10x64mongoc\lib\bson-1.0.lib
```

注意：**...\win10x64mongoc\lib\bson-static-1.0.lib**  只有在以静态链接方式时才使用，一般不使用。

## 配置dll

**将bson-1.0.dll 及mongoc-1.0.dll 复制到工作目录下**

# 测试程序

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mongoc/mongoc.h>
#include <bson/bson.h>

int main(int argc, char* argv[])
{
    mongoc_client_t* client;
    mongoc_collection_t* collection;
    bson_error_t error;
    bson_t* doc; /*文档名称doc*/
    const char* uristr = "mongodb://localhost:27017"; /*mongodb地址*/
    const char* collection_name = "test"; /*集合名称test*/
    time_t     now = time(0);
    char       timebuf[256] = {};
    struct  tm  cur_time;
    const char* optime;
    localtime_s(&cur_time, &now);/*获取本地当前时间*/
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", &cur_time);/*格式化时间*/
    optime = timebuf;

    mongoc_init();/*初始化*/
    if (argc > 1) {
        uristr = argv[1];
    }
    if (argc > 2) {
        collection_name = argv[2];
    }
    client = mongoc_client_new(uristr); /*连线到db */
    if (!client) {
        fprintf(stderr, "Failed to parse URI.\n");
        return EXIT_FAILURE;
    }
    mongoc_client_set_error_api(client, 2);
    collection = mongoc_client_get_collection(client, "test", collection_name);/*获取集合*/
    doc = bson_new();/*創建BSON*/
    BSON_APPEND_UTF8(doc, "Title", "Hello world ");
    BSON_APPEND_UTF8(doc, "Nowtime", optime);
    /*插入集合*/
    if (!mongoc_collection_insert(collection, MONGOC_INSERT_NONE, doc, NULL, &error))
    {
        fprintf(stderr, "%s\n", error.message);
    }
    /*释放资源*/
    bson_destroy(doc);
    mongoc_collection_destroy(collection);
    mongoc_client_destroy(client);
    mongoc_cleanup();
    system("pause");
    return EXIT_SUCCESS;
}
```

# API Reference

http://mongoc.org/libmongoc/current/index.html

http://mongoc.org/libbson/current/index.html