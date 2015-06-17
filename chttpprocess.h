#ifndef CHTTPPROCESS_H
#define CHTTPPROCESS_H
#include <QString>

enum HTTPMethod {
    GET,
    POST,
    HEAD
};

class CHTTPProcess
{
public:
    CHTTPProcess();

public:
    QString sHost;
    int
    HTTPMethod eHTTPMethod;

};

#endif // CHTTPPROCESS_H
