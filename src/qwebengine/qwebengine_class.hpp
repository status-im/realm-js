////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#pragma once

#include "qwebengine_types.hpp"

#include "js_class.hpp"
#include "js_util.hpp"

namespace realm {
namespace qwebengine {

template<typename T>
using ClassDefinition = js::ClassDefinition<Types, T>;

using ConstructorType = js::ConstructorType<Types>;
using MethodType = js::MethodType<Types>;
using ArgumentsMethodType = js::ArgumentsMethodType<Types>;
using Arguments = js::Arguments<Types>;
using PropertyType = js::PropertyType<Types>;
using IndexPropertyType = js::IndexPropertyType<Types>;
using StringPropertyType = js::StringPropertyType<Types>;

template<typename ClassType>
class ObjectWrap {
    using Internal = typename ClassType::Internal;
    using ParentClassType = typename ClassType::Parent;

  public:
    static QVariant create_constructor(QVariant);
    static QVariant create_instance(QVariant, Internal* = nullptr);

    static QVariant get_template() {
        static QVariant js_template(create_template());
        return js_template;
    }

    static void construct(const QVariant&);

    static bool has_instance(QVariant isolate, const QVariant &value) {
        return false; //get_template()->HasInstance(value);
    }

    operator Internal*() const {
        return m_object.get();
    }

    ObjectWrap<ClassType>& operator=(Internal* object) {
        if (m_object.get() != object) {
            m_object = std::unique_ptr<Internal>(object);
        }
        return *this;
    }

  private:
    static ClassType s_class;

    std::unique_ptr<Internal> m_object;

    ObjectWrap(Internal* object = nullptr) : m_object(object) {}

    static QVariant create_template();

    static void setup_method(QVariant, const std::string &, QVariant);
    static void setup_static_method(QVariant, const std::string &, QVariant);

    template<typename TargetType>
    static void setup_property(QVariant, const std::string &, const PropertyType &);

    static void get_indexes(const QVariant&);
    static void set_property(QVariant, QVariant, const QVariant&);

    static void set_readonly_property(QVariant property, QVariant value, const QVariant& info) {
        std::string message = std::string("Cannot assign to read only property '") + std::string(String(property)) + "'";
        //Nan::ThrowError(message.c_str());
    }

    static void set_readonly_index(uint32_t index, QVariant value, const QVariant& info) {
        std::string message = std::string("Cannot assign to read only index ") + util::to_string(index);
        //Nan::ThrowError(message.c_str());
    }

    static void get_nonexistent_property(QVariant, const QVariant&) {
        // Do nothing. This function exists only to prevent a crash where it is used.
    }
};

template<>
class ObjectWrap<void> {
  public:
    using Internal = void;

    static QVariant get_template() {
        return QVariant();
    }
};

// This helper function is needed outside the scope of the ObjectWrap class as well.
static inline std::vector<QVariant> get_arguments(const QVariant &info) {
    int count = info.toList().length();
    std::vector<QVariant> arguments;
    arguments.reserve(count);

    for (int i = 0; i < count; i++) {
        arguments.push_back(info.toList()[i]);
    }
    
    return arguments;
}

// The static class variable must be defined as well.
template<typename ClassType>
ClassType ObjectWrap<ClassType>::s_class;

template<typename ClassType>
inline QVariant ObjectWrap<ClassType>::create_constructor(QVariant isolate) {
    return QVariant();
}

template<typename ClassType>
inline QVariant ObjectWrap<ClassType>::create_instance(QVariant isolate, Internal* internal) {
    return QVariant();
}

template<typename ClassType>
inline QVariant ObjectWrap<ClassType>::create_template() {
    return QVariant();
}

template<typename ClassType>
inline void ObjectWrap<ClassType>::setup_method(QVariant tpl, const std::string &name, QVariant callback) {

}

template<typename ClassType>
inline void ObjectWrap<ClassType>::setup_static_method(QVariant tpl, const std::string &name, QVariant callback) {

}

template<typename ClassType>
template<typename TargetType>
inline void ObjectWrap<ClassType>::setup_property(QVariant target, const std::string &name, const PropertyType &property) {
}

template<typename ClassType>
inline void ObjectWrap<ClassType>::construct(const QVariant& info) {
}

template<typename ClassType>
inline void ObjectWrap<ClassType>::get_indexes(const QVariant& info) {
}

template<typename ClassType>
inline void ObjectWrap<ClassType>::set_property(QVariant property, QVariant value, const QVariant& info) {
}

} // node

namespace js {

template<typename ClassType>
class ObjectWrap<qwebengine::Types, ClassType> : public qwebengine::ObjectWrap<ClassType> {};

template<qwebengine::MethodType F>
void wrap(const QVariant& info) {
}

template<qwebengine::ArgumentsMethodType F>
void wrap(const QVariant& info) {
}


template<qwebengine::PropertyType::GetterType F>
void wrap(QVariant property, const QVariant& info) {
}

template<qwebengine::PropertyType::SetterType F>
void wrap(QVariant property, QVariant value, const QVariant& info) {
}

template<qwebengine::IndexPropertyType::GetterType F>
void wrap(uint32_t index, const QVariant& info) {
}

template<qwebengine::IndexPropertyType::SetterType F>
void wrap(uint32_t index, QVariant value, const QVariant& info) {
}

template<qwebengine::StringPropertyType::GetterType F>
void wrap(QVariant property, const QVariant& info) {
}

template<qwebengine::StringPropertyType::SetterType F>
void wrap(QVariant property, QVariant value, const QVariant& info) {
}

template<qwebengine::StringPropertyType::EnumeratorType F>
void wrap(const QVariant& info) {
}

} // js
} // realm
