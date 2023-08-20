#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

public slots:
    void doWork(const QString &parameter);

signals:
    void resultReady(const QString &result);

};

#endif // WORKER_H
