#include "MongoDBClient.h"


MongoDBClient::MongoDBClient() {
	const char* uristr = "mongodb://localhost:27017"; /*mongodb地址*/
	const char* collection_name = "test"; /*集合名称test*/
	client = mongoc_client_new(uristr); /*连线到db */
	if (!client) {
		status = false;
	}
	mongoc_client_set_error_api(client, 2);
	collection = mongoc_client_get_collection(client, "test", collection_name); /*获取集合*/
	doc = bson_new();	// 初始化 document
}

MongoDBClient::~MongoDBClient() {
	bson_destroy(doc);
	mongoc_collection_destroy(collection);
	mongoc_client_destroy(client);
}