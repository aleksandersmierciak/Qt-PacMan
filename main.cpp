#include <QtGui/QApplication>
#include <QtDeclarative>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeEngine>

#include "qmlapplicationviewer.h"
#include "gamedata.h"
#include "tile.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    GameData * gameData = new GameData();

    QmlApplicationViewer viewer;
    // viewer.rootContext()->setContextProperty("gameData", new GameData());
    // viewer.engine()->rootContext()->setContextObject(gameData);
    viewer.engine()->rootContext()->setContextProperty("gameData", gameData);

    // Register Tile to be available in QML
    qmlRegisterType<Tile>("gameCore", 1, 0, "Tile");

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/MainView.qml"));
    viewer.showExpanded();

    return app->exec();
}
