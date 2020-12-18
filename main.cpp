#include <math.h>
#include <iostream>
#include "PD.h"

using namespace std;

int main()
{
	double FrequencyC1 = 0;
	double FrequencyC2 = 0;
	double FrequencyD = 0;

	jz data;
	data.initialize_players();
	
	for (int i = 0; i < TimeStep; i++)
	{
		data.initialize_payoff();
		data.syn_players();

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

	}

	return 0;
}
