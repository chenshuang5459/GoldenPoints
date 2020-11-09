#include "rounds.h"
#include "user.h" 
Rounds::Rounds()                     //创建游戏轮盘对象
{
    roundnum=1;
}
void Rounds::append_player(user user0)   //在队列中增加用户对象
{
    players.push_back(user0);
}

int Rounds::get_size(){
    return players.size();
}

user Rounds::get_player(int n){
    return players[n];
}

void Rounds::calculate()                  //根据用户输入计算黄金点和赢家输家
{
    int sum=0;
    for(int i=0;i<players.size();i++)                          //计算游戏用户输入数字总和及游戏人数
	{
        sum+=players[i].getnum();
	}
    double over=sum/players.size();                   //计算平均值
    float G=over*0.618;                       //计算G值
    G_point=G;
    int winsub=0xffff;                              //绝对值最小
    int lossum=0;                              //绝对值最大
    for(int i=0;i<players.size();i++)                                     //循环比较绝对差找出胜者和输者
	{
        if( abs(players[i].getnum()-G) < winsub )
		{
            winsub=abs(players[i].getnum()-G);
            winner_id=players[i].getid();
		}
        if( abs(players[i].getnum()-G) > lossum )
		{
            lossum=abs(players[i].getnum()-G);
            loser_id=players[i].getid();
		}
	}
}
void Rounds::score()                           //更新用户得分
{
    for(int i=0;i<players.size();i++)
    {
        if(players[i].getid() == winner_id)
        {
            players[i].setscore(players[i].getscore()+players.size());
        }
        if(players[i].getid() == loser_id)
        {
            players[i].setscore(players[i].getscore()-2);
        }
    }
}

float Rounds::get_Gpoint()                     //获取G值
{
    return G_point;
}
int Rounds::get_winner_id()                  //获取胜者id
{
    return winner_id;
}

int Rounds::get_loser_id()                   //获取输者id
{
    return loser_id;
}
