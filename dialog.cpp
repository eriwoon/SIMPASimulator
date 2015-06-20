#include "dialog.h"
#include "ui_dialog.h"
#include "chttpprocess.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#define COPYRIGHTINFO "Copyright:\nXiao Zhen\nSIMPA Simulator v0.1\n2015.06.20"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setWindowTitle("SIMPA Simulator");
    this->setWindowFlags(Qt::Dialog
                         | Qt::WindowMaximizeButtonHint
                         | Qt::WindowMinimizeButtonHint
                         | Qt::WindowCloseButtonHint);


    //TextURL控件,在上方显示
    qTextURL = new QTextEdit;
    qTextURL->setLineWrapMode(QTextEdit::NoWrap);
    qTextURL->setMaximumHeight(33);
    qTextURL->setText("http://www.xiaozhen.me/routing-sfr.huawei.com");

    //TextBody控件,在上方显示
    qTextBody = new QTextEdit;
    qTextBody->setLineWrapMode(QTextEdit::WidgetWidth);
    qTextBody->setMaximumHeight(100);
    qTextBody->setText("Hello World!\n");

    //Button控件,在中间
    qButtonSend = new QPushButton("&Send");
    connect(qButtonSend,SIGNAL(clicked()),this,SLOT(onClickSend()));

    //Label控件,在下方显示
    qLabelDesc = new QLabel;
    qLabelDesc->setWordWrap(true);
    qLabelDesc->setTextInteractionFlags(Qt::TextSelectableByMouse);
    qLabelDesc->setText(COPYRIGHTINFO);

    this->setDialogLayout();

}
void Dialog::setDialogLayout()
{
    QVBoxLayout *qVLayout = new QVBoxLayout();
    qVLayout->addWidget(this->qTextURL);
    qVLayout->addWidget(this->qTextBody);
    qVLayout->addWidget(this->qButtonSend);
    qVLayout->addWidget(this->qLabelDesc);
    this->setLayout(qVLayout);
}

void Dialog::onClickSend()
{
    QString reply;
    QString sURL = qTextURL->toPlainText();
    QString sBody = qTextBody->toPlainText();
    if(CHTTPProcess::sendRequest(sURL,sBody,reply) == 0)
    {
        qDebug() << reply;
    }
    else
    {
        qDebug() << "Failed";
        qDebug() << reply;
    }
    this->qLabelDesc->setText(reply);
}

Dialog::~Dialog()
{
    delete ui;
}
