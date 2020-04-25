#include<iostream>
#include<vector>
#include<iomanip>
#include"game.h"

using namespace std;

#define ROW 4
#define COL 4

static vector<vector<int>> GAME;

//完成地图初始化并填充内容
vector<vector<int>> randinit()
{   /*
     * 返回一个vector容器, 保存的是地图的诗句
     */
    //返回result
    vector<vector<int>> result;
    vector<int> vec;
    int row1=0;
    int row2=0;
    int col1=0;
    int col2=0;

    srand(time(NULL));
    row1=rand()%ROW;
    col1=rand()%ROW;

    row2=rand()%ROW;
    col2=rand()%ROW;

    for(int i=0;i<ROW;++i)
    {
        for(int j=0;j<COL;++j)
        {

            if(row1==i&&col1==j)
            {
                int number=(rand()%2+1)*2;
                vec.push_back(number);
            }else if(row2==i&&col2==j)
            {
                int number=(rand()%2+1)*2;
                vec.push_back(number);
            }
            else{
                vec.push_back(0);
            }
        }
        result.push_back(vec);
        vec.clear();
    }
    return result;
}
void game_init()
{
    GAME=randinit();
}

void print()
{
    system("cls");
    cout << "Welcome to 2048" << endl;
    for(auto i :GAME)
    {
        cout<<"---------------------------------"<<endl;
        for(auto j:i)
        {
            cout<<"|   "<<j<<"\t";
        }
        cout<<"|"<<endl;
    }
    cout<<"---------------------------------"<<endl;

    cout<<"control tutorial:\nup,\ndown,\nleft \nright"<<endl;
}

void update()
{   //检测开关
    bool kg=true;

    //检测是否存在空位置
    for(auto i:GAME)
        for(auto j:i)
        {
            if(j==0)
            {
                kg=false;
                break;
            }
        }

    if(kg) return;

    int row1=rand() % ROW;
    int col1=rand() % COL;

    if(GAME[row1][col1]!=0) update();
    else{
        int number=(rand() %2+1)*2;
        GAME[row1][col1]=number;
    }
}

void move_direction(const char &ch)
{
    switch (ch) {
    case 'w':
        up();
        break;
    case 's':
        down();
        break;
    case 'a':
        left();
        break;
    case 'd':
        right();
        break;
    case 'q':
        exit(0);
    default:
        cout<<"Are you stupid?"<<endl;
        break;
    }
}
void up()
{
    for(int k=0;k<ROW-1;++k)
    {
        for(int i =0;i<ROW-1;++i)
        {
            for(int j=0;j<COL;++j)
            {
               /*
                * Replace first row if second row is not 0;
                */
                if(GAME[i][j]==0)
                {
                 GAME[i][j]=GAME[i+1][j];
                 GAME[i+1][j]=0;
                }else if(GAME[i][j]==GAME[i+1][j])
                {
                    GAME[i][j]*=2;
                    GAME[i+1][j]=0;
                    get_number+=GAME[i][j];
                }
            }
        }

    }
}
void down()
{
    for(int k=0;k<ROW-1;++k)
    {
        for(int i =ROW-1;i>0;--i)
        {
            for(int j=0;j<COL;++j)
            {
               /*
                * Replace first row if second row is not 0;
                */
                if(GAME[i][j]==0)
                {
                 GAME[i][j]=GAME[i-1][j];
                 GAME[i-1][j]=0;
                }else if(GAME[i][j]==GAME[i-1][j])
                {
                    GAME[i][j]*=2;
                    GAME[i-1][j]=0;
                    get_number+=GAME[i][j];
                }
            }
        }

    }
}
void left()
{
    for(int k=0;k<ROW-1;++k)
    {
        for(int i =0;i<ROW;++i)
        {
            for(int j=0;j<COL-1;++j)
            {
               /*
                * Replace first row if second row is not 0;
                */
                if(GAME[i][j]==0)
                {
                 GAME[i][j]=GAME[i][j+1];
                 GAME[i][j+1]=0;
                }else if(GAME[i][j]==GAME[i][j+1])
                {
                    GAME[i][j]*=2;
                    GAME[i][j+1]=0;
                    get_number+=GAME[i][j];
                }
            }
        }

    }

}
void right()
{
    for(int k=0;k<ROW-1;++k)
    {
        for(int i =0;i<ROW;++i)
        {
            for(int j=COL-1;j>0;--j)
            {
               /*
                * Replace first row if second row is not 0;
                */
                if(GAME[i][j]==0)
                {
                 GAME[i][j]=GAME[i][j-1];
                 GAME[i][j-1]=0;
                }else if(GAME[i][j]==GAME[i][j-1])
                {
                    GAME[i][j]*=2;
                    GAME[i][j-1]=0;
                    get_number+=GAME[i][j];
                }
            }
        }

    }
}
