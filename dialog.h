#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    void setDialogLayout();

//Widgets
private:
    QTextEdit   *qTextURL, *qTextBody;
    QLabel      *qLabelDesc;
    QPushButton *qButtonSend;

//消息响应处理函数
private slots:
    void onClickSend();
};

#endif // DIALOG_H
