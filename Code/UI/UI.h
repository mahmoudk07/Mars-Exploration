#pragma once
#include"../Main_data/LinkedQueue.h"
#include"../Main_data/PrioQueue.h"
#include"../Main_data/LinkedList.h"
#include"../RoverAndMissions/Mission.h"
#include"../RoverAndMissions/Rover.h"
class UI
{
private:
	int PolarNumR, EmerNumR, PolarSpeedR, EmerSpeedR, NumMissiontoCheck, PolarDurR, EmerDurR, NumEvent;
	LinkedQueue<Mission> mlist;
	int Daycount,c1,c2;
public:
	UI();
	void setPolarNumR(int pr);
	int getPolarNumR();

	void setEmerNumR(int er);
	int getEmerNumR();

	void setPolarSpeedR(int ps);
	int getPolarSpeedR();

	void setEmerSpeedR(int es);
	int getEmerSpeedR();

	void setNumMissiontoCheck(int nm);
	int getNumMissiontoCheck();

	void setPolarDurR(int pd);
	int getPolarDurR();

	void setEmerDurR(int ed);
	int getEmerDurR();

	void setNumEvent(int ne);
	int getNumEvent();
	void mlistdeq( Mission item);
	void getlistofmission(LinkedQueue<Mission> & listiOfmissions);

	void Input();
	void Output(LinkedQueue<Mission>& Q);

	void IncrementDAy();
	int RoverNum();
	char AskUser();
	void ProgInterface(char s, int DC,LinkedQueue<Mission>& PW, LinkedQueue<Mission>& PC, LinkedQueue<Mission>& EC,
		PrioQueue<Mission>& EW, PrioQueue<Mission>& PI, PrioQueue<Mission>& EI, LinkedList<Rover>& PA, LinkedList<Rover>& EA,
		LinkedQueue<Rover>& PCR, LinkedQueue<Rover>& ECR);



	~UI();
};

