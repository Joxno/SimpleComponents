#ifndef COMPONENT_H
#define COMPONENT_H
#include <typeinfo>
using namespace std;
class Component
{
	private:
		string m_Name = "";
	public:
		Component(string Name) {m_Name=Name;}
		virtual void Update() {}		// Every Frame
		virtual void FixedUpdate() {}	// Fixed Interval
		virtual void Initialize() {}	// Called when added to Handler
		
		virtual string GetName() {return m_Name;}
		virtual bool isComponent(Component *Comp) { return (typeid(Component) == typeid(*Comp)); }
		
};


#endif