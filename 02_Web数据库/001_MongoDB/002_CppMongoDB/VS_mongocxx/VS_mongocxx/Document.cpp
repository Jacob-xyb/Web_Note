#include "Document.h"



MongoDB::MongoDB() {
	//client = new mongocxx::client{ mongocxx::uri{"mongodb://localhost:27017"} };
	client = new mongocxx::client{ mongocxx::uri{"mongodb://admin:yg0074@10.100.2.50:27017"} };
	db = client->database("test");
	coll = db["col"];
}

MongoDB::~MongoDB() {
	delete client;
	client = NULL;
}



void creat_a_document_by_stream() {
	bsoncxx::builder::stream::document builder{};
	bsoncxx::document::value doc_value = builder
		<< "name" << "MongoDB"
		<< "type" << "database"
		<< "count" << 1
		<< "versions" << open_array
		<< "v3.2" << "v3.0" << "v2.6"
		<< close_array
		<< "info" << open_document
		<< "x" << 203
		<< "y" << 102
		<< close_document
		<< bsoncxx::builder::stream::finalize;
	cout << bsoncxx::to_json(doc_value) << endl;
}


void creat_a_document_by_basic() {
	// We append key-value pairs to a document using the kvp helper.
	using bsoncxx::builder::basic::kvp;
	using bsoncxx::builder::basic::sub_array;
	using bsoncxx::builder::basic::sub_document;

	// basic::document builds a BSON document.
	bsoncxx::builder::basic::document builder{};

	builder.append(kvp("name", "MongoDB"));  // string literal value will be converted to b_string automatically
	builder.append(kvp("type", "database"));
	builder.append(kvp("count", 1));

	builder.append(
		kvp("versions",
			[](sub_array subarr) {subarr.append("v3.2", "v3.0", "v2.6"); }),
		kvp("info",
			[](sub_document subdoc) {subdoc.append(
				kvp("x", 203), kvp("y", 102)
			); })
	);

	cout << bsoncxx::to_json(builder.view()) << endl;
}

void creat_a_document_by_basic_OOP() {
	bsoncxx::builder::basic::document builder{};
	bsoncxx::builder::basic::document sub{};
	bsoncxx::builder::basic::array array{};
	bsoncxx::builder::basic::array subarray{};
	sub.append(kvp("name", "MongoDB"));  // string literal value will be converted to b_string automatically
	sub.append(kvp("type", "database"));
	sub.append(kvp("count", 1));
	builder.append(kvp("sub_document", sub));

	array.append(sub);
	subarray.append(1, 2, 3, 4, 5);
	array.append(subarray, subarray, subarray);

	builder.append(kvp("array", array));

	cout << bsoncxx::to_json(builder.view()) << endl;
}


void insert_one_document() {
	MongoDB mgdb;

	bsoncxx::builder::basic::document builder{};
	builder.append(kvp("name", "_crt"), kvp("type", "profile"));

	auto res = mgdb.coll.insert_one(builder.view());
	// 返回值可以获取属性
	// ++ 获取自动插入的id;
	string oid = res.value().inserted_id().get_oid().value.to_string();
	cout << oid << endl;
}

void query_one_collection() {
	MongoDB mgdb;

	// 输入默认参数，返回一个可能的匹配结果
	bsoncxx::stdx::optional<bsoncxx::document::value> maybe_result;
	maybe_result = mgdb.coll.find_one({});
	if (maybe_result)
	{
		cout << bsoncxx::to_json(maybe_result.value().view()) << endl;
		//cout << bsoncxx::to_json(maybe_result->view()) << endl;		// 等效
	}

	// 
	maybe_result = mgdb.coll.find_one(document{} << "name" << "array" << finalize);

	if (maybe_result)
	{
		cout << bsoncxx::to_json(maybe_result.value().view()) << endl;
	}
	else {
		// 如果直接获取 view() 会报错；
		cout << "没有找到任何匹配项，调用函数返回为：" << maybe_result.has_value() << endl;
	}
}

void update_one_documents() {
	MongoDB mgdb;

	bsoncxx::builder::basic::document builder{};

	builder.append(kvp("name", "MongoDB"), kvp("type", "database"), kvp("count", 1));

	// TODO: 暂时只能通过操作符更新单个字段
	mgdb.coll.update_one(document{} << "name" << "_crt" << finalize, builder.view());
}

void delete_all_document() {
	MongoDB mgdb;
	
	bsoncxx::stdx::optional<mongocxx::result::delete_result> result =
		mgdb.coll.delete_many(
			document{} << "name" << "_crt" << finalize);

	if (result) {
		std::cout << result->deleted_count() << "\n";
	}
}

void delete_all_document_by_jx() {
	MongoDB mgdb;

	bsoncxx::builder::basic::document builder{};
	builder.append(kvp("name", "_crt"), kvp("type", "profile"));

	// 1. 先删除匹配项
	mgdb.coll.delete_many(
		document{} << "name" << "_crt" << "type" << "profile" << finalize);

	// 2. 再插入
	mgdb.coll.insert_one(builder.view());
}