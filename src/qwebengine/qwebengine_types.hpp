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

#include <cmath>
#include <functional>
#include <map>
#include <string>

#include <QVariant>

#include "js_types.hpp"

#define HANDLESCOPE

namespace realm {
namespace qwebengine {

struct Types {
    using Context = QVariant;
    using GlobalContext = QVariant;
    using Value = QVariant;
    using Object = QVariant;
    using String = QVariant;
    using Function = QVariant;

    using ConstructorCallback = QVariant;
    using FunctionCallback = QVariant;
    using PropertyGetterCallback = QVariant;
    using PropertySetterCallback = QVariant;
    using IndexPropertyGetterCallback = QVariant;
    using IndexPropertySetterCallback = QVariant;
    using StringPropertyGetterCallback = QVariant;
    using StringPropertySetterCallback = QVariant;
    using StringPropertyEnumeratorCallback = QVariant;
};

template<typename ClassType>
class ObjectWrap;

using String = js::String<Types>;
using Context = js::Context<Types>;
using Value = js::Value<Types>;
using Function = js::Function<Types>;
using Object = js::Object<Types>;
using Exception = js::Exception<Types>;
using ReturnValue = js::ReturnValue<Types>;

} // node
} // realm
