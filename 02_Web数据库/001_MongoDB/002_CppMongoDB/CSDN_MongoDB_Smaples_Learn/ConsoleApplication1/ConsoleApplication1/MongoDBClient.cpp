#include "MongoDBClient.h"


MongoDBClient::MongoDBClient() {
	const char* uristr = "mongodb://localhost:27017"; /*mongodb��ַ*/
	const char* collection_name = "col"; /*��������test*/
	client = mongoc_client_new(uristr); /*���ߵ�db */
	if (!client) {
		status = false;
	}
	mongoc_client_set_error_api(client, 2);
	collection = mongoc_client_get_collection(client, "test", collection_name); /*��ȡ����*/
	doc = bson_new();	// ��ʼ�� document
}

MongoDBClient::~MongoDBClient() {
	bson_destroy(doc);
	mongoc_collection_destroy(collection);
	mongoc_client_destroy(client);
}