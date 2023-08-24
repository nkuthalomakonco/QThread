#include "worker.h"

Worker::Worker()
{
}
void Worker::doWork(const QString &parameter) {
    QString result;
    /* ... here is the expensive or blocking operation ... */
    QThread::currentThread()->setObjectName("Worker Thread");
    for(int i = 1; i <= 5; i++)
    {
        result = QString("Working %1.")
                     .arg(QString::number(i));

        qInfo() << "Working" << QString::number(i) << QThread::currentThread();
        QThread::currentThread()->msleep(500);

        emit resultReady(result);
    }
}
