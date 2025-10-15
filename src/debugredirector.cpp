#include "debugredirector.h"

DebugRedirector::DebugRedirector()
{
}

DebugRedirector::~DebugRedirector()
{
}

void DebugRedirector::stdErrorHandler(QtMsgType type, const QMessageLogContext & context, const QString & msg)
{
    DebugRedirector::__errorHandler(stderr, type, context, msg);
}

void DebugRedirector::__errorHandler(FILE * output, QtMsgType type, const QMessageLogContext & context, const QString & msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    switch (type)
    {
    case QtDebugMsg:
        fprintf(output, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtInfoMsg:
        fprintf(output, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtWarningMsg:
        fprintf(output, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtCriticalMsg:
        fprintf(output, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        break;
    case QtFatalMsg:
        fprintf(output, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
        fflush(stdout);
        fflush(stderr);
        abort();
    }

    fflush(stdout);
    fflush(stderr);

}