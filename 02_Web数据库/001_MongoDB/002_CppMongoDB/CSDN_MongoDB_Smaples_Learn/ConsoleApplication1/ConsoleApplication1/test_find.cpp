#include "test_find.h"


void find_a_document() {
	MongoDBClient client;
	bson_t* query;
	const bson_t* doc;
	mongoc_cursor_t* cursor;
	//query = bson_new();
	query = BCON_NEW("title", BCON_UTF8("tmp_profile"));
	cursor = mongoc_collection_find_with_opts(client.collection, query, NULL, NULL);

	int64_t count = mongoc_collection_count(
		client.collection, MONGOC_QUERY_NONE, query, 0, 0, NULL, NULL);

	cout << count << endl;

	if (count != 0)
	{
		mongoc_cursor_next(cursor, &doc);
	}
	else {
		return;
	}

	bson_iter_t iter;

	if (bson_iter_init(&iter, doc)) {
		//while (bson_iter_next(&iter)) {
		//	printf("Found a field named: %s\n", bson_iter_key(&iter));
		//	cout << bson_iter_value(&iter) << endl;;
		//}
		bson_iter_find(&iter, "title");
		cout << bson_iter_key(&iter) << endl;
		cout << bson_iter_utf8(&iter, NULL) << endl;
	}

	char* j;
	j = bson_as_canonical_extended_json(doc, NULL);
	cout << j << endl;
}