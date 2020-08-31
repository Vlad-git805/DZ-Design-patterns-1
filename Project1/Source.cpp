#include<iostream>
#include <string>

using namespace std;

class Car
{
public:

	string Body_assembl;
	string Engine_installation;
	string Installation_of_wheels;
	string paint;
	string Salon_preparation;

	void Show() const
	{
		cout << "Body assembl: " << Body_assembl << endl;
		cout << "Engine installation: " << Engine_installation << endl;
		cout << "Installation of wheels: " << Installation_of_wheels << endl;
		cout << "Paint: " << paint << endl;
		cout << "Salon preparation: " << Salon_preparation << endl;
	}

};

class AutoTechnology
{
protected:

	Car* car;

public:
	void Create_car()
	{
		car = new Car();
	}

	Car* Get_car() const
	{
		return car;
	}

	virtual void BuildBody() = 0;
	virtual void InstallEngine() = 0;
	virtual void InstallWheels() = 0;
	virtual void Paint() = 0;
	virtual void PrepareSalon() = 0;
};


class SportCarTechnology : public  AutoTechnology
{
	void BuildBody()
	{
		car->Body_assembl = "SportCarBody_assembl";
	}
	void InstallEngine()
	{
		car->Engine_installation = "SportCarEngine_installation";
	}
	void InstallWheels()
	{
		car->Installation_of_wheels = "SportCarInstallation_of_wheels";
	}
	void Paint()
	{
		car->paint = "SportCarPaint";

	}
	void PrepareSalon()
	{
		car->Salon_preparation = "SportCarSalon_preparation";
	}
};



class MiniAutoTechnology : public  AutoTechnology
{
	void BuildBody()
	{
		car->Body_assembl = "MiniCarBody_assembl";
	}
	void InstallEngine()
	{
		car->Engine_installation = "MiniCarEngine_installation";
	}
	void InstallWheels()
	{
		car->Installation_of_wheels = "MiniCarInstallation_of_wheels";
	}
	void Paint()
	{
		car->paint = "MiniCarPaint";

	}
	void PrepareSalon()
	{
		car->Salon_preparation = "MiniCarSalon_preparation";
	}
};


class SUVAutoTechnology : public  AutoTechnology
{

	void BuildBody()
	{
		car->Body_assembl = "SUVCarBody_assembl";
	}
	void InstallEngine()
	{
		car->Engine_installation = "SUVCarEngine_installation";
	}
	void InstallWheels()
	{
		car->Installation_of_wheels = "SUVCarInstallation_of_wheels";
	}
	void Paint()
	{
		car->paint = "SUVCarPaint";

	}
	void PrepareSalon()
	{
		car->Salon_preparation = "SUVCarSalon_preparation";
	}
};

class Conveyor
{
private:

	AutoTechnology* ModelTehnology;

public:
	void SetTehnology(AutoTechnology* build)
	{
		this->ModelTehnology = build;
	}
	Car* Getcar() const
	{
		return ModelTehnology->Get_car();
	}
	void Configurate()
	{

		ModelTehnology->Create_car();
		ModelTehnology->BuildBody();
		ModelTehnology->InstallEngine();
		ModelTehnology->InstallWheels();
		ModelTehnology->Paint();
		ModelTehnology->PrepareSalon();
	}
};


int main()
{

	Conveyor d1;
	d1.SetTehnology(new  SportCarTechnology());
	d1.Configurate();

	Car* car = d1.Getcar();

	car->Show();

}