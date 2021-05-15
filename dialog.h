#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
    int oper;

signals:
    void oper_signal(int);

private slots:
    void oper_slot(int);
    void plus_slot();
    void minus_slot();
    void mul_slot();
    void div_slot();
    void calc_slot();
};
#endif // DIALOG_H
