#include "jx_CRDU.h"

using namespace std;

void transform_bson_data() {
	MongoDB mgdb;
	mgdb.coll = mgdb.db["transform"];

	// �������
	mgdb.coll.delete_many({});

	// ���� bson ����
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

	// ���� bson ����
	mgdb.coll.insert_one(bson.view());

	// ��ѯ���ݿ� ��ȡ���
	auto find_res = mgdb.coll.find_one({});
	auto bs_view = find_res->view();
	cout << bs_view["string"].get_utf8().value.to_string() << endl;;
	cout << bs_view["bool"].get_bool().value << endl;;
	cout << "�ж�����(double)��\t" << (bs_view["double"].type() == bsoncxx::type::k_double) << endl;
	cout << "�ж�����(int)��\t" << (bs_view["double"].type() == bsoncxx::type::k_int64) << endl;

	// ++ ��ȡһ�������ڵ�����
	cout << bool(bs_view["noexists"]) << endl;
}