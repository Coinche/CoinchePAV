#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
    class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();
    QStringList readSettings();

private slots:
    void on_radioButtonJH_clicked();

    void on_radioButtonDemo_clicked();

private:
    Ui::StartDialog *ui;
    QString info;
};

#endif // STARTDIALOG_H

