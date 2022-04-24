#include<iostream>
#include"MarsStation/MarsStation.h"
using namespace std;

int main()
{
		MarsStation Maestro;
		int DAY=0;
		Maestro.ReadInpFile();
		Maestro.takelist();
		Maestro.SetAvalRovers();
		int x = 0;
		int y;
		char s = Maestro.ReadFromUser();
		while (!Maestro.END(x, y))
		{
			DAY = Maestro.getDaycount();
			Maestro.SendtoForm();
			Maestro.AssigntoRover();
			Maestro.SendtoComp();
			Maestro.FromcheckToAval();
			Maestro.decExitcountRov();
			Maestro.Interface(s);
			Maestro.IncremrntDaycount();
			if (!Maestro.ISthereRover())
			{
				break;
			}
		}
		Maestro.OutputFile();
		return 0;
}