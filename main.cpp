#include "PD.h"

using namespace std;

int main()
{
	double FrequencyC1 = 0;
	double FrequencyC2 = 0;
	double FrequencyD = 0;
	double resultC1[TimeStep];
	double resultC2[TimeStep];
	double resultD[TimeStep];
	

	jz data;
	data.initialize_players();
	
	for (int t = 0; t < TimeStep; t++)
	{
		data.initialize_payoff();
		data.syn_players();
		//博弈
		for (int i = 1; i < L + 1; i++)
		{
			for (int j = 1; j < L + 1; j++)
			{
				for (int m = -1; m < 2; m++)
				{
					for (int n = -1; n < 2; n++)
					{
						if (m != 0 && n != 0)
						{
							int I = i + m;
							int J = j + n;
							if (data.CurrentPlayersPlus[i][j] == 1 && data.CurrentPlayersPlus[I][J] == 1)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + 1;
							if (data.CurrentPlayersPlus[i][j] == 1 && data.CurrentPlayersPlus[I][J] == 2)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + 1 - r;
							if (data.CurrentPlayersPlus[i][j] == 1 && data.CurrentPlayersPlus[I][J] == 3)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + alpha;
							if (data.CurrentPlayersPlus[i][j] == 2 && data.CurrentPlayersPlus[I][J] == 1)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + 1 + r;
							if (data.CurrentPlayersPlus[i][j] == 2 && data.CurrentPlayersPlus[I][J] == 2)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + 1;
							if (data.CurrentPlayersPlus[i][j] == 2 && data.CurrentPlayersPlus[I][J] == 3)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + 0;
							if (data.CurrentPlayersPlus[i][j] == 3 && data.CurrentPlayersPlus[I][J] == 1)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + b - alpha;
							if (data.CurrentPlayersPlus[i][j] == 3 && data.CurrentPlayersPlus[I][J] == 2)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + b;
							if (data.CurrentPlayersPlus[i][j] == 3 && data.CurrentPlayersPlus[I][J] == 3)
								data.PayoffPlus[i][j] = data.PayoffPlus[i][j] + 0;
						}
					}
				}
			}
		}
		data.syn_payoff();
		//Learning
		for (int i = 1; i < L + 1; i++)
		{
			for (int j = 1; j < L + 1; j++)
			{
				srand(time(0));
				int position = random(8);
				int I, J;
				double W, a;
				switch (position)
				{
				case 1:
					I = i - 1;
					J = j - 1;
					W = data.feimi(i, j, I, J);
					srand(time(0));
					a = random(100) / (double)101;
					if (a <= W)
						a = 1;
					else
						a = 0;
					if (a == 1)
						data.TempPlayersPlus[i][j] = a * data.CurrentPlayersPlus[I][J];
				case 2:
					I = i - 1;
					J = j;
					W = data.feimi(i, j, I, J);
					srand(time(0));
					a = random(100) / (double)101;
					if (a <= W)
						a = 1;
					else
						a = 0;
					if (a == 1)
						data.TempPlayersPlus[i][j] = a * data.CurrentPlayersPlus[I][J];
				case 3:
					I = i - 1;
					J = j + 1;
					W = data.feimi(i, j, I, J);
					srand(time(0));
					a = random(100) / (double)101;
					if (a <= W)
						a = 1;
					else
						a = 0;
					if (a == 1)
						data.TempPlayersPlus[i][j] = a * data.CurrentPlayersPlus[I][J];
				case 4:
					I = i;
					J = j - 1;
					W = data.feimi(i, j, I, J);
					srand(time(0));
					a = random(100) / (double)101;
					if (a <= W)
						a = 1;
					else
						a = 0;
					if (a == 1)
						data.TempPlayersPlus[i][j] = a * data.CurrentPlayersPlus[I][J];
				case 5:
					I = i;
					J = j + 1;
					W = data.feimi(i, j, I, J);
					srand(time(0));
					a = random(100) / (double)101;
					if (a <= W)
						a = 1;
					else
						a = 0;
					if (a == 1)
						data.TempPlayersPlus[i][j] = a * data.CurrentPlayersPlus[I][J];
				case 6:
					I = i + 1;
					J = j - 1;
					W = data.feimi(i, j, I, J);
					srand(time(0));
					a = random(100) / (double)101;
					if (a <= W)
						a = 1;
					else
						a = 0;
					if (a == 1)
						data.TempPlayersPlus[i][j] = a * data.CurrentPlayersPlus[I][J];
				case 7:
					I = i + 1;
					J = j;
					W = data.feimi(i, j, I, J);
					srand(time(0));
					a = random(100) / (double)101;
					if (a <= W)
						a = 1;
					else
						a = 0;
					if (a == 1)
						data.TempPlayersPlus[i][j] = a * data.CurrentPlayersPlus[I][J];
				case 8:
					I = i + 1;
					J = j + 1;
					W = data.feimi(i, j, I, J);
					srand(time(0));
					a = random(100) / (double)101;
					if (a <= W)
						a = 1;
					else
						a = 0;
					if (a == 1)
						data.TempPlayersPlus[i][j] = a * data.CurrentPlayersPlus[I][J];
				}
			}
		}
		//同步
		for (int i = 0; i < L; i++)
			for (int j = 0; j < L; j++)
				data.CurrentPlayers[i][j] = data.CurrentPlayersPlus[i + 1][j + 1];
		//求和
		FrequencyC1 = data.players_sum(1);
		FrequencyC2 = data.players_sum(2);
		FrequencyD = data.players_sum(3);
		resultC1[t] = FrequencyC1;
		resultC2[t] = FrequencyC2;
		resultD[t] = FrequencyD;
	}
	cout << resultC1[500] << endl;
	return 0;
}
