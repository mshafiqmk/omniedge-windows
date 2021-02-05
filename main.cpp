#include "traymenu.h"
#include <QApplication>
#include <QSettings>
#include "menucontroller.h"
#include "syslog.h"
#include "runguard.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    //single instance
    RunGuard guard( "Omniedge_Desktop_Client" );
    if ( !guard.tryToRun() )
        return 0;
    //Startup item
    QSettings  reg("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",QSettings::NativeFormat);
    QString strAppPath=QDir::toNativeSeparators(QCoreApplication::applicationFilePath());
    reg.setValue("OmniEdge",strAppPath);

#ifdef QT_NO_DEBUG
    syslog hlog;
    hlog.installReleaseMsgHandler();
#endif

    // Setting for QSetting
    QCoreApplication::setOrganizationName("Omniedge");
    QCoreApplication::setOrganizationDomain("omniedge.io");
    QCoreApplication::setApplicationName("Omniedge Desktop Client");

    TrayMenu menu;

    return a.exec();
}
