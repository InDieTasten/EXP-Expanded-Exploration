#include <Core\GravityThread.hpp>
#include <Core\ThreadManager.hpp>
#include <Level\SolarSystem.hpp>

GravityThread::GravityThread(ThreadManager* _parent)
{
	//pointer
	parent = _parent;

	ug::log("A GravityThread has been constructed: " + *parent->getParent()->getID());
}
GravityThread::~GravityThread()
{
	//pointer
	ThreadManager* tmp = parent;
	parent = nullptr;

	ug::log("A GravityThread has been destructed: " + *tmp->getParent()->getID());
}