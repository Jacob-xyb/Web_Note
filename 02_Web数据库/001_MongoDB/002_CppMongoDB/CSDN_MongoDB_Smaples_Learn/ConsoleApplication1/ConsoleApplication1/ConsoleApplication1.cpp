#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <mongoc/mongoc.h>
#include <bson/bson.h>

#include "test_insert.h"

using namespace std;

int sample() {
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
    //if (argc > 1) {
    //    uristr = argv[1];
    //}
    //if (argc > 2) {
    //    collection_name = argv[2];
    //}
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

    bson_t* arr;
    arr = bson_new();
    BSON_APPEND_DOUBLE(arr, "0", 33);
    BSON_APPEND_DOUBLE(arr, "1", 34);
    BSON_APPEND_DOUBLE(arr, "2", 35);
    BSON_APPEND_DOUBLE(arr, "3", 36);
    BSON_APPEND_ARRAY(doc, "num", arr);
    bson_destroy(arr);
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
    return EXIT_SUCCESS;
}

int sample_client() {
    MongoDBClient client;

    // 获取 database 信息
    bson_error_t error;
    char** strv;
    unsigned i;

    if (strv = mongoc_client_get_database_names_with_opts(client.client, NULL, &error)) {
        for (i = 0; strv[i]; i++)
            printf("%s\n", strv[i]);
        bson_strfreev(strv);    // 字符串数组应该这样释放
    }
    else {
        fprintf(stderr, "Command failed: %s\n", error.message);
    }

    return 0;
}


int main(int argc, char* argv[])
{
    mongoc_init();/*初始化*/
    sample_client();

    //test_insert();
    mongoc_cleanup();
    system("pause");
    return EXIT_SUCCESS;
}
