#include "test_insert.h"

void test_insert() {
	MongoDBClient client;
	// »ù´¡ÀàÐÍ£º
	//BSON_APPEND_BOOL();

	BSON_APPEND_UTF8(client.doc, "Title", "Hello world ");

	if (!mongoc_collection_insert(client.collection, MONGOC_INSERT_NONE, client.doc, NULL, &client.error))
	{
		fprintf(stderr, "%s\n", client.error.message);
	}
}