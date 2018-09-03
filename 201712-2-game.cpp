#include <iostream>
#include <vector>

using namespace std;

//全局变量
int n, k;
struct player {
	int num;
	bool mIsOut;
};

bool isOut(int tmpNum)
{
	if (tmpNum%k == 0)//k的倍数
		return true;
	else if (tmpNum % 10 == k)//个位是k
		return true;
	else
		return false;
}

int main()
{
	//处理输入
	cin >> n >> k;

	vector<player> gamePlayer;
	player tmplayer;
	for (int i = 0; i < n; i++)
	{
		tmplayer.num = i + 1;
		tmplayer.mIsOut = false;
		gamePlayer.push_back(tmplayer);
	}

	//游戏
	int currNum = 1;
	int remains = gamePlayer.size();
	while (remains != 1)
	{
		for (int i = 0; i < gamePlayer.size(); i++)
		{
			if (gamePlayer.at(i).mIsOut == true)//已经淘汰的不参与计数
				continue;
			if (isOut(currNum))
			{
				gamePlayer.at(i).mIsOut = true;
				remains--;
			}
			currNum++;

		}

	}


	//输出
	for (int i = 0; i < gamePlayer.size(); i++)
	{
		if (gamePlayer.at(i).mIsOut == false)
			cout << gamePlayer.at(i).num << endl;
	}

	return 0;
}