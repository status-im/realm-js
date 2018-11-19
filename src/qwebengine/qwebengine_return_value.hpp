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

namespace realm {
namespace js {

template<>
class ReturnValue<qwebengine::Types> {
    QVariant m_value;

  public:
    ReturnValue(QVariant value) : m_value(value) {}

    void set(const QVariant &value) {
        m_value = value;
    }
    void set(const std::string &string) {
        if (string.empty()) {
            m_value = QString("");
        }
        else {
            m_value = QString(string.c_str());
        }
    }
    void set(const char *str) {
        if (!str) {
            m_value = QVariant();
        }
        else if (!*str) {
            m_value = QString("");
        }
        else {
            m_value = QString(str);
        }
    }
    void set(bool boolean) {
        m_value = boolean;
    }
    void set(double number) {
        m_value = number;
    }
    void set(int32_t number) {
        m_value = number;
    }
    void set(uint32_t number) {
        m_value = number;
    }
    void set(realm::Mixed mixed) {
        //m_value.Set(Value<qwebengine::Types>::from_mixed(nullptr, mixed));
    }
    void set_null() {
        m_value = QVariant();
    }
    void set_undefined() {
        m_value = QVariant();
    }

    template<typename T>
    void set(util::Optional<T> value) {
        if (value) {
            set(*value);
        }
        else {
            m_value = QVariant();
        }
    }
};
    
} // js
} // realm
