#include <iostream>
#include <vector>

using namespace std;

struct ball {
	int position;
	int direction;//1 right.-1 left
};

int main()
{
	//记录n个球当前位置
	vector<ball> balls;

	//球个数num，轨道长度length，总时间time;    
	int num, length, time;

	//处理输入
	//读取小球数量，轨道长度，总时间
	cin >> num >> length >> time;

	//记录跑道当前状态
	vector<int> trackStatus(length+1, 0);

	//读取小球初始位置
	int tmpPosi, i,j;
	ball currball;
	for (i = 0; i<num; i++)
	{
		cin >> tmpPosi;
		currball.position = tmpPosi;
		currball.direction = 1;
		balls.push_back(currball);

		//记录轨道初始状态，当前位置有球记为1，无球保持0
		trackStatus[tmpPosi] = 1;
	}



	//时刻变化
	for (i = 0; i< time; i++)
	{
		//依次更新小球的位置
		for (j = 0; j < num; j++)
		{
			currball = balls[j];
			trackStatus[currball.position] = trackStatus[currball.position] - 1;//离开当前位置

			//小球的位置不能超出0-length
			if (currball.position > 0 && currball.position < length)
			{
				currball.position = currball.position + 1 * currball.direction;
				
			}

			//当达到边界时改变方向
			else if (currball.position == 0 || currball.position == length)
			{
				currball.direction = -1 * currball.direction;//改变方向
				currball.position = currball.position + 1 * currball.direction;
			}
			balls[j] = currball;
			trackStatus[currball.position] = trackStatus[currball.position] + 1;//到达新位置
		}

		//检测是否发生碰撞
		for (int k = 0; k <= length; k++)
		{
			if (trackStatus[k] == 2)//如果当前位置有两个小球，找到这两个小球，并改变方向
			{
				for ( j = 0; j < num; j++)
				{
					if(balls[j].position == k)
						balls[j].direction = -1 * balls[j].direction;//改变方向
				}
			}
		}


	}

	//输出结果
	for (i = 0; i < num; i++)
	{
		cout << balls[i].position << " ";
	}
	cout << endl;

	return 0;
}