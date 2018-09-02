#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//处理输入
	int totalNum,tmpIn;
	cin >> totalNum;

	vector<int> inputNumber;
	vector<int> outputNumber;
	for (int i = 0; i < totalNum; i++)
	{
		cin >> tmpIn;
		inputNumber.push_back(tmpIn);
	}

	//排序
	sort(inputNumber.begin(), inputNumber.end());

	//相邻相减
	int tmpNum;
	for (int i = 0; i < totalNum-1; i++)
	{
		tmpNum = inputNumber[i + 1] - inputNumber[i];
		outputNumber.push_back(tmpNum);
	}

	//找最小
	sort(outputNumber.begin(), outputNumber.end());

	//输出
	cout << outputNumber[0] << endl;

	return 0;
}