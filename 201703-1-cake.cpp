#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//处理输入
	int n, k;//n蛋糕的数量，k最小重量
	cin >> n >> k;

	vector<int> cakePiece;
	int tmpWeight;
	for (int i = 0; i < n; i++)
	{
		cin >> tmpWeight;
		cakePiece.push_back(tmpWeight);
	}

	//分蛋糕
	int numKid=0;
	tmpWeight = 0;
	for (int i = 0; i < cakePiece.size(); i++)
	{
		if (cakePiece[i] >= k || cakePiece[i]+tmpWeight >= k)
		{
			numKid++;
			tmpWeight = 0;
			continue;
		}
		else if(cakePiece[i]<k)
		{
			tmpWeight = tmpWeight + cakePiece[i];
		}

	}
	if (tmpWeight > 0)
		numKid++;

	//输出结果
	cout << numKid << endl;
	
	return 0;
}