#ifndef ROUNDS_H
#define ROUNDS_H
#include"user.h"
#include<vector>

class Rounds                      //游戏轮盘类
{
private:
    std::vector<user> players;      //用户队列
    float G_point;                  //G值
    int winner_id;                  //胜者id
    int loser_id;                   //输者id

public:
    Rounds();                       //创建游戏轮盘对象
    void append_player(user);       //在队列中增加用户对象
    int get_size();                 //获取用户人数
    user get_player(int);               //获取用户信息
    void calculate();               //根据用户输入计算黄金点和赢家输家
    void score();                   //更新用户得分
    float get_Gpoint();             //获取G值
    int get_winner_id();            //获取胜者id
    int get_loser_id();             //获取输者id
    int roundnum;                   //轮数
};

#endif // ROUNDS_H
