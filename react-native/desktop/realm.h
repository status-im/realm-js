#ifndef REALM_H
#define REALM_H

#include "moduleinterface.h"

#include <QVariantMap>

class RealmPrivate;
class Realm : public QObject, public ModuleInterface {
    Q_OBJECT
    Q_INTERFACES(ModuleInterface)

    Q_DECLARE_PRIVATE(Realm)

public:
    Q_INVOKABLE Realm(QObject* parent = 0);
    ~Realm();

    void setBridge(Bridge* bridge) override;

    QString moduleName() override;
    QList<ModuleMethod*> methodsToExport() override;
    QVariantMap constantsToExport() override;

private:
    QScopedPointer<RealmPrivate> d_ptr;
};

#endif // REALM_H
