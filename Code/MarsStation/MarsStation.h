#pragma once
#include<math.h>
#include"../Event/FormEvent.h"
#include"../UI/UI.h"

class MarsStation
{
private:
	LinkedQueue<Mission> PolarWaiting_Mission,Lp;
	LinkedQueue<Mission>PolarCompleted_Mission,Le;
	LinkedQueue<Mission>EmerCompleted_Mission,Allc;
	PrioQueue<Mission> EmerWaiting_Mission;
	PrioQueue<Mission> PolarInexecution_Mission;
	PrioQueue<Mission> EmerInexecution_Mission;
	LinkedList<Rover> PolarRover_Available;
	LinkedList<Rover> EmerRover_Available;
	LinkedQueue<Rover> PolarRover_Checkup;
	LinkedQueue<Rover>EmerRover_Checkup;
	LinkedQueue<FormEvent*> formevent;
	int dayscount;
	int counter;
	LinkedQueue<Mission> lm;
	UI inp;

public:
	MarsStation();
	void IncremrntDaycount();
	void ActualdaybyDEc();
	int getDaycount();
	//member functions
	void ReadInpFile();//read input file after load it
	void SetAvalRovers();
	//fill waiting mission lists
	void SendtoForm();
	//assign to rover and move waiting mission to inExecution
	void AssigntoRover();

	void decExitcountRov();

	//move mission to complete list and check rover to send to checkup or be avaliable
	void SendtoComp();
	void takelist();
	void FromcheckToAval();
	UI getui();
	// Exit program function
	bool END(int &x,int&y);

	LinkedQueue<Mission> getcompE();
	LinkedQueue<Mission> getcompP();

	bool ISthereRover();


	void OutputFile();
	char ReadFromUser();
	void Interface(char s);

	~MarsStation();
};

