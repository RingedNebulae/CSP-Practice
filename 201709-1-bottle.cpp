#include <iostream>

using namespace std;

int main()
{
	int money;
	int totalNum = 0;

	//处理输入
	cin >> money;

	//计算瓶数
	int count_5 = (money / 10) / 5;
	totalNum = totalNum + count_5 * 5 + count_5 * 2;//可以买几个5瓶，每个5瓶赠2瓶
	int remainMoney = money - count_5 * 10 * 5;
	int count_3 = (remainMoney / 10) / 3;
	totalNum = totalNum + count_3*3 + count_3;//可以买几个3瓶，每3瓶赠1瓶
	remainMoney = remainMoney - count_3 * 10 * 3;
	int count_1 = remainMoney / 10;
	totalNum = totalNum + count_1;

	//输出结果
	cout << totalNum << endl;

	return 0;
}