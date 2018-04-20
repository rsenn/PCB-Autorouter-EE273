#include <iostream>
using namespace std;

class Component
{
public:
	int NumberOfPins;
	//int Name[new NumberOfPins];
	int Coordinates[40][40][40];
	virtual void Add();
	virtual void Remove();
	//node getLocation(Name);
};

class Resistor : public Component
{
public:
	int NumberOfPins = 2;
	virtual void PlaceResistor(int Coordinates);
	void Add();
	void Remove();
};

class Capacitor : public Component
{
public:
	int NumberOfPins = 2;
	virtual void PlaceCapictor(int Coordinates);
	void Add();
	void Remove();
};

class Inductor : public Component
{
public:
	int NumberOfPins = 2;
	virtual void PlaceInductor(int Coordinates);
	void Add();
	void Remove();
};

class LED : public Component
{
public:
	int NumberOfPins = 2;
	virtual void PlaceLED(int Coordinates);
	void Add();
	void Remove();
};

class Battery : public Component
{
public:
	int NumberOfPins = 2;
	virtual void PlaceBattery(int Coordinates);
	void Add();
	void Remove();
};

class Transistor : public Component
{
public:
	int NumberOfPins = 3;
	virtual void PlaceTransistor(int Coordinates);
	void Add();
	void Remove();
};

class Diode : public Component
{
public:
	int NumberOfPins = 3;
	virtual void PlaceDiode(int Coordinates);
	void Add();
	void Remove();
};

class Switch : public Component
{
public:
	int NumberOfPins = 3;
	virtual void PlaceSwitch(int Coordinates);
	void Add();
	void Remove();
};

class Operational_Amplifier : public Component
{
public:
	int NumberOfPins = 8;
	virtual void PlaceOpamp(int Coordinates);
	void Add();
	void Remove();
};