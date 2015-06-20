#ifndef CHTTPPROCESS_H
#define CHTTPPROCESS_H
#include <QString>


class CHTTPProcess
{
public:
    CHTTPProcess(){}
    CHTTPProcess(QString url, QString body):sURL(url), sBody(body){}

private:
    QString sURL;
    QString sBody;
    QString sReply;

public:
    void init(QString url, QString body){this->sURL = url; this->sBody = body;}
    QString getReply(){return this->sReply;}
    int sendRequest(){return sendRequest(sURL,sBody,sReply);}
    static int sendRequest(QString, QString, QString &);
};

#endif // CHTTPPROCESS_H
