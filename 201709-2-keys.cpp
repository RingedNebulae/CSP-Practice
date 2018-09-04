#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct teacher {
	int keyNum;
	int startTime;
	int endTime;
};

int main()
{
	//处理输入
	int N, K;//N个挂钩，K个老师
	vector<teacher> teacherList;
	vector<int> keysPosition;
	cin >> N >> K;

	//初始化钥匙挂钩状态
	for (int i = 0; i < N; i++)
	{
		keysPosition.push_back(i+1);
	}

	//初始化教师使用钥匙的状态
	teacher tmpTeacher;
	int durationTime;
	for (int i = 0; i < K; i++)
	{
		cin >> tmpTeacher.keyNum >> tmpTeacher.startTime >> durationTime;
		tmpTeacher.endTime = tmpTeacher.startTime + durationTime;
		teacherList.push_back(tmpTeacher);
	}
	
	//找到最终还钥匙的时刻，就是算法输出的时刻
	int endtime=0;
	for (int i = 0; i < teacherList.size(); i++)
	{
		if (teacherList.at(i).endTime > endtime)
			endtime = teacherList.at(i).endTime;
	}

	//按时刻处理借还钥匙
	vector<int> keyReturnQueue;//还钥匙的队列

	for (int currTime = 1; currTime <= endtime; currTime++)
	{
		//先处理当前时刻还钥匙请求
		//找到所有要还的钥匙
		for (int j = 0; j < teacherList.size(); j++)
		{
			if (teacherList.at(j).endTime == currTime)
			{
				keyReturnQueue.push_back(teacherList.at(j).keyNum);
			}
		}
		//将这些钥匙按钥匙编号从小到大的顺序依次归还
		//每次规划钥匙放到最左边的空挂钩
		sort(keyReturnQueue.begin(), keyReturnQueue.end());
		for (int tmp = 0; tmp < keyReturnQueue.size(); tmp++)
		{
			for (int tmp2 = 0; tmp2 < N; tmp2++)
			{
				//从左边开始第一个等于0的位置放钥匙
				if (keysPosition.at(tmp2) == 0)
				{
					keysPosition.at(tmp2) = keyReturnQueue.at(tmp);
					break;
				}
					
			}
		}
		//处理完还钥匙的请求之后，清空
		keyReturnQueue.clear();

		//再处理借钥匙的请求
		//钥匙可以直接借走，没有顺序要求
		for (int j = 0; j < teacherList.size(); j++)
		{
			//判断当前老师是否要借钥匙
			if (teacherList.at(j).startTime == currTime)
			{
				for (int tmp = 0; tmp < keysPosition.size(); tmp++)
				{
					//在钥匙列表中找到钥匙
					if (keysPosition.at(tmp) == teacherList.at(j).keyNum)
					{
						keysPosition.at(tmp) = 0;//借走钥匙，当前位置标为0
						break;
					}
				}
			}
		}

	}
	//输出结果
	for (int i = 0; i < keysPosition.size(); i++)
	{
		cout << keysPosition.at(i) << " ";
	}

	cout << endl;
	return 0;
}