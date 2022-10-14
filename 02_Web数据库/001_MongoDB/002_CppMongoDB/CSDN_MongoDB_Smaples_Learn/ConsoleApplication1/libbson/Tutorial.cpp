#include "Tutorial.h"

void hello_bson() {
	bson_t* b;
	char* j;

	b = BCON_NEW("hello", BCON_UTF8("bson!"));
	j = bson_as_canonical_extended_json(b, NULL);
	printf("%s\n", j);

	bson_free(j);
	bson_destroy(b);
}

void creatingANewBSONDocument() {
	// 栈上创建一个 bson
	bson_t b;
	char* j;

	bson_init(&b);
	j = bson_as_canonical_extended_json(&b, NULL);
	cout << j << endl;		// { }
	bson_destroy(&b);

	// ++ 不用函数的创建方法：
	bson_t b1 = BSON_INITIALIZER;
	j = bson_as_canonical_extended_json(&b, NULL);
	cout << j << endl;		// { }

	// 从堆上创建一个 bson
	bson_t* new_b;
	new_b = BCON_NEW("hello", BCON_UTF8("bson!"));
	j = bson_as_canonical_extended_json(&b, NULL);
	cout << j << endl;		// { }
	bson_destroy(new_b);

	bson_free(j);
}

// 习惯用堆来创建
void bson_append_() {
	bson_t* b = bson_new();
	bson_t* b_macros = bson_new();
	char* j1, * j2;

	// -1 代表用 strlen() 计算长度
	bson_append_utf8(b, "key", -1, "value", -1);
	bson_append_int32(b, "int32", -1, 1);
	bson_append_bool(b, "bool", -1, false);
	// macros
	BSON_APPEND_UTF8(b_macros, "key", "value");
	BSON_APPEND_INT32(b_macros, "int32", 1);
	BSON_APPEND_BOOL(b_macros, "bool", false);
	// print
	j1 = bson_as_canonical_extended_json(b, NULL);
	cout << "b:" << j1 << endl;

	j2 = bson_as_canonical_extended_json(b_macros, NULL);
	cout << "b_macros:" << j2 << endl;
	bson_destroy(b);
	bson_free(j1);
	bson_free(j2);
}

void bson_append_arrayString() {
	const char* lang_names[] = { "MATH-MATIC", "FLOW-MATIC", "COBOL" };
	bson_t* doc;
	bson_t child;
	char* j;
	size_t keylen;
	char buf[16];
	const char* key;

	doc = bson_new();
	BSON_APPEND_ARRAY_BEGIN(doc, "languages", &child);
	for (uint32_t i = 0; i < sizeof lang_names / sizeof(char*); ++i) {
		keylen = bson_uint32_to_string(i, &key, buf, sizeof buf);
		//bson_append_utf8(&child, key, (int)keylen, lang_names[i], -1);
		BSON_APPEND_UTF8(&child, key, lang_names[i]);
	}
	bson_append_array_end(doc, &child);
	j = bson_as_canonical_extended_json(doc, NULL);
	cout << j << endl;
	
	bson_free(j);
	bson_destroy(doc);
}

void bson_append_sub_document() {
	bson_t parent;
	bson_t child;
	char* str;

	bson_init(&parent);
	// ++ begin 会初始化 sub_document
	bson_append_document_begin(&parent, "foo", 3, &child);
	bson_append_int32(&child, "baz", 3, 1);
	bson_append_document_end(&parent, &child);

	str = bson_as_canonical_extended_json(&parent, NULL);
	printf("%s\n", str);
	bson_free(str);

	bson_destroy(&parent);

	// 上述方式需要传入一个未初始化的 bson，然后再进行添加内容，
	//衍生出传入一个完整的 bson 方法。

	bson_t parent1, child1;
	bson_init(&parent1);
	bson_init(&child1);
	bson_append_int32(&child1, "baz", 3, 1);
	bson_append_document(&parent1, "foo", -1, &child1);
	str = bson_as_canonical_extended_json(&parent1, NULL);
	printf("%s\n", str);
	bson_free(str);
	bson_destroy(&child1);
	bson_destroy(&parent1);
}


void bson_append_sub_array() {
	bson_t* parent = bson_new();
	bson_t* child = bson_new();
	char* str;

	// ++ begin 会初始化 sub_document
	bson_append_array_begin(parent, "foo", 3, child);
	BSON_APPEND_INT32(child, "0", 1);
	BSON_APPEND_INT32(child, "1", 2);
	BSON_APPEND_INT32(child, "2", 3);
	BSON_APPEND_INT32(child, "3", 4);
	bson_append_array_end(parent, child);

	str = bson_as_canonical_extended_json(parent, NULL);
	printf("%s\n", str);
	bson_free(str);

	bson_destroy(parent);
}

void bson_append_sub_array1() {
	bson_t* parent = bson_new();
	bson_t* child = bson_new();
	char* str;

	// ++ begin 会初始化 sub_document
	BSON_APPEND_INT32(child, "0", 1);
	BSON_APPEND_INT32(child, "1", 2);
	BSON_APPEND_INT32(child, "2", 3);
	BSON_APPEND_INT32(child, "3", 4);
	BSON_APPEND_ARRAY(parent, "fo", child);

	str = bson_as_canonical_extended_json(parent, NULL);
	printf("%s\n", str);
	bson_free(str);

	bson_destroy(parent);
}

void BSONCObjectNotation() {
	bson_t* doc;
	char* str;

	doc = BCON_NEW("foo",
		"{", "int", BCON_INT32(1), "array",
		"[", BCON_INT32(100), "{", "sub", BCON_UTF8("value"), "}", "]",
		"}");
	str = bson_as_canonical_extended_json(doc, NULL);
	printf("%s\n", str);
	bson_free(str);
	bson_destroy(doc);
}

void BSONCObjectNotation1() {
	bson_t* doc;
	bson_t* tmp_doc;
	char* str;
	doc = bson_new();
	tmp_doc = BCON_NEW("foo", BCON_INT32(1));
	BSON_APPEND_DOCUMENT(doc, "d1", tmp_doc);
	tmp_doc = BCON_NEW("foo", BCON_INT32(2));
	BSON_APPEND_DOCUMENT(doc, "d2", tmp_doc);

	str = bson_as_canonical_extended_json(doc, NULL);
	printf("%s\n", str);
	bson_free(str);
	bson_destroy(doc);
	bson_destroy(tmp_doc);
}