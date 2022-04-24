#include "FormEvent.h"

//constructor
FormEvent::FormEvent()
{
}

//constructor non default
FormEvent::FormEvent(Mission m)
{
	EventDay = m.getfd();
	id = m.getID();
	M = m;
}

//copy constructor
FormEvent::FormEvent(const FormEvent& ev)
{
	EventDay = ev.EventDay;
	id = ev.id;
	M = ev.M;
}

//execution of formulation class
void FormEvent::Execute(LinkedQueue<Mission>& q, PrioQueue<Mission>& pq)
{
	if (M.getmtype() == 'E')
	{
		float prio=(0.45*M.getsig())+(0.25*1/(M.getfd()))+(0.15*1/(M.gettloc()))+(0.15*1/(M.getmd()));
		pq.enqueue(M,prio);
	}
	else if (M.getmtype() == 'P')
	{
		q.enqueue(M);
	}
}

//destructor
FormEvent::~FormEvent()
{
}
