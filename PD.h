#pragma once
#ifndef _PD_H_
#define _PD_H_

#define L 100
#define K 0.1
#define TimeStep 1000
#define b 1.2
#define r 0.2
#define alpha 0.2

#define random(x) (rand()%x)

class jz {
public:
	int initialize_players();
	double initialize_payoff();
	int syn_players();
	double syn_payoff();
	double feimi(double a, double c, int position);
public:
	int CurrentPlayers[L][L];
	int CurrentPlayersPlus[L + 2][L + 2];
	int TempPlayers[L][L];
	int TempPlayersPlus[L + 2][L + 2];
	double Payoff[L][L];
	double PayoffPlus[L + 2][L + 2];
};

#endif // _PD_H_
