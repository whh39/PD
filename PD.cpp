#include "PD.h"

int jz::initialize_players()
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			srand(time(0));
			CurrentPlayers[i][j] = random(2) + 1;
			TempPlayers[i][j] = CurrentPlayers[i][j];
		}
	}
	for (int i = 0; i < L + 2; i++)
	{
		for (int j = 0; j < L + 2; j++)
		{
			CurrentPlayersPlus[i][j] = 0;
			TempPlayersPlus[i][j] = 0;
		}
	}
	return 0;
}
double jz::initialize_payoff()
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			Payoff[i][j] = 0;
		}
	}
	for (int i = 0; i < L + 2; i++)
	{
		for (int j = 0; j < L + 2; j++)
		{
			PayoffPlus[i][j] = 0;
		}
	}
	return 0;
}

int jz::syn_players()
{
	for (int i = 1; i < L + 1; i++)
	{
		for (int j = 1; j < L + 1; j++)
		{
			CurrentPlayersPlus[i][j] = CurrentPlayers[i-1][j-1];
		}
	}

	CurrentPlayersPlus[0][0] = CurrentPlayers[L - 1][L - 1];
	CurrentPlayersPlus[0][L + 1] = CurrentPlayers[L - 1][0];
	CurrentPlayersPlus[L + 1][0] = CurrentPlayers[0][L - 1];
	CurrentPlayersPlus[L + 1][L + 1] = CurrentPlayers[0][0];

	for (int i = 0; i < L + 1; i++)
	{
		CurrentPlayersPlus[0][i + 1] = CurrentPlayers[L - 1][i];
		CurrentPlayersPlus[L + 1][i + 1] = CurrentPlayers[0][i];
		CurrentPlayersPlus[i + 1][0] = CurrentPlayers[i][L - 1];
		CurrentPlayersPlus[i + 1][L + 1] = CurrentPlayers[i][0];
	}

	return 0;
}

double jz::syn_payoff()
{
	for (int i = 1; i < L + 1; i++)
	{
		for (int j = 1; j < L + 1; j++)
		{
			PayoffPlus[i][j] = Payoff[i - 1][j - 1];
		}
	}

	PayoffPlus[0][0] = Payoff[L - 1][L - 1];
	PayoffPlus[0][L + 1] = Payoff[L - 1][0];
	PayoffPlus[L + 1][0] = Payoff[0][L - 1];
	PayoffPlus[L + 1][L + 1] = Payoff[0][0];

	for (int i = 0; i < L + 1; i++)
	{
		PayoffPlus[0][i + 1] = Payoff[L - 1][i];
		PayoffPlus[L + 1][i + 1] = Payoff[0][i];
		PayoffPlus[i + 1][0] = Payoff[i][L - 1];
		PayoffPlus[i + 1][L + 1] = Payoff[i][0];
	}

	return 0;
}

double jz::feimi(int i, int j, int I, int J)
{
	return 1 / (1 + exp((PayoffPlus[i][j] - PayoffPlus[I][J]) / K));
}

double jz::players_sum(int a)
{
	int sum = 0;
	int S = L * L;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			if (CurrentPlayers[i][j] == a)
				sum++;
		}
	}
	return sum / S;
}