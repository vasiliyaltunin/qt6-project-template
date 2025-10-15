#ifndef DEBUGREDIRECTOR_H
#define DEBUGREDIRECTOR_H

#include <QQmlApplicationEngine>
#include <QDebug>

#include <iostream>



class DebugRedirector
{
public:
    DebugRedirector();
    ~DebugRedirector();
    
    static void stdErrorHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void __errorHandler(FILE *output, QtMsgType type, const QMessageLogContext &context, const QString &msg);
};

#endif