#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "googleoauth.h"
#include "edge.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    GoogleOAuth hGoogleOAuth;
    QObject* root = engine.rootObjects().first();
    QObject *pObjGoogleOAuth = root->findChild<QObject*>("item_auth");
    if(pObjGoogleOAuth)
    {
        QObject::connect(pObjGoogleOAuth,SIGNAL(googleAuthClicked()),&hGoogleOAuth,SLOT(grant()));
    }

    // Test edge.exe
    Edge* edge = new Edge();
    edge->connectSuperNode(
                "52.80.139.238",
                "7787",
                "omniedge",
                "66YRd88kyYdhzk",
                "192.168.8.2"
                );

    return app.exec();
}
