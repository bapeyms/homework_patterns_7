#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Component
{
protected:
	string name;
	double price;
public:
	static double sum;
	Component(string name, double price)
	{
		this->name = name;
		this->price = price;

		sum += price;
	}

	virtual void Add(Component* c) = 0;
	virtual void Remove(Component* c) = 0;
	virtual void Display(int depth) = 0;
};

class Composite : public Component
{
	vector<Component*> components;

public:
	Composite(string name, double price) :Component(name, price) {}

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
		cout << name;
		if (price == 0)
		{
			cout << "" << endl;
		}
		else
		{
			cout << " | Price: " << price << " UAH" << endl;
		}

		for (Component* component : components)
		{
			component->Display(depth + 2);
		}
	}
};

class Leaf : public Component
{
public:
	Leaf(string name, double price) : Component(name, price) {}

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
		cout << name;
		if (price == 0)
		{
			cout << "" << endl;
		}
		else
		{
			cout << " | Price: " << price << " UAH" << endl;
		}
	}
};

double Component::sum = 0;

int main()
{
	// reception area
	Component* receptionArea = new Composite("1. Reception area", 0);

	receptionArea->Add(new Leaf("a. It should be designed in warm tones", 0));

	Component* coffeeTable = new Composite("b. Coffee table", 4500);
	coffeeTable->Add(new Leaf("i. 10-20 magazines such as 'Computer World'", 1200));
	receptionArea->Add(coffeeTable);

	receptionArea->Add(new Leaf("c. Soft sofa", 60000));
	Component* secretaryTable = new Composite("d. Secretary's desk", 18000);
	secretaryTable->Add(new Leaf("i. Computer", 30000));
	secretaryTable->Add(new Leaf("ii. Office supplies", 10000));
	receptionArea->Add(secretaryTable);
	receptionArea->Add(new Leaf("e. Water cooler with hot and cold water", 12000));

	receptionArea->Display(1);
	cout << endl;

	// classroom 1
	Component* classroom1 = new Composite("2. Classroom 1", 0);
	classroom1->Add(new Leaf("a. 10 desks", 40000));
	classroom1->Add(new Leaf("b. Board", 20000));
	Component* teacherDesk = new Composite("c. Teacher's desk", 29900);
	teacherDesk->Add(new Leaf("i. Computer", 30000));
	classroom1->Add(teacherDesk);
	classroom1->Add(new Leaf("d. Poster of famous mathematicians", 700));

	classroom1->Display(1);
	cout << endl;

	// classroom 2
	Component* classroom2 = new Composite("3. Classroom 2", 0);
	Component* blackDesks = new Composite("a. 20 desks", 50000);
	blackDesks->Add(new Leaf("i. Black desks", 20000));
	blackDesks->Add(new Leaf("ii. The desks are arranged in an ovel or a circle", 0));
	classroom2->Add(blackDesks);
	classroom2->Add(new Leaf("b. Board", 7000));
	classroom2->Add(new Leaf("c. Soft sofa", 49000));

	classroom2->Display(1);
	cout << endl;

	// computer classroom
	Component* computerClassroom = new Composite("4. Computer classroom", 0);
	Component* computerDesks = new Composite("a. 10 computer desks", 20000);
	computerDesks->Add(new Leaf("i. A computer on each desk", 0));
	computerDesks->Add(new Leaf("ii. A power outlet near each desk", 3000));
	computerClassroom->Add(computerDesks);
	Component* board = new Composite("b. Board", 19990);
	board->Add(new Leaf("i. A set of colored markers", 200));
	computerClassroom->Add(board);

	computerClassroom->Display(1);
	cout << endl;

	// dining area
	Component* diningRoom = new Composite("5. Dining room", 0);
	diningRoom->Add(new Leaf("1. Coffee machine", 4500));
	Component* table = new Composite("2. Table", 2900);
	table->Add(new Leaf("i. 4 chairs", 12000));
	diningRoom->Add(table);
	diningRoom->Add(new Leaf("3. Refrigerator", 40000));
	diningRoom->Add(new Leaf("4. Sink", 19000));

	diningRoom->Display(1);
	cout << endl;

	cout << "Total sum: " << Component::sum << " UAH" << endl << endl;

	system("pause");
}


