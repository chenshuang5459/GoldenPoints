#ifndef USER_H
#define USER_H


class user                    //用户类
{
private:
    int id;                  //学号
    int nums_inround;        //本轮输入数字
    int score;               //分数
public:
    user();                  //创建用户
    user(int,double,int);           //创建带有参数输入的用户
    user(const user &);
    ~user();                 //删除用户
    int getnum();            //获取本轮数字
    int getid();             //获取用户id
    int getscore();          //获取用户分数
    void setscore(int);        //更新用户得分
    void setnum(int);        //设置用户输入本轮数字
};

#endif // USER_H
