#pragma once

#include <iostream>
#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;
using bsoncxx::builder::basic::kvp;

using namespace std;

class MongoDB {
public:
	MongoDB();
	~MongoDB();
	mongocxx::instance* instance;
	mongocxx::client* client;
	mongocxx::database db;
	mongocxx::collection coll;
};



void creat_a_document_by_stream();
void creat_a_document_by_basic();
void creat_a_document_by_basic_OOP();
void insert_one_document();
void query_one_collection();
void delete_all_document();
void delete_all_document_by_jx();