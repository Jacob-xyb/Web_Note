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
	// ջ�ϴ���һ�� bson
	bson_t b;
	char* j;

	bson_init(&b);
	j = bson_as_canonical_extended_json(&b, NULL);
	cout << j << endl;		// { }

	// �Ӷ��ϴ���һ�� bson
	bson_t* new_b;
	new_b = BCON_NEW("hello", BCON_UTF8("bson!"));
	j = bson_as_canonical_extended_json(&b, NULL);
	cout << j << endl;		// { }
	bson_destroy(new_b);

	bson_free(j);
}

// ϰ���ö�������
void bson_append_() {
	bson_t* b = bson_new();
	bson_t* b_macros = bson_new();
	char *j1, *j2;

	// -1 ������ strlen() ���㳤��
	bson_append_utf8(b, "key", -1, "value", -1);
	// macros
	BSON_APPEND_UTF8(b_macros, "key", "value");
	j1 = bson_as_canonical_extended_json(b, NULL);
	cout << "b:" << j1 << endl;

	j2 = bson_as_canonical_extended_json(b_macros, NULL);
	cout << "b_macros:" << j2 << endl;
	bson_destroy(b);
	bson_free(j1);
	bson_free(j2);
}