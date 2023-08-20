#include "controller.h"
#include "worker.h"

Controller::Controller() {
    Worker *worker = new Worker;
    //worker->setObjectName("Worker Thread");
    worker->moveToThread(&workerThread);
    connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(this, &Controller::operate, worker, &Worker::doWork);
    connect(worker, &Worker::resultReady, this, &Controller::handleResults);
    workerThread.start();
    emit operate(QString());
}

Controller::~Controller() {
    workerThread.quit();
    workerThread.wait();
}

void Controller::handleResults(const QString &s)
{
    QThread::currentThread()->setObjectName("Controller Thread");
    qInfo() << s << QThread::currentThread();
}
