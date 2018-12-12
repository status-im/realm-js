#ifndef REALM_H
#define REALM_H

#include "moduleinterface.h"

#include <QVariantMap>

#include <QDebug>
#include <QApplication>

class RealmClass : public QObject {
    Q_OBJECT

    Q_PROPERTY(bool empty READ empty WRITE setEmpty NOTIFY emptyChanged)
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
    //Q_PROPERTY(int schemaVersion READ schemaVersion WRITE setSchemaVersion NOTIFY schemaVersionChanged)
    Q_PROPERTY(bool schema READ schema WRITE setSchema NOTIFY schemaChanged)
    Q_PROPERTY(bool inMemory READ inMemory WRITE setInMemory NOTIFY inMemoryChanged)
    Q_PROPERTY(bool readOnly READ readOnly WRITE setReadOnly NOTIFY readOnlyChanged)
    Q_PROPERTY(bool isInTransaction READ isInTransaction WRITE setIsInTransaction NOTIFY isInTransactionChanged)
    Q_PROPERTY(bool isClosed READ isClosed WRITE setIsClosed NOTIFY isClosedChanged)

    Q_PROPERTY(QString defaultPath READ defaultPath WRITE setDefaultPath NOTIFY defaultPathChanged)
public:

    explicit RealmClass(QObject* parent) : QObject(parent) {}

    Q_INVOKABLE static int schemaVersion(QString defaultPath, QString encyptionKey) {qDebug() << "+++ RealmClass method call"; return 0;}

    bool empty() const { qDebug() << "+++ RealmClass method call"; return true;}
    void setEmpty(bool value) {qDebug() << "+++ RealmClass method call";}

    QString path() const {qDebug() << "+++ RealmClass method call"; return "";}
    void setPath(QString value) {qDebug() << "+++ RealmClass method call";}

    int schemaVersion() {qDebug() << "+++ RealmClass method call"; return 0;}
    void setSchemaVersion(int value) {qDebug() << "+++ RealmClass method call";}

    bool schema() const {qDebug() << "+++ RealmClass method call"; return true;}
    void setSchema(bool value) {qDebug() << "+++ RealmClass method call";}

    bool inMemory() const {qDebug() << "+++ RealmClass method call"; return true;}
    void setInMemory(bool value) {qDebug() << "+++ RealmClass method call";}

    bool readOnly() const {qDebug() << "+++ RealmClass method call"; return true;}
    void setReadOnly(bool value) {qDebug() << "+++ RealmClass method call";}

    bool isInTransaction() const {qDebug() << "+++ RealmClass method call"; return true;}
    void setIsInTransaction(bool value) {qDebug() << "+++ RealmClass method call";}

    bool isClosed() const {qDebug() << "+++ RealmClass method call"; return true;}
    void setIsClosed(bool value) {qDebug() << "+++ RealmClass method call";}

    QString defaultPath() const {qDebug() << "+++ RealmClass defaultPath method call"; return qApp->applicationDirPath();}
    void setDefaultPath(QString value) {qDebug() << "+++ RealmClass setDefaultPath method call";}

Q_SIGNALS:

    void emptyChanged();
    void pathChanged();
    void schemaVersionChanged();
    void schemaChanged();
    void inMemoryChanged();
    void readOnlyChanged();
    void isInTransactionChanged();
    void isClosedChanged();
    void defaultPathChanged();

};

class RealmPrivate;
class Realm : public QObject, public ModuleInterface {
    Q_OBJECT
    Q_INTERFACES(ModuleInterface)

    Q_DECLARE_PRIVATE(Realm)

public:
    Q_INVOKABLE Realm(QObject* parent = 0);
    ~Realm();

    void setBridge(Bridge* bridge) override;
    void registerJSObjects(Bridge* bridge) override;

    QString moduleName() override;
    QList<ModuleMethod*> methodsToExport() override;
    QVariantMap constantsToExport() override;

private:
    QScopedPointer<RealmPrivate> d_ptr;
};

#endif // REALM_H
