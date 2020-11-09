#include "user.h"

user::user()                           //创建用户
{
    id=0;
    score=0;
    nums_inround=0;
}

user::user(int id0,double num,int score0)         //创建带有参数输入的用户
{
    id=id0;
    score=score0;
    nums_inround=num;
}

user::user(const user & user0){
    id=user0.id;
    score=user0.score;
    nums_inround=user0.nums_inround;
}

user::~user(){;}

void user::setnum(int num0)             //设置用户输入本轮数字
{
    nums_inround=num0;
}

int user::getid()                       //获取用户id
{
    return id;
}

int user::getnum()                      //获取本轮数字
{
    return nums_inround;
}

int user::getscore()                    //获取用户分数
{
    return score;
}

void user::setscore(int n){
    score+=n;
}
