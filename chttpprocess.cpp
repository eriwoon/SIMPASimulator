#include "chttpprocess.h"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QDebug>
#include <QUrl>

int CHTTPProcess::sendRequest(QString sURL, QString sBody, QString &sReply)
{
    // create custom temporary event loop on stack
    QEventLoop eventLoop;

    // "quit()" the event-loop, when the network request "finished()"
    QNetworkAccessManager mgr;
    QObject::connect(&mgr,       SIGNAL(finished(QNetworkReply*)),
                     &eventLoop, SLOT(quit()));

    // the HTTP request
    QNetworkRequest req(sURL);
    req.setHeader(QNetworkRequest::ContentTypeHeader, "text/plain");
    req.setHeader(QNetworkRequest::UserAgentHeader, "SIMPA/2.0/1.0");

    /*auto headerlist = req.rawHeaderList();
    for(auto iter = headerlist.begin(); iter != headerlist.end(); iter ++)
    {
        qDebug() << *iter << req.rawHeader(*iter);
    }*/

    QNetworkReply *reply = mgr.post(req,sBody.toUtf8());
    eventLoop.exec(); // blocks stack until "finished()" has been called

    if (reply->error() == QNetworkReply::NoError) {
        //success
        auto repHeaderList = reply->rawHeaderList();
        for(auto iter = repHeaderList.begin(); iter != repHeaderList.end(); iter ++)
        {
            sReply += *iter + ':' + reply->rawHeader(*iter)+ '\n';
        }
        sReply += '\n';
        sReply += reply ->readAll();

        delete reply;
        return 0;
    }
    else {
        //failure
        auto repHeaderList = reply->rawHeaderList();
        for(auto iter = repHeaderList.begin(); iter != repHeaderList.end(); iter ++)
        {
            sReply += *iter + ':' + reply->rawHeader(*iter)+ '\n';
        }
        sReply += '\n';
        sReply += reply->errorString();

        delete reply;
        return 1;
    }

    return 0;
}
