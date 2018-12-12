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

#include "qwebengine_init.hpp"
#include "js_realm.hpp"

#include "bridge.h"

#include <QFile>


namespace realm {
namespace qwebengine {

void qwebengine_init() {

    QFile qwebengineInjectJSFile("/home/max/work/realm-js/realm-js/qwebengine_inject.js");
    if(!qwebengineInjectJSFile.open(QIODevice::ReadOnly))
        qDebug()<<"Couldn't load qwebengine inject JS file";
    QString webengineInjectionScript = QString::fromLatin1(qwebengineInjectJSFile.readAll());
    CustomWebPage::instance()->runJavaScript(webengineInjectionScript, 0);

  //CustomWebPage::instance()->runJavaScript("console.log(\"Setting Realm\"); var Realm = {}; localStorage.clear();", 1);

  /*CustomWebPage::instance()->runJavaScript("new QWebChannel(qt.webChannelTransport, function (channel) {\
                                           console.log('!!! new QWebChannel is created'); \
                                           var JSobject = channel.objects.RealmTest; \
                                           console.log('Custom JSObject= ' + JSobject); \
                                       });", 1);*/
}

} // qwebengine
} // realm
