#pragma once
#include"../RoverAndMissions/Mission.h"
#include"../RoverAndMissions/Rover.h"
#include"../Main_data/LinkedQueue.h"
#include"../Main_data/PrioQueue.h"
class FormEvent
{
private:
    int EventDay, id;
    Mission M;
public:

    //constructor default
    FormEvent();

    //constructor non default
    FormEvent(Mission m);

    //copy constructor
    FormEvent(const FormEvent& ev);

    //execution of formulation class
     void Execute(LinkedQueue<Mission>& q, PrioQueue<Mission>& pq);

     //destructor
     ~FormEvent();
};

