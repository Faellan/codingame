#include <iostream>

#include "../config/config.h"
#include "my_assert.h"
#include "Object.h"

using namespace std;

#ifdef OBJECT_PROPERTIES

uint64_t Object::obj_sid = 0;

#ifdef LOG_ON_COUT
Object::Object(const string& name) : obj_logger(this, cout) {
#else
Object::Object(const string& name) : obj_logger(this, cerr) {
#endif
    obj_id = ++Object::obj_sid;
    obj_name = name;
    ASSERT(obj_id == Object::obj_sid);
    ASSERT(obj_name == name);
}

void Object::show() {
    cerr << "Object " << obj_name << ":" << obj_id << endl;
}
#else
Object::Object() {

}

void show() {
    cerr << "Object" << endl;
}
#endif