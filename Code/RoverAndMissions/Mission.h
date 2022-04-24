#pragma once
#include "Rover.h"
class Mission
{
private:
	int fd, wd, Ex;
	char mtype;
	float tloc;
	float md;
	int ID;
	int sig;
	Rover r;
public:
	Mission();
	Mission(int F,int w, int ex, char x, int id, float Tloc, float Md, int Sig);
	Mission(const Mission& m1);
	void setfd(int F);
	void setwd(int w);
	void setexd(int e);
	int getfd()const;
	int getwd()const;
	int getexd()const;
	void setmtype(char x);
	char getmtype()const;
	void setloc(float t);
	float gettloc()const;
	void setmd(float x);
	float getmd()const;
	void setID(int id);
	int getID()const;
	void setsig(int x);
	int getsig()const;
	void AssignRover(Rover& x);
	int getCD();
	Rover getRover()const;
	~Mission();
};