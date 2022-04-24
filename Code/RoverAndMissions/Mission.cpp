#include "Mission.h"

Mission::Mission()
{
}

Mission::Mission(int F, int w, int ex, char x, int id, float Tloc, float Md, int Sig)
{
	setfd(F);
	setmtype(x);
	setID(id);
	setloc(Tloc);
	setmd(Md);
	setsig(Sig);
	setwd(w);
	setexd(ex);
}

Mission::Mission(const Mission& m1)
{
	fd = m1.fd;
	mtype = m1.mtype;
	tloc = m1.tloc;
	md = m1.md;
	ID = m1.ID;
	sig = m1.sig;
	r = m1.r;
	wd = m1.wd;
	Ex = m1.Ex;
}

void Mission::setfd(int F)
{
	if (F >= 0)
	{
		fd = F;
	}
	else
	{
		return;
	}
}

void Mission::setwd(int w)
{
	if(w>=0)
	wd = w;
}

void Mission::setexd(int e)
{
	if(e>=0)
	Ex = e;
}

int Mission::getfd() const
{
	return fd;
}

int Mission::getwd() const
{
	return wd;
}

int Mission::getexd() const
{
	return Ex;
}

void Mission::setmtype(char x)
{
	if (x == 'E' ||  x == 'P')
	{
		mtype = x;
	}
	else
		return;
}



char Mission::getmtype() const
{
	return mtype;
}

void Mission::setloc(float t)
{
	if (t > 0)
	{
		tloc = t;
	}
	else
		return;
}

float Mission::gettloc() const
{
	return tloc;
}

void Mission::setmd(float x)
{
	if (x > 0)
	{
		md = x;
	}
	else
		return;
}

float Mission::getmd() const
{
	return md;
}

void Mission::setID(int id)
{
	if (id > 0)
	{
		ID = id;
	}
	else
		return;
}

int Mission::getID() const
{
	return ID;
}

void Mission::setsig(int x)
{
	if (x >= 0)
	{
		sig = x;
	}
	else
		return;
}

int Mission::getsig() const
{
	return sig;
}

void Mission::AssignRover(Rover& x)
{
	r = x;
}

int Mission::getCD()
{
	return (fd+ wd+ Ex);
}

Rover Mission::getRover() const
{
	return r;
}

Mission::~Mission()
{
}