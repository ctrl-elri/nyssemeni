#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Minimi- ja maksimipelaajamäärä
    ui->players->setRange(1,4);


}
Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_startbutton_clicked()
{
    emit numberOfPlayers(players_);
    accept();
}

void Dialog::on_exitbutton_clicked()
{
    emit exit();
    reject();
}


void Dialog::on_players_valueChanged(int arg1)
{
    players_ = arg1;
}
