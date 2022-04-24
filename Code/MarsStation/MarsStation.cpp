#include "MarsStation.h"


MarsStation::MarsStation()
{
	dayscount = 1;
	counter = 0;
}

void MarsStation::IncremrntDaycount()
{
		dayscount ++;
}

void MarsStation::ActualdaybyDEc()
{
	dayscount--;
}

int MarsStation::getDaycount()
{
	return dayscount;
}



void MarsStation::ReadInpFile()
{
	inp.Input();
}


void MarsStation::SendtoForm()
{
	
	Mission mm;
	while (lm.peek(mm))
	{
		if (mm.getfd() == dayscount)
		{
			lm.dequeue(mm);	
			FormEvent* ptr = new FormEvent(mm);
			ptr->Execute(PolarWaiting_Mission, EmerWaiting_Mission);
			formevent.enqueue(ptr);
			
		}
		else 
			break;
	}
}

void MarsStation::AssigntoRover()
{
	Mission m1;
	Rover r;
	while (EmerWaiting_Mission.peek(m1))
	{
		if (!EmerRover_Available.Isempty())
		{
			EmerRover_Available.deletefirst(r);
			r.IncrementCompMission();
			m1.AssignRover(r);
			//set waiting days period
			m1.setwd(dayscount - m1.getfd());
			//set exectution days period 
			float y = (float(float((m1.gettloc()*2 / r.getSpeed()))/(25)));
			m1.setexd(m1.getmd() + ceil(y));
			EmerInexecution_Mission.enqueue(m1, (m1.getfd()+m1.getwd() + m1.getexd()) * (-1));
			EmerWaiting_Mission.dequeue(m1);

		}
		else if (!PolarRover_Available.Isempty())
		{
			PolarRover_Available.deletefirst(r);
			r.IncrementCompMission();
			m1.AssignRover(r);
			//set waiting days period
			m1.setwd(dayscount - m1.getfd());
			//set exectution days period
			float y = (float(float((m1.gettloc() * 2 / r.getSpeed())) / (25)));
			m1.setexd(m1.getmd() + ceil(y));
			EmerInexecution_Mission.enqueue(m1, (m1.getfd() + m1.getwd() + m1.getexd()) * (-1));
			EmerWaiting_Mission.dequeue(m1);

		}
		else
			break;
	}
	while (PolarWaiting_Mission.peek(m1))
	{
		if (!PolarRover_Available.Isempty())
		{
			PolarRover_Available.deletefirst(r);
			r.IncrementCompMission();
			m1.AssignRover(r);
			//set waiting days period
			m1.setwd(dayscount - m1.getfd());
			//set exectution days period
			float y = (float(float((m1.gettloc() * 2 / r.getSpeed())) / (25)));
			m1.setexd(m1.getmd() + ceil(y));
			PolarInexecution_Mission.enqueue(m1, (m1.getfd() + m1.getwd() + m1.getexd()) * (-1));
			PolarWaiting_Mission.dequeue(m1);
		}
		else
			break;
	}
}

void MarsStation::decExitcountRov()
{
	LinkedQueue<Rover> rov;
	Rover r1;
	while (PolarRover_Checkup.dequeue(r1))
	{
		r1.decExitcount();
		rov.enqueue(r1);

	}
	while (rov.dequeue(r1))
	{
		PolarRover_Checkup.enqueue(r1);
	}
	while (EmerRover_Checkup.dequeue(r1))
	{
		r1.decExitcount();
		rov.enqueue(r1);
	}
	while (rov.dequeue(r1))
	{
		EmerRover_Checkup.enqueue(r1);
	}
}



void MarsStation::SetAvalRovers()
{
	int c = 1;
	int pnum = inp.getPolarNumR();
	int Enum = inp.getEmerNumR();
	int pspeed = inp.getPolarSpeedR();
	int Espeed = inp.getEmerSpeedR();
	int pcheckd = inp.getPolarDurR();
	int Echeckd = inp.getEmerDurR();
	int numMissionCheck = inp.getNumMissiontoCheck();

		for (int i = 0; i < pnum; i++)
		{
			Rover RP;
			RP.setType('P');
			RP.Setid(c);
			RP.setSpeed(pspeed);
			RP.setCheckupDur(pcheckd);
			RP.setMuntilcheck(numMissionCheck);
			RP.setExitcount();
			PolarRover_Available.InsertEnd(RP);
			c++;
		}

		for (int j = 0; j < Enum; j++)
		{
			Rover RE;
			RE.setType('E');
			RE.Setid(c);
			RE.setSpeed(Espeed);
			RE.setCheckupDur(Echeckd);
			RE.setMuntilcheck(numMissionCheck);
			RE.setExitcount();
			EmerRover_Available.InsertEnd(RE);
			c++;
		}
}

void MarsStation::SendtoComp()
{ 
	Mission m,m2;
	Rover r;
	while (EmerInexecution_Mission.peek(m))
	{
		m2 = EmerInexecution_Mission.peek2();
		if (dayscount == (m2.getfd() + m2.getwd() + m2.getexd()))
		{
			EmerCompleted_Mission.enqueue(m2);
			Le.enqueue(m2);
			Allc.enqueue(m2);
			EmerInexecution_Mission.dequeue(m);
			r = m2.getRover();
			if (r.getType() == 'E')
			{
				if (r.getCompMission() == r.getMuntilcheck())
				{
					r.Resetcompmiss();
					EmerRover_Checkup.enqueue(r);
				}
				else
				{
					EmerRover_Available.InsertEnd(r);
				}
			}
			else if (r.getType() == 'P')
			{
				if (r.getCompMission() == r.getMuntilcheck())
				{
					r.Resetcompmiss();
					PolarRover_Checkup.enqueue(r);

				}
				else
				{
					PolarRover_Available.InsertEnd(r);
				}
			}
		}
		else
			break;
	}

	while (PolarInexecution_Mission.peek(m))
	{
		m2 = PolarInexecution_Mission.peek2();
		if (dayscount == (m2.getfd() + m2.getwd() + m2.getexd()))
		{
			PolarCompleted_Mission.enqueue(m2);
			Lp.enqueue(m);
			Allc.enqueue(m2);
			PolarInexecution_Mission.dequeue(m);

			r = m2.getRover();
			if (r.getCompMission() == r.getMuntilcheck())
			{
				r.Resetcompmiss();
				PolarRover_Checkup.enqueue(r);
			}
			else
			{
				PolarRover_Available.InsertEnd(r);
			}
		}
		else
			break;
	}
}

void MarsStation::takelist()
{
	inp.getlistofmission(lm);
}

void MarsStation::FromcheckToAval()
{
	Rover r;
	while (EmerRover_Checkup.peek(r))
	{
		if (r.getExitcount() == 0)
		{
			r.setExitcount();
			EmerRover_Available.InsertEnd(r);
			EmerRover_Checkup.dequeue(r);
		}
		else
			break;
	}
	while (PolarRover_Checkup.peek(r))
	{
		if (r.getExitcount() == 0)
		{
			r.setExitcount();
			PolarRover_Available.InsertEnd(r);
			PolarRover_Checkup.dequeue(r);
		}
		else
			break;
	}
}

UI MarsStation::getui()
{
	return inp;
}

bool MarsStation::END(int &x,int &y)
{
	int numMission = inp.getNumEvent();
	y = numMission;

	Mission m;
	while (EmerCompleted_Mission.dequeue(m))
	{
		counter++;
		
	}
	while (PolarCompleted_Mission.dequeue(m))
	{
		counter++;
		
	}
	if (numMission == counter)
		return true;
	return false;
}

LinkedQueue<Mission> MarsStation::getcompE()
{
	return Le;
}

LinkedQueue<Mission> MarsStation::getcompP()
{
	return Lp;
}

bool MarsStation::ISthereRover()
{
	if(inp.RoverNum()==0)
	return false;
	return true;
}

void MarsStation::OutputFile()
{
	inp.Output(Allc);
}

char MarsStation::ReadFromUser()
{
	return inp.AskUser();
}

void MarsStation::Interface(char s)
{
	inp.ProgInterface(s,dayscount, PolarWaiting_Mission, Lp, Le, EmerWaiting_Mission,
		PolarInexecution_Mission, EmerInexecution_Mission, PolarRover_Available, EmerRover_Available, PolarRover_Checkup,
		EmerRover_Checkup);
}

MarsStation::~MarsStation()
{
	
}
