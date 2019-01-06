//顺时针打印矩阵
#include<iostream>
#include <algorithm>
#include<string>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int>result;
		if (matrix.size() == 0)return result;

		int row_num = matrix.size();
		int col_num = matrix[0].size();
		int col = 0,row=0,d_col=0,d_row=0;
		int count = 0;
		if (row_num % 2 == 0)
		{
			count = row_num / 2;
		}
		else
		{
			count = row_num / 2 + 1;
		}
		while (row<count)
		{
			col = d_col;
			while (col<col_num-d_col)
			{
				result.push_back(matrix[row][col]);
				col++;
			}
			row = d_row+1;
			col = col_num - d_col - 1;
			while (row<row_num-d_row-1&&col>=d_col)
			{
				result.push_back(matrix[row][col]);
				row++;
			}
			row = row_num - d_row-1;
			col = col_num - d_col-1;
			while (col>=d_col&&row>d_row)
			{
				result.push_back(matrix[row][col]);
				col--;
			}
			row=row_num-d_row-2;
			col = d_col;
			while (row>d_row&&col<col_num-d_col-1)
			{
				result.push_back(matrix[row][col]);
				row--;
			}
			d_col++;
			d_row++;
			row = d_row;
		}
		return result;
	}
};

int main()
{
	Solution solver;
	vector<vector<int>> vec;

	int num = 1;
	for (int i = 1; i <6; i++)
	{
		vector<int>temp;
		for (int j = 1; j < 2; j++)
		{
			temp.push_back(num);
			num++;
		}
		vec.push_back(temp);
	}
	vector<int>a=solver.printMatrix(vec);
	return 0;
}