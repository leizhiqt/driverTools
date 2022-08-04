#include <QApplication>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QMessageBox>
#include <QtQuick>
#include <QQmlApplicationEngine>
#include "src/buscomm.h"
#include "bclog.h"
#include "unistd.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    log_initialize("logcomm.txt", 1);

    LOG_INFO("abcd");
/*
    QSharedMemory shared("driverTools");
    if (shared.attach())
    {
        QMessageBox::information(0,"error","已运行一个实例！");
//        qDebug()<<"已运行一个实例！\n";
        return 0;
    }
    shared.create(1);
*/

//    QSystemSemaphore semaphore("ProgramKey",1, QSystemSemaphore::Open);
//    semaphore.acquire();
//    //在临界区操作共享内存SharedMemory
//    QSharedMemory memory("DriverTools");//全局对象名
//    if(!memory.create(1)) //如果全局对象存在则提示退出
//    {
//       QMessageBox::information(0, "提示", "DriverTools 已经运行!");
//       semaphore.release();
//       exit(0);
//    }
//    semaphore.release();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QQmlApplicationEngine engine;

    busComm *bus= busComm::getInstance();

    rs422Comm *rs422=rs422Comm::getInstance();
    rs232Comm *rs232=rs232Comm::getInstance();
    arincComm429 *arinc429=arincComm429::getInstance();
    dioComm *diocomm=dioComm::getInstance();

    //添加到qml上下文
    QQmlContext* rootContex = engine.rootContext();

    rootContex->setContextProperty("bus", bus);
    rootContex->setContextProperty("rs232", rs232);
    rootContex->setContextProperty("rs422", rs422);
    rootContex->setContextProperty("arinc429", arinc429);
    rootContex->setContextProperty("diocomm", diocomm);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    LOG_INFO("bus->open1");
    bus->open();
    LOG_INFO("bus->open2");

    rs232->qmlObject=engine.rootObjects().first()->findChildren<QObject*>("rs232Page").first();
    rs422->qmlObject=engine.rootObjects().first()->findChildren<QObject*>("rs422Page").first();

    arinc429->qmlObject=engine.rootObjects().first()->findChildren<QObject*>("arinc429Page").first();
    diocomm->qmlObject=engine.rootObjects().first()->findChildren<QObject*>("dioPage").first();
    bus->qmlobj=engine.rootObjects().first();

//    while(1){
//        sleep(1000);
//    }
//    log_release();

    return app.exec();
}
