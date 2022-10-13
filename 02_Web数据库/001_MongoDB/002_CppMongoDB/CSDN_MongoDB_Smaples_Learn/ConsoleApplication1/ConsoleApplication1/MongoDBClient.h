#pragma once
#include <mongoc/mongoc.h>
#include <bson/bson.h>

class MongoDBClient {
public:
	MongoDBClient();
	~MongoDBClient();
	bool status = true;
	bson_t* doc; /*ÎÄµµÃû³Ædoc*/
	bson_error_t error;
	mongoc_client_t* client;
	mongoc_collection_t* collection;
private:
};



