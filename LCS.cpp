#include <string>
#include <iostream>
#include <chrono>
#include <algorithm>

int main(int argc, char const *argv[])
{
	//諸々の宣言
	std::string S = "aaaaaaaaaaaaaaaa";
	std::string T = "abababababababab";
	std::chrono::system_clock::time_point start,end;//処理時間の計測用


	//表の作成
	int** table_ST = new int*[S.size()+1];
	for (int i = 0; i < S.size()+1; ++i)
	{
		table_ST[i] = new int[T.size()+1];
		for (int j = 0; j < T.size()+1; ++j)
		{
			table_ST[i][j]=0;
		}
	}

	//処理部分
	start = std::chrono::system_clock::now();//計測開始
	int N = 10000;
	for (int ii = 0; ii < N; ++ii)
	{
		for (int i = 0; i < S.size(); ++i)
		{
			for (int j = 0; j < T.size(); ++j)
			{
				if (S[i]==T[j])
				{
					table_ST[i+1][j+1]=std::max(table_ST[i+1][j+1],table_ST[i][j]+1);
				}
				table_ST[i+1][j+1]=std::max(table_ST[i+1][j+1],table_ST[i+1][j]);
				table_ST[i+1][j+1]=std::max(table_ST[i+1][j+1],table_ST[i][j+1]);
			}
		}
	}
	end = std::chrono::system_clock::now();//計測終了
	auto elapsed = std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count();
    std::cout << elapsed <<"ms"<< std::endl;//タイム表示
    std::cout << table_ST[S.size()][T.size()] << std::endl;
    return 0;
}