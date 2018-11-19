set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_TYPE_NAMES ${REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_TYPE_NAMES}
                                                     \"Realm\" PARENT_SCOPE)

set(REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_SRC ${REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_SRC}
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_realm.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_init.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/platform.cpp"

        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/concurrent_deque.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/event_loop_dispatcher.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_class.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_collection.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_list.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_object_accessor.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_observable.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_realm.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_realm_object.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_results.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_schema.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_sync.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_types.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/js_util.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_class.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_context.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_exception.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_function.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_init.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_object.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_protected.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_return_value.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_string.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_types.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine/qwebengine_value.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/platform.hpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/../../src/rpc.hpp"
                                              ${CMAKE_CURRENT_SOURCE_DIR}/realm.cpp PARENT_SCOPE)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

set(REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_INCLUDE_DIRS ${REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_INCLUDE_DIRS}
  "${CMAKE_CURRENT_SOURCE_DIR}/../../src/object-store/src/impl"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../src/object-store/src/parser"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../src/object-store/src"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../src"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../src/qwebengine"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../src/object-store/build4/CMakeFiles/realm-core/src/realm-core/build.release/installed/include"
  PARENT_SCOPE)

set(REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_LIBS ${REACT_NATIVE_DESKTOP_EXTERNAL_MODULES_LIBS}
  "${CMAKE_CURRENT_SOURCE_DIR}/../../src/object-store/build4/CMakeFiles/realm-core/src/realm-core/build.release/installed/lib/librealm.a"
  libcrypto.a PARENT_SCOPE)

