#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component
{
protected:
	string name;
public:
	Component(string name)
	{
		this->name = name;
	}

	virtual void Add(Component* c) = 0;
	virtual void Remove(Component* c) = 0;
	virtual void Display(int depth) = 0;
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
		for (int i = 0; i < depth; i++)
		{
			cout << " ";
		}
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
		for (int i = 0; i < depth; i++)
		{
			cout << " ";
		}
		cout << name << endl;
	}
};

int main()
{
	// reception area
	Component* receptionArea = new Composite("1. Reception area");

	receptionArea->Add(new Leaf("a. It should be designed in warm tones"));

	Component* coffeeTable = new Composite("b. Coffee table");
	coffeeTable->Add(new Leaf("i. 10-20 magazines such as 'Computer World'"));
	receptionArea->Add(coffeeTable);

	receptionArea->Add(new Leaf("c. Soft sofa"));
	Component* secretaryTable = new Composite("d. Secretary's desk");
	secretaryTable->Add(new Leaf("i. Computer"));
	secretaryTable->Add(new Leaf("ii. Office supplies"));
	receptionArea->Add(secretaryTable);
	receptionArea->Add(new Leaf("e. Water cooler with hot and cold water"));

	receptionArea->Display(1);
	cout << endl;

	// classroom 1
	Component* classroom1 = new Composite("2. Classroom 1");
	classroom1->Add(new Leaf("a. 10 desks"));
	classroom1->Add(new Leaf("b. Board"));
	Component* teacherDesk = new Composite("c. Teacher's desk");
	teacherDesk->Add(new Leaf("i. Computer"));
	classroom1->Add(teacherDesk);
	classroom1->Add(new Leaf("d. Poster of famous mathematicians"));

	classroom1->Display(1);
	cout << endl;

	// classroom 2
	Component* classroom2 = new Composite("3. Classroom 2");
	Component* blackDesks = new Composite("a. 20 desks");
	blackDesks->Add(new Leaf("i. Black desks"));
	blackDesks->Add(new Leaf("ii. The desks are arranged in an ovel or a circle"));
	classroom2->Add(blackDesks);
	classroom2->Add(new Leaf("b. Board"));
	classroom2->Add(new Leaf("c. Soft sofa"));

	classroom2->Display(1);
	cout << endl;

	// computer classroom
	Component* computerClassroom = new Composite("4. Computer classroom");
	Component* computerDesks = new Composite("a. 10 computer desks");
	computerDesks->Add(new Leaf("i. A computer on each desk"));
	computerDesks->Add(new Leaf("ii. A power outlet near each desk"));
	computerClassroom->Add(computerDesks);
	Component* board = new Composite("b. Board");
	board->Add(new Leaf("i. A set of colored markers"));
	computerClassroom->Add(board);

	computerClassroom->Display(1);
	cout << endl;

	// dining area
	Component* diningRoom = new Composite("5. Dining room");
	diningRoom->Add(new Leaf("1. Coffee machine"));
	Component* table = new Composite("2. Table");
	table->Add(new Leaf("i. 4 chairs"));
	diningRoom->Add(table);
	diningRoom->Add(new Leaf("3. Refrigerator"));
	diningRoom->Add(new Leaf("4. Sink"));

	diningRoom->Display(1);
	cout << endl;

	system("pause");
}


