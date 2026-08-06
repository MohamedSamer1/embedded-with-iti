#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>
#include <QDebug>


class LanguageManager : public QObject
{
    Q_OBJECT

public:
    LanguageManager(QGuiApplication *app,
                    QTranslator *translator,
                    QQmlApplicationEngine *engine)
        : app(app), translator(translator), engine(engine)
    {
    }


    Q_INVOKABLE void changeLanguage(QString lang)
    {
        app->removeTranslator(translator);

        if (lang == "ar")
        {
            if (translator->load(":/i18n/qml_ar.qm"))
            {
                app->installTranslator(translator);
                qDebug() << "Arabic loaded";
            }
        }
        else if (lang == "en")
        {
            if (translator->load(":/i18n/qml_en.qm"))
            {
                app->installTranslator(translator);
                qDebug() << "English loaded";
            }
        }

        engine->retranslate();
    }


private:
    QGuiApplication *app;
    QTranslator *translator;
    QQmlApplicationEngine *engine;
};


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QTranslator translator;


    // Default language
    if (translator.load(":/i18n/qml_en.qm"))
    {
        app.installTranslator(&translator);
        qDebug() << "English loaded";
    }


    QQmlApplicationEngine engine;


    LanguageManager languageManager(
        &app,
        &translator,
        &engine
        );


    engine.rootContext()->setContextProperty(
        "languageManager",
        &languageManager
        );


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []()
        {
            QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
        );


    engine.loadFromModule("home", "Main");


    return app.exec();
}


#include "main.moc"