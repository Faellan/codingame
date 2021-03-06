#pragma once //<ck:del>

#include <string>

#include "../config/config.h"
#include "Logger.h"

using namespace std;

class Object {
    friend class Object_test;
public:
    void show();

#ifdef OBJECT_PROPERTIES
    Object(const string& name="");
    string obj_name;
    static uint64_t obj_sid;
    uint64_t obj_id;
    Logger obj_logger;
#else
    Object();
#endif
};
