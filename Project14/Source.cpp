#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component abstract
{
protected:
	string name;
public:
	Component(string name)
	{
		this->name = name;
	}

	virtual  void Add(Component* c) abstract;
	virtual  void Remove(Component* c) abstract;
	virtual  void Display(int depth) abstract;
};

class Composite : public Component
{
	vector<Component*> components;

public:
	Composite(string name) :Component(name) {}

	void Add(Component* component) override
	{
		components.push_back(component);
	}
	void Remove(Component* component) override
	{
		auto iter = find(components.begin(), components.end(), component);
		components.erase(iter);
	}
	void Display(int depth) override
	{
		cout << name << endl;

		for (Component* component : components)
		{
			component->Display(depth + 2);
		}
	}
};

class Leaf : public Component
{
public:
	Leaf(string name) : Component(name) {}

	void Add(Component* c) override
	{
		cout << "Cannot add to file\n";
	}
	void Remove(Component* c) override
	{
		cout << "Cannot remove from file\n";
	}
	void Display(int depth) override
	{
		cout << name << endl;
	}
};

int main()
{

	Component* receptionArea = new Composite("1. Reception area");

	receptionArea->Add(new Leaf("a. It should be designed in warm tones"));
	receptionArea->Add(new Leaf("b. Coffee table"));

	Component* comp = new Composite("Folder X");

	comp->Add(new Leaf("File XA"));
	comp->Add(new Leaf("File XB"));
	receptionArea->Add(comp);

	Component* comp2 = new Composite("");

	comp2->Add(new Leaf("File YA"));
	comp2->Add(new Leaf("File YB"));

	Component* comp3 = new Composite("Folder Z");
	comp3->Add(new Leaf("File YZA"));
	comp3->Add(new Leaf("File YZB"));
	comp2->Add(comp3);

	receptionArea->Add(comp2);

	receptionArea->Add(new Leaf("File C"));

	Component* leaf = new Leaf("File D");
	receptionArea->Add(leaf);
	receptionArea->Display(1);
	cout << "\n\n";

	receptionArea->Remove(leaf);
	receptionArea->Display(1);

	cout << "\n\n";
	comp2->Remove(comp3);
	receptionArea->Display(1);

	system("pause");
}


