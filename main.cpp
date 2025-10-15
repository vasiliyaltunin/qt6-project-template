#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "src/debugredirector.h"

#include "src/helloworld.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qInstallMessageHandler(DebugRedirector::stdErrorHandler);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.addImportPath(":/qt/qml/altuninvv");

    engine.load(QUrl("qrc:/qt/qml/altuninvv/qmlmain/qml/Main.qml"));

    HelloWorld *h = new HelloWorld();

    h->hello();

    return app.exec();
}
