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
    void playerNames(QString player1, QString player2, QString player3, QString player4);
    void exit();


private slots:

    void on_startbutton_clicked();

    void on_exitbutton_clicked();

    void on_players_valueChanged(int arg1);

    void on_player1Name_textChanged(const QString &arg1);

    void on_player2Name_textChanged(const QString &arg1);

    void on_player3Name_textChanged(const QString &arg1);

    void on_player4Name_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
    int players_ = 1;
    QString player1_name_ = "Player1";
    QString player2_name_ = "Player2";
    QString player3_name_ = "Player3";
    QString player4_name_ = "Player4";


};

#endif // DIALOG_H
