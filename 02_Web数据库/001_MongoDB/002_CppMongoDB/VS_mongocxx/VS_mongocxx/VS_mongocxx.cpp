// VS_mongocxx.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Document.h"
#include "jx_CRDU.h"


mongocxx::instance _instance{};

void sample() {
	mongocxx::instance instance{}; // This should be done only once.
	mongocxx::client client{ mongocxx::uri{"mongodb://admin:yg0074@10.100.2.50:27017"} };
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
	cout << bsoncxx::to_json(doc_value) << endl;
}


int main()
{
	test_read_origin_database();
	//creat_a_document_by_basic_OOP();
}