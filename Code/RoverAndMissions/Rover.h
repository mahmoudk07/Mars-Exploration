#pragma once
class Rover
{
private:
	char RoverType;
	int  Speed, CheckupDur,CompletedMissions, missionsuntilcheck,Exitcount;
	int ID;
	
public:
	//constreuctor default
	Rover();

	//constreuctor non default
	Rover(char typ, int s, int check, int Cm,int id);

	//copy constructor
	Rover(const Rover& r);

	//setting type
	void setType(char t);

	//setting speed 
	void setSpeed(int S);

	//setting checkup duration of rover
	void setCheckupDur(int c);

	//increment missions completed
	void IncrementCompMission();

	//reset comp mission
	void Resetcompmiss();

	//getting type
	char getType() const;

	//getting speed
	int getSpeed() const;

	//getting checkup duration of rover
	int getCheckupDur() const;

	//getting no of missions completed by rover
	int getCompMission() const;

	void setMuntilcheck(int cm);
	int getMuntilcheck();

	void setExitcount();
	void decExitcount();
	int getExitcount();

	void Setid(int x);
	int getid()const;

	//destructor
	~Rover();
};

