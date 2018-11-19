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

#include <stdexcept>
#include <vector>

#include "../platform.hpp"

namespace realm {

// taken from Node.js: function Cwd in node.cc
std::string default_realm_file_directory()
{
    throw std::runtime_error("Realm qwebengine support for this method is not implemented");
    return std::string("To be implemented");
}

void ensure_directory_exists_for_file(const std::string &file_path)
{
    throw std::runtime_error("Realm qwebengine support for this method is not implemented");
}

void copy_bundled_realm_files()
{
    throw std::runtime_error("Realm for Node does not support this method.");
}

inline bool ends_with(const std::string& str, const std::string& suffix) {
    return str.size() > suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void remove_realm_files_from_directory(const std::string &dir_path)
{
    throw std::runtime_error("Realm qwebengine support for this method is not implemented");
}

void remove_directory(const std::string &path)
{
    throw std::runtime_error("Realm qwebengine support for this method is not implemented");
}

void remove_file(const std::string &path)
{
    throw std::runtime_error("Realm qwebengine support for this method is not implemented");
}

} // realm
