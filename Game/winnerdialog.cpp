#include "winnerdialog.h"
#include "ui_winnerdialog.h"

WinnerDialog::WinnerDialog(QString winnerName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerDialog)
{
    ui->setupUi(this);
    ui->winnerLabel->setText("Winner is " + winnerName);

}

WinnerDialog::~WinnerDialog()
{
    delete ui;
}

void WinnerDialog::on_newgameButton_clicked()
{
    accept();
    emit newGame();
}

void WinnerDialog::on_exitButton_clicked()
{
    emit exitFromWinnerDialog();
    reject();
}
