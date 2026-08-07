    #include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "calc.h"
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Calc calculator;
    engine.rootContext()->setContextProperty("backend", &calculator);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("calculator", "Main");


    return QGuiApplication::exec();
}
