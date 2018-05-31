#include<iostream>
#include<vector>
using namespace std;

/*
 0 1 2
 8 9 3
 7 6 5

*/

void ClockwisePrintMat(const vector<vector<int>> &mat){
	int flag = 0;
	int rowStart = 0;
	int rowEnd = mat.size()-1;
	int colStart = 0;
	int colEnd = mat[0].size()-1;
	while (true)
	{
		int ival = flag % 4;
		if (rowStart>rowEnd || colStart>colEnd)
		{
			break;
		}
		if (ival == 0)
		{
			for (int j = colStart; j <= colEnd; j++)
			{
				cout << mat[rowStart][j] << " ";
			}
			++flag;
		}
		else if (ival == 1)
		{
			for (int i = rowStart + 1; i <= rowEnd; i++)
			{
				cout << mat[i][colEnd] << " ";
			}
			++flag;
		}
		else if (ival == 2)
		{
			for (int j = colEnd - 1; j >= colStart; j--)
			{
				cout << mat[rowEnd][j] << " ";
			}
			++flag;
		}
		else if (ival == 3)
		{
			for (int i = rowEnd - 1; i >= rowStart + 1; i--)
			{
				cout << mat[i][colStart] << " ";
			}
			++flag;
			rowStart++;
			rowEnd--;
			colStart++;
			colEnd--;
		}
	}

}
int main()
{ 
	vector<vector<int>> mat(4, vector<int>(3,0));
	int i = 0;
	for (auto&& arr:mat)
	{
		for (auto& element:arr)
		{
			element = (++i);
			cout << element << " ";

		}
		cout << endl;
	}
	ClockwisePrintMat(mat);
	return 0;
}