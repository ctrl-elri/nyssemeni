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
    void GameTime(QTime time);
    void NumberOfPlayers(int players);


private slots:

    void on_startbutton_clicked();

    void on_exitbutton_clicked();

    void on_timeEdit_userTimeChanged(const QTime &time);

    void on_players_valueChanged(int arg1);

private:
    Ui::Dialog *ui;
    QTime time_ = QTime(0,0);
    int players_ = 1;


};

#endif // DIALOG_H
