#include "realm.h"
#include "bridge.h"
#include "eventdispatcher.h"

#include <QCoreApplication>
#include <QDebug>
#include <QUrl>

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
  d->bridge = bridge;

  CustomWebPage::instance()->runJavaScript("console.log(\"Setting Realm\"); var Realm = {}; localStorage.clear();", 1);
}

QString Realm::moduleName() { return "Realm"; }

QList<ModuleMethod *> Realm::methodsToExport() {
  return QList<ModuleMethod *>{};
}

QVariantMap Realm::constantsToExport() { return QVariantMap(); }

