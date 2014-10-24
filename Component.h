#ifndef COMPONENT_H
#define COMPONENT_H
using namespace std;

	class Component
	{
		private:
			string m_Name = "";
		public:
			Component() {}
			Component(string Name) {m_Name=Name;}
			virtual void Update() {}		// Every Frame
			virtual void FixedUpdate() {}	// Fixed Interval
			virtual void Initialize() {}	// Called when added to Handler
		
			string GetName() {return m_Name;}
			void SetName(string Name) { m_Name = Name; }
			virtual bool isComponent(Component *Comp) { return !strcmp(Comp->GetName().c_str(), GetName().c_str()); }
		
	};


#endif