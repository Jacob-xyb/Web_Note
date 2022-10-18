# C驱动

## 编译

## 配置环境 32位

### C/C++ 预处理器

设定四个参数

```cpp
MONGO_HAVE_STDINT
MONGO_HAVE_UNISTD
MONGO_USE_INT64
MONGO_USE_LONG_LONG_INT
```

### VC++目录 包含目录

```cpp
...\mongo-c-driver\include\libbson-1.0
...\mongo-c-driver\include\libmongoc-1.0
```

### 链接器 输入添加依赖项

```cpp
...\mongo-c-driver\lib\mongoc-1.0.lib
...\mongo-c-driver\lib\bson-1.0.lib
```

注意：**...\win10x64mongoc\lib\bson-static-1.0.lib**  只有在以静态链接方式时才使用，一般不使用。

### 配置dll

**将libbson-1.0.dll 及libmongoc-1.0.dll 复制到工作目录下**

## 配置环境 64位

### C/C++ 预处理器

设定四个参数

```cpp
MONGO_HAVE_STDINT
MONGO_HAVE_UNISTD
MONGO_USE_INT64
MONGO_USE_LONG_LONG_INT
```

### VC++目录 包含目录

```cpp
...\win10x64mongoc\include\libbson-1.0
...\win10x64mongoc\include\libmongoc-1.0
```

### 链接器 输入添加依赖项

```cpp
...\win10x64mongoc\lib\mongoc-1.0.lib
...\win10x64mongoc\lib\bson-1.0.lib
```

注意：**...\win10x64mongoc\lib\bson-static-1.0.lib**  只有在以静态链接方式时才使用，一般不使用。

### 配置dll

**将bson-1.0.dll 及mongoc-1.0.dll 复制到工作目录下**

## 测试程序

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

# C++ 驱动

## 编译

请先安装boost最新版本。地址: https://sourceforge.net/projects/boost/files/boost-binaries/1.72.0/

## 测试程序

```cpp
#include <iostream>
#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

int main()
{
	mongocxx::instance instance{}; // This should be done only once.
	mongocxx::client client{ mongocxx::uri{"mongodb://localhost:27017"} };
	mongocxx::database db = client["test"];
	mongocxx::collection coll = db["col"];

	auto builder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc_value = builder
		<< "name" << "MongoDB"
		<< "type" << "database"
		<< "count" << 1
		<< "versions" << bsoncxx::builder::stream::open_array
		<< "v3.2" << "v3.0" << "v2.6"
		<< close_array
		<< "info" << bsoncxx::builder::stream::open_document
		<< "x" << 203
		<< "y" << 102
		<< bsoncxx::builder::stream::close_document
		<< bsoncxx::builder::stream::finalize;
	coll.insert_one(doc_value.view());
}
```

## VC++目录 包含目录

```cpp
...\mongocxx\include
```

## 链接器 输入

```cpp
...\mongocxx\lib\bsoncxx.lib
...\mongocxx\lib\mongocxx.lib
```

## 调试 环境

```cpp
PATH=...\mongocxx\bin
```

# API Reference

http://mongoc.org/libmongoc/current/index.html

http://mongoc.org/libbson/current/index.html

https://mongocxx.org/mongocxx-v3/tutorial/

