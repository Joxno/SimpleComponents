#ifndef COMPONENTHANDLER_H
#define COMPONENTHANDLER_H
#include <vector>
#include "Component.h"
using namespace std;
class ComponentHandler
{
	private:
		vector<Component*> m_Components;
	public:
		void AddComponent(Component *C) {m_Components.push_back(C); m_Components[m_Components.size()-1]->Initialize();}
		template<typename T> T* GetComponent() {for(auto C : m_Components) if(typeid(C) == typeid(T)) return C; return null;}
		template<typename T> void RemoveComponent(T *Component) {int RemoveIndex = 0; for(int i = 0; i < m_Components.size(); i++) if(C->isComponent(Component)) {RemoveIndex = i; break;} m_Components.remove(RemoveIndex); }
		void UpdateComponents() {for(auto C : m_Components) C->Update();}
		void FixedUpdateComponents() {for(auto C : m_Components) C->FixedUpdate();}
};

#endif