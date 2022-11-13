#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>

#include "bridge.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Bridge* connector = new Bridge();


    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("appBackend", connector);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
