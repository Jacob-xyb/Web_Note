#include "test_insert.h"

void test_insert() {
	MongoDBClient client;
	// 基础类型：
	//BSON_APPEND_BOOL();

	BSON_APPEND_UTF8(client.doc, "Title", "Hello world");
	BSON_APPEND_INT32(client.doc, "int32", 1);

	// mongoc_collection_insert 已经弃用，改为 mongoc_collection_insert_one
	if (!mongoc_collection_insert(client.collection, MONGOC_INSERT_NONE, client.doc, NULL, &client.error))
	{
		fprintf(stderr, "%s\n", client.error.message);
	}
}

void test_insert1() {
	MongoDBClient client;
	client.doc = BCON_NEW("title", BCON_UTF8("tmp_profile"),
		"isRoughness", BCON_BOOL(false),
		"layer_num", BCON_INT32(0));
	mongoc_collection_insert_one(client.collection, client.doc, NULL, NULL, NULL);
}
