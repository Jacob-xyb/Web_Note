#include "jx_CRDU.h"

using namespace std;

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
	cout << bs_view["string"].get_utf8().value.to_string() << endl;;
	cout << bs_view["bool"].get_bool().value << endl;;
	cout << "判断类型(double)：\t" << (bs_view["double"].type() == bsoncxx::type::k_double) << endl;
	cout << "判断类型(int)：\t" << (bs_view["double"].type() == bsoncxx::type::k_int64) << endl;

	// ++ 获取一个不存在的数据
	cout << bool(bs_view["noexists"]) << endl;
}