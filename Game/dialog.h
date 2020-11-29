#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCommonStyle>
#include <QTime>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void numberOfPlayers(int players);
    void exit();


private slots:

    void on_startbutton_clicked();

    void on_exitbutton_clicked();

    void on_players_valueChanged(int arg1);

private:
    Ui::Dialog *ui;
    int players_ = 1;


};

#endif // DIALOG_H
