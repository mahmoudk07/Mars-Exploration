#include "Rover.h"


//constreuctor default
Rover::Rover()
{
	CompletedMissions = 0;
	ID = 0;
	Speed = -1;
	CheckupDur = -1;
	missionsuntilcheck = -1;
	Exitcount=-1;
	RoverType = 'u';
}

//constreuctor non default
Rover::Rover(char typ, int s, int check,int Cm, int id)
{
	setType(typ);
	setSpeed(s);
	setCheckupDur(check);
	missionsuntilcheck = Cm;
	CompletedMissions = 0;
	Exitcount = CheckupDur;
	ID = id;
}

//copy constructor
Rover::Rover(const Rover& r)
{
	RoverType = r.RoverType;
	Speed = r.Speed;
	CheckupDur = r.CheckupDur;
	CompletedMissions = r.CompletedMissions;
	missionsuntilcheck = r.missionsuntilcheck;
	Exitcount = r.Exitcount;
	ID = r.getid();
}

//setting type
void Rover::setType(char t)
{
	if(t=='E'|| t == 'P')
	RoverType = t;
}

//setting speed 
void Rover::setSpeed(int S)
{
	if (S >= 0)
	Speed = S;
}

//setting checkup duration of rover
void Rover::setCheckupDur(int c)
{
	if (c >= 0)
	CheckupDur = c;
}

//setting missions completed
void Rover::IncrementCompMission()
{
	CompletedMissions++;
}

void Rover::Resetcompmiss()
{
	CompletedMissions = 0;
}


//getting type
char Rover::getType() const
{
	return RoverType;
}

//getting speed
int Rover::getSpeed() const
{
	return Speed;
}

//getting checkup duration of rover
int Rover::getCheckupDur() const
{
	return CheckupDur;
}

//getting no of missions completed by rover
int Rover::getCompMission() const
{
	return CompletedMissions;
}

void Rover::setMuntilcheck(int cm)
{
	if (cm >= 0)
		missionsuntilcheck = cm;
}

int Rover::getMuntilcheck()
{
	return missionsuntilcheck;
}

void Rover::setExitcount()
{
	Exitcount = CheckupDur;
}

void Rover::decExitcount()
{
	Exitcount--;
}

int Rover::getExitcount()
{
	return Exitcount;
}

void Rover::Setid(int x)
{
	ID = x;
}

int Rover::getid() const
{
	return ID;
}

//destructor
Rover::~Rover()
{
	
}