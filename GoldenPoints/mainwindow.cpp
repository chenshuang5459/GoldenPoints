#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    round=Rounds();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_submit_clicked()//获取本次对局结果、输出
{
    if(round.get_size()<10){
        ui->textEdit->setPlainText("Player number is less than 10.");
        return;
    }
    ui->textEdit->setPlainText("");
    round.calculate();
    round.score();
    QString line=QString("The winner id:");
    line+=QString::number(round.get_winner_id());
    ui->textEdit->append(line);
    line="The loser id:"+QString::number(round.get_loser_id());
    ui->textEdit->append(line);
    line="The G_point is:";
    line+=QString::number(round.get_Gpoint());
    ui->textEdit->append(line);
    ui->textEdit->append("player scores are shown below:");
    for(int i=0;i<round.get_size();i++){
        line="id:"+QString::number(round.get_player(i).getid());
        ui->textEdit->append(line);
        line=" Score:"+QString::number(round.get_player(i).getscore());
        ui->textEdit->append(line);
        line=" number:"+QString::number(round.get_player(i).getnum());
        ui->textEdit->append(line);
    }
}

void MainWindow::on_pushButton_nextplayer_clicked()//获取下一个用户的输入,存储进入对局信息
{
    int player_id=ui->lineEdit_get_player_id->text().toInt();
    double player_input=ui->lineEdit_get_player_input->text().toDouble();
    int flag=0;
    for(int i=0;i<round.get_size();i++){
        if(round.get_player(i).getid()==player_id)
            flag=1;
    }
    if(flag==0){
        round.append_player(user(player_id,player_input,0));
        ui->textEdit->setPlainText("Success.");
    }else if(player_input<=0||player_input>=100){
        ui->textEdit->setPlainText("Please enter number between 0 and 100.");
    }else if(flag==1){
        ui->textEdit->setPlainText("Already have a same id.");
    }
    ui->lineEdit_get_player_id->setText("");
    ui->lineEdit_get_player_input->setText("");
}

void MainWindow::on_pushButton_nextround_clicked()//将本次次对局的信息存储到数据库，并创建下一局游戏对象
//不允许有用户提前退出
{
    round.roundnum+=1;
    ui->rounds->setText("Round "+QString::number(round.roundnum));
    ui->textEdit->setPlainText("");
}
