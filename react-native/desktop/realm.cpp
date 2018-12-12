#include "realm.h"
#include "bridge.h"
#include "eventdispatcher.h"

#include "qwebengine_init.h"

#include <QCoreApplication>
#include <QDebug>
#include <QUrl>

#include <QWebChannel>
#include <QFile>

namespace {
struct RegisterQMLMetaType {
  RegisterQMLMetaType() { qRegisterMetaType<Realm *>(); }
} registerMetaType;
} // namespace

class RealmPrivate {
public:
  Bridge *bridge = nullptr;
};

Realm::Realm(QObject *parent) : QObject(parent), d_ptr(new RealmPrivate) {
}

Realm::~Realm() {
}

void Realm::setBridge(Bridge *bridge) {
  Q_D(Realm);

  if (!d->bridge) {
    realm::qwebengine::qwebengine_init();
  }
  d->bridge = bridge;

  /*QWebChannel* channel = new QWebChannel(this);
  CustomWebPage::instance()->setWebChannel(channel);
  channel->registerObject(QStringLiteral("RealmTest"), this);

  QFile apiFile(":/qtwebchannel/qwebchannel.js");
  if(!apiFile.open(QIODevice::ReadOnly))
      qDebug()<<"Couldn't load Qt's QWebChannel API!";
  QString apiScript = QString::fromLatin1(apiFile.readAll());
  apiScript.append(
           "\n"
           "console.log('!++++ Test message');\n"
           "new QWebChannel(qt.webChannelTransport, function(channel) {"
           "   console.log('!!! new QWebChannel is created');"
           "   var JSobject = channel.objects.RealmTest;"
           "   console.log('Custom JSObject= ' + JSobject);"
           "});"
  );
  CustomWebPage::instance()->runJavaScript(apiScript, 1);*/


}

void Realm::registerJSObjects(Bridge *bridge)
{
    RealmClass* realmInstance = new RealmClass(this);
    bridge->registerJSObject(QStringLiteral("RealmTest"), realmInstance);
}

QString Realm::moduleName() { return "Realm"; }

QList<ModuleMethod *> Realm::methodsToExport() {
  return QList<ModuleMethod *>{};
}

QVariantMap Realm::constantsToExport() { return QVariantMap(); }

