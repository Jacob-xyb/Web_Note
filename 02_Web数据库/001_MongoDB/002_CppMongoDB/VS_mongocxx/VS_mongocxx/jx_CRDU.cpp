#include "jx_CRDU.h"

using namespace std;

void test_read_origin_database() {
	MongoDB mgdb;
	mgdb.db = mgdb.client->database("EometricsPro");
	mgdb.coll = mgdb.db.collection("tmp");

	bsoncxx::builder::basic::document query;
	query.append(kvp("type", "profile"));

	auto q_res = mgdb.coll.find_one(query.view());
	bsoncxx::document::view bson = q_res->view();


	//cout << bsoncxx::to_json(bson) << endl;
	//cout << bson["waveMin"].get_double().value << endl;
	// 
	//cout << bsoncxx::to_json(bson["v_lay_ui"].get_array().value) << endl;
	//cout << bsoncxx::to_json(bson["v_lay_ui"].get_array().value[0].get_document().view()) << endl;

	// 对于 array 只能用迭代器来进行遍历获取
	for (auto& arr : bson["v_lay_ui"].get_array().value)
	{
		cout << bsoncxx::to_json(arr.get_document().view()) << endl;

	}
	//cout << bson["v_lay_ui"].get_array().value[0] << endl;
}

void transform_bson_data() {
	MongoDB mgdb;
	mgdb.coll = mgdb.db["transform"];

	// 清空数据
	mgdb.coll.delete_many({});

	// 创建 bson 数据
	bsoncxx::builder::basic::document bson;
	bson.append(kvp("string", "hello world"));
	bson.append(kvp("bool", false));
	bson.append(kvp("double", double(1)));

	bsoncxx::builder::basic::array subarray;

	for (size_t i = 0; i < 10; i++)
	{
		subarray.append(double(i));
	}

	bson.append(kvp("double_array", subarray));

	// 插入 bson 数据
	mgdb.coll.insert_one(bson.view());

	// 查询数据库 获取结果
	auto find_res = mgdb.coll.find_one({});
	auto bs_view = find_res->view();
	//cout << bs_view["string"].get_utf8().value.to_string() << endl;
	cout << bs_view["string"].get_string().value << endl;
	cout << bs_view["bool"].get_bool().value << endl;
	cout << "判断类型(double)：\t" << (bs_view["double"].type() == bsoncxx::type::k_double) << endl;
	cout << "判断类型(int)：\t" << (bs_view["double"].type() == bsoncxx::type::k_int64) << endl;

	// ++ 获取一个不存在的数据
	cout << bool(bs_view["noexists"]) << endl;
}