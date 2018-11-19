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
inline QVariant qwebengine::Context::get_global_context(QVariant) {
    return QVariant();
}

template<>
inline AbstractExecutionContextID qwebengine::Context::get_execution_context_id(QVariant)
{
    return reinterpret_cast<AbstractExecutionContextID>(123ul);
}

} // js
} // realm
