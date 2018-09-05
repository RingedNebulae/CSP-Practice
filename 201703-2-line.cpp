#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct order
{
	int student;
	int command;
};

int main()
{
	//处理输入
	int n,m;
	cin >> n;//学生的数量
	cin >> m;//调整的次数

	vector<order> orderlist;//保存指令
	order tmpOrder;
	for (int i = 0; i < m; i++)
	{
		cin >> tmpOrder.student >> tmpOrder.command;
		orderlist.push_back(tmpOrder);
	}

	//初始化队列
	vector<int> studentlist;
	for (int i = 0; i < n; i++)
	{
		studentlist.push_back(i+1);
	}

	//调整队列
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (studentlist[j] == orderlist[i].student)
			{
				if (orderlist[i].command > 0)
				{
					studentlist.insert(studentlist.begin() + 1 + j + orderlist[i].command, studentlist[j]);//插入队列
					studentlist.erase(studentlist.begin() + j); //删除原数据
					break;
				}
				else if (orderlist[i].command<0)
				{
					studentlist.insert(studentlist.begin() + j + orderlist[i].command, studentlist[j]);//插入队列
					studentlist.erase(studentlist.begin() + j+1); //删除原数据
					break;
				}
			}
		}
	}

	//输出结果
	for (int i = 0; i < n; i++)
	{
		cout << studentlist.at(i) << " ";

	}
	cout << endl;
	return 0;
}