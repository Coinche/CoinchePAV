#include "startdialog.h"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    ui->comboBoxIA1->setDisabled(true);
}

StartDialog::~StartDialog()
{
    delete ui;
}

QStringList StartDialog::readSettings()
{

    QStringList info = QStringList();
    if (ui->radioButtonDemo->isChecked())
    {
        info.append(ui->comboBoxIA1->currentText());
        info.append(ui->comboBoxIA2->currentText());
        info.append(ui->comboBoxIA3->currentText());
        info.append(ui->comboBoxIA4->currentText());
    }
    else
    {
        info.append("");
        info.append(ui->comboBoxIA2->currentText());
        info.append(ui->comboBoxIA3->currentText());
        info.append(ui->comboBoxIA4->currentText());
    }

    return info;
}


void StartDialog::on_radioButtonJH_clicked()
{
    ui->comboBoxIA1->setDisabled(true);
}

void StartDialog::on_radioButtonDemo_clicked()
{
    ui->comboBoxIA1->setDisabled(false);
}
