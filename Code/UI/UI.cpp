#include "UI.h"
#include<iostream>
#include<fstream>
using std::ofstream;
#include<string>
#include <thread>
#include <chrono>
using namespace std;
UI::UI()
{
	Daycount = 1;
	PolarNumR = 0;
	EmerNumR = 0;
	PolarSpeedR = 0;
	EmerSpeedR = 0;
	NumMissiontoCheck = 0;
	PolarDurR = 0;
	EmerDurR = 0;
	NumEvent=0;
	c1 = 0;
	c2 = 0;
}

void UI::setPolarNumR(int pr)
{
	if (pr > 0)
		PolarNumR = pr;
}

int UI::getPolarNumR()
{
	return PolarNumR;
}

void UI::setEmerNumR(int er)
{
	if(er>0)
	EmerNumR = er;
}

int UI::getEmerNumR()
{
	return EmerNumR;
}

void UI::setPolarSpeedR(int ps)
{
	if(ps>0)
	PolarSpeedR = ps;
}

int UI::getPolarSpeedR()
{
	return PolarSpeedR;
}

void UI::setEmerSpeedR(int es)
{
	if(es>0)
	EmerSpeedR = es;
}

int UI::getEmerSpeedR()
{
	return EmerSpeedR;
}

void UI::setNumMissiontoCheck(int nm)
{
	if(nm>0)
	NumMissiontoCheck = nm;
}

int UI::getNumMissiontoCheck()
{
	return NumMissiontoCheck;
}

void UI::setPolarDurR(int pd)
{
	if(pd>0)
	PolarDurR = pd;
}

int UI::getPolarDurR()
{
	return PolarDurR;
}

void UI::setEmerDurR(int ed)
{
	if(ed>0)
	EmerDurR = ed;
}

int UI::getEmerDurR()
{
	return EmerDurR;
}

void UI::setNumEvent(int ne)
{
	if(ne>0)
	NumEvent = ne;
}

int UI::getNumEvent()
{
	return NumEvent;
}

void UI::mlistdeq(Mission item)
{
	mlist.dequeue(item);
}

void UI::getlistofmission(LinkedQueue<Mission>& listiOfmissions)
{
	listiOfmissions = mlist;
}

void UI::Input()
{

	ifstream fin("Input.txt");
	fin >> PolarNumR >> EmerNumR;
	fin >> PolarSpeedR >> EmerSpeedR;
	fin >> NumMissiontoCheck >> PolarDurR >> EmerDurR;
	fin >> NumEvent;
	int count = 0;
	char useless, q;
	int formd, Id, tl, mD, SIgn;
	if (PolarSpeedR <= 0)
	{
		PolarNumR = 0;
	}
	if (EmerSpeedR <= 0)
	{
		EmerNumR = 0;
	}
	while (count < NumEvent)
	{
		Mission m1;
		fin >> useless >> q >> formd >> Id >> tl >> mD >> SIgn;
		if (PolarNumR == 0 && EmerNumR == 0)
		{
			NumEvent = 0;
			c1 = 0;
			c2 = 0;
			break;
		}
		else if (q == 'P' && PolarNumR !=0)
			c1++;
		else if(q == 'E'&& (PolarNumR != 0|| EmerNumR != 0))
			c2++;
	
			m1.setmtype(q);
			m1.setfd(formd);
			m1.setID(Id);
			m1.setloc(tl);
			m1.setmd(mD);
			m1.setsig(SIgn);
			if (q == 'P' && PolarNumR == 0)
			{
				NumEvent--;
			}
			else
			{
				mlist.enqueue(m1);
				count++;
			}
	}
}

void UI::Output(LinkedQueue<Mission>& Q)
{
	//Declare a file-stream variable
	ofstream fileOut;

	//open a file to write to
	fileOut.open("output.txt");

	//write the information of the file 
	fileOut << "CD\tID\tFD\tWD\tED" << endl;

	///////////////////////////////////////////////////////////

	LinkedQueue<Mission> temp, temp2;
	Mission m; int z = 0;
	Mission* arr = new Mission[NumEvent];
	while (Q.dequeue(m))
	{
		arr[z] = m;
		z++;
		temp2.enqueue(m);
	}
	for (int i = 0; i < z; i++)
	{
		
		for (int j = 0; j < z; j++)
		{
			if (arr[j].getCD() == arr[j + 1].getCD() && arr[j].getexd() > arr[j + 1].getexd())
			{
				Mission m2;
				m2 = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = m2;
				
			}
		}
	}
	for (int i = 0; i < z; i++)
	{
		Q.enqueue(arr[i]);
	}

	while (Q.dequeue(m))
	{
		int CD = m.getfd() + m.getwd() + m.getexd();
		fileOut << CD << "\t" << m.getID() << "\t" << m.getfd() << "\t" << m.getwd() << "\t" << m.getexd() << endl;
		temp.enqueue(m);
	}
	float sumWD = 0.00;
	float sumED = 0.00;
	int count = 0;

	while (temp.dequeue(m))
	{
		sumWD = sumWD + m.getwd();
		sumED = sumED + m.getexd();
		count++;
		Q.enqueue(m);
	}
	int w = 0, Ex = 0;
	if ((PolarNumR + EmerNumR) == 0|| (PolarNumR==0&&c2==0))
	{
		w = 0;
		Ex = 0;
	}
	else
	{
		w = float(sumWD / count);
			Ex = float(sumED / count);
	}
	fileOut << "........................................" << endl;
	fileOut << "........................................" << endl;
	fileOut << "Missions: " << NumEvent << " [P: " << c1 << ",E: " << c2 << "]" << endl;
	fileOut << "Rovers: " << PolarNumR + EmerNumR << " [P: " << PolarNumR << ",E: " << EmerNumR << "]" << endl;
	fileOut << "Avg Wait=" << w << ", " << "Avg Exec=" << Ex << endl;

	//////////////////////////////////////////////////////////

	//close the file stream 
	fileOut.close();
}



void UI::IncrementDAy()
{
	Daycount++;
}

int UI::RoverNum()
{

	return PolarNumR+ EmerNumR;
}



char UI::AskUser()
{
	char s;
	cout << "Please Select The Program Mode." << endl;
	cout << "Interactive Mode (A)" << endl;
	cout << "Step-by-Step Mode (B)" << endl;
	cout << "Silent Mode (C)" << endl;
	cin >> s;
	cin.ignore();
	system("cls");
	return s;
}

void UI::ProgInterface(char s,int DC, LinkedQueue<Mission>& PW, LinkedQueue<Mission>& PC, LinkedQueue<Mission> &EC,
	PrioQueue<Mission> &EW, PrioQueue<Mission>& PI, PrioQueue<Mission> &EI, LinkedList<Rover>&APR, LinkedList<Rover>&AER,
	LinkedQueue<Rover>& PCR, LinkedQueue<Rover> &ECR)
{
	Mission m,m1,M,M1,mi,mi1;
	Rover r, r1, R, R1,R2,R3;
	LinkedQueue<Mission>ew, ewtemp, pw, pwtemp, ei, pi, eitemp, pitemp, ec, ectemp, pc, pctemp;
	LinkedQueue<Rover>pcr, pcrtemp, ecr, ecrtemp;
	LinkedList<Rover> Rover1, Rover2, Rover3;
	int cew = 1,cpw=1,cei=1,cpi=1,cec=1,cpc=1,cea=1,cpa=1,cce=1,ccp=1,eee=1,eeee=1;

	//waiting
	while (PW.dequeue(m1))
	{
		pw.enqueue(m1);
		pwtemp.enqueue(m1);
	}

	while (pwtemp.dequeue(m1))
	{
		PW.enqueue(m1);
	}

	while (EW.dequeue(m))
	{
		ew.enqueue(m);
		ewtemp.enqueue(m);
	}
	while (ewtemp.dequeue(m))
	{
		float prio = (0.45 * m.getsig()) + (0.25 * 1 / (m.getfd())) + (0.15 * 1 / (m.gettloc())) + (0.15 * 1 / (m.getmd()));
		EW.enqueue(m, prio);
	}

	//IN execution
	while (EI.dequeue(M))
	{
		ei.enqueue(M);
		eitemp.enqueue(M);
	}
	while (eitemp.dequeue(M))
	{
		EI.enqueue(M, (M.getfd() + M.getwd() + M.getexd()) * (-1));
	}
	while (PI.dequeue(M1))
	{
		pi.enqueue(M1);
		pitemp.enqueue(M1);
	}
	while (pitemp.dequeue(M1))
	{
		PI.enqueue(M1, (M1.getfd() + M1.getwd() + M1.getexd()) * (-1));
	}
	//completed missons
	while (EC.dequeue(mi))
	{
		ec.enqueue(mi);
		ectemp.enqueue(mi);
	}
	while (ectemp.dequeue(mi))
	{
		EC.enqueue(mi);
	}
	while (PC.dequeue(mi1))
	{
		pc.enqueue(mi1);
		pctemp.enqueue(mi1);
	}
	while (pctemp.dequeue(mi1))
	{
		PC.enqueue(mi1);
	}
	//Available rovers

	while (AER.deletefirst(R2))
	{
		Rover1.InsertEnd(R2);
		Rover2.InsertEnd(R2);
	}
	while (Rover2.deletefirst(R2))
	{
		AER.InsertEnd(R2);
	}
	while (APR.deletefirst(R3))
	{
		Rover2.InsertEnd(R3);
		Rover3.InsertEnd(R3);
	}
	while (Rover2.deletefirst(R3))
	{
		APR.InsertEnd(R3);
	}

	//Checkup rovers 
	while (ECR.dequeue(R))
	{
		ecr.enqueue(R);
		ecrtemp.enqueue(R);
	}
	while (ecrtemp.dequeue(R))
	{
		ECR.enqueue(R);
	}
	while (PCR.dequeue(R1))
	{
		pcr.enqueue(R1);
		pcrtemp.enqueue(R1);
	}
	while (pcrtemp.dequeue(R1))
	{
		PCR.enqueue(R1);
	}

	//call body
	if (s == 'A' || s == 'B')
	{
		cout << "Current Day:" << DC << endl;
		cout << PW.getlength() + EW.getlength() << " Waiting Missions: [";
		while (ew.dequeue(m))
		{
			if (cew == EW.getlength())
				cout << m.getID() ;
			else
			cout << m.getID() << ",";
			cew++;
		}
	    cout << "] (";
		while (pw.dequeue(m1))
		{
			if (cpw == PW.getlength())
				cout << m1.getID();
			else
				cout << m1.getID() << ",";
			cpw++;
		}
		cout << ") " << endl;
	    cout << "-------------------------------------------------------" << endl;
		cout << EI.getlength() + PI.getlength() << " In-Execution Missions/Rovers: [";
		while (ei.dequeue(M))
		{
			if (cei == EI.getlength())
				cout << M.getID() << "/" << M.getRover().getid();
			else
				cout << M.getID() << "/" << M.getRover().getid() << ",";
			cei++;
		}
		cout << "] (";
		while (pi.dequeue(M1))
		{
			if (cpi == PI.getlength())
				cout << M1.getID() << "/" << M1.getRover().getid();
			else
				cout << M1.getID() << "/" << M1.getRover().getid() << ",";
			cpi++;
		}
		cout << ")" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << AER.getlength() + APR.getlength() << " Available Rovers: [";
		while (Rover1.deletefirst(R2))
		{
			if (eee == AER.getlength())
				cout << R2.getid();
			else
				cout << R2.getid() << ",";
			eee++;
		}
		cout << "] (";
		while (Rover3.deletefirst(R3))
		{
			if (eeee == APR.getlength())
				cout << R3.getid();
			else
				cout << R3.getid() << ",";
			eeee++;

		}

		cout << ")" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << ECR.getlength() + PCR.getlength() << " In-Checkup Rovers: [";
		while (ecr.dequeue(R))
		{
			if (cce == ECR.getlength())
				cout << R.getid();
			else
				cout << R.getid() << ",";
			cce++;
		}
		cout << "] (";
		while (pcr.dequeue(R1))
		{
			if (ccp == PCR.getlength())
				cout << R1.getid();
			else
				cout << R1.getid() << ",";
			ccp++;
		}
		cout << ")" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << PC.getlength() + EC.getlength() << " Completed Missions: [";
		while (ec.dequeue(mi))
		{
			if (cec == EC.getlength())
				cout << mi.getID();
			else
				cout << mi.getID()<< ",";
			cec++;
		}
		cout << "] (";
		while (pc.dequeue(mi1))
		{
			if (cpc == PC.getlength())
				cout << mi1.getID();
			else
				cout << mi1.getID() << ",";
			cpc++;
		}
		cout << ")" << endl;
		/////////////////////////////////////////////////////////////////////////////////////////
		IncrementDAy();
		if (s == 'A')
		{
			cin.get();
			system("cls");
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			system("cls");
		}
	}
	else if (s == 'C' && DC == 1)
	{
		cout << "Silent Mode" << endl;
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
		IncrementDAy();
	}
	else
		return;

}



UI::~UI()
{
}
