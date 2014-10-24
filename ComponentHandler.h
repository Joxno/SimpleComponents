#ifndef COMPONENTHANDLER_H
#define COMPONENTHANDLER_H
#include <vector>
#include "Component.h"
using namespace std;

#define CreateComponent(X) __CreateComponent<X>(#X)
#define GetComponent(X) __GetComponent<X>(#X)
	class ComponentHandler
	{
		private:
			vector<Component*> m_Components;
		public:
			template<typename T> T* __CreateComponent(string Name) { T *C = new T(); C->Initialize(); m_Components.push_back(C); return C; }
			void AddComponent(Component *C) {m_Components.push_back(C); m_Components[m_Components.size()-1]->Initialize();}
			template<typename T> T* __GetComponent(string Name){for (auto C : m_Components){if (!strcmp(Name.c_str(),C->GetName().c_str()))return (T*)C;}return NULL;}
			template<typename T> void RemoveComponent(T *Component) {int RemoveIndex = 0; for(int i = 0; i < m_Components.size(); i++) if(C->isComponent(Component)) {RemoveIndex = i; break;} m_Components.remove(RemoveIndex); }
			void UpdateComponents() {for(auto C : m_Components) C->Update();}
			void FixedUpdateComponents() {for(auto C : m_Components) C->FixedUpdate();}
	};

#endif