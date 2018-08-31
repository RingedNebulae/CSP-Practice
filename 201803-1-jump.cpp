#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int tmpin;
	vector<int> inputNum;
	int score = 0;
	//处理输入
	do
	{
		cin >> tmpin;
		if (tmpin == 1 || tmpin == 2)
			inputNum.push_back(tmpin);
	} while (tmpin != 0);

	int count = 0;
	int continueCenter = 0;

	while (count<inputNum.size())
	{
		//判断是否跳到中心
		if (inputNum[count] == 1)//没跳到中心得1分
		{
			score = score + 1;
			continueCenter = 0;
		}
		else if (inputNum[count] == 2)//跳到中心则分情况讨论
		{
			continueCenter++;

			if (count == 0)//如果是本局第一次游戏
				score = score + 2;
			else if (inputNum[count - 1] == 1)//上次得分是1分
				score = score + 2;
			else//连续跳中心
			{
				score = score + 2 * continueCenter;
			}
		}
		count++;
	}
	cout << score << endl;
	return 0;
}