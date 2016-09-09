#include "Creational\AbstractFactory\AbstractFactory.h"
#include "Creational\Builder\Builder.h"
#include "Creational\Prototype\Prototype.h"
#include "Creational\SimpleFactory\SimpleFactory.h"
#include "Creational\Singleton\Singleton.h"


#include <iostream> 

using namespace std;
int main(int argc,char* argv[]) 
{
	//////////////////////////////////////////////////////////////////////////
	// Creational
	//////////////////////////////////////////////////////////////////////////

	// AbstractFactory
	AbstractFactory* cf1 = new ConcreteFactory1();
	delete cf1->CreateProductA(); 
	delete cf1->CreateProductB();
	delete cf1;

	AbstractFactory* cf2 = new ConcreteFactory2(); 
	delete cf2->CreateProductA(); 
	delete cf2->CreateProductB();
	delete cf2;

	//Builder
	Director* d = new Director(new ConcreteBuilder());
	d->Construct();
	
	// Prototype
	Prototype* p = new ConcretePrototype();
	Prototype* p1 = p->Clone();
	delete p1;

	// SimpleFactory
	Api* api = Factory::CreateApi(1);
	string str("test");
	api->Operation(str);
	delete api;

	// Singleton
	Singleton* sgn = Singleton::Instance();
	delete sgn;


	// Adapter
	Adaptee* ade = new Adaptee;
	Target* adt = new Adapter(ade);
	adt->Request();
	
	// Bridge
	AbstractionImp* imp = new ConcreteAbstractionImpA();
	Abstraction* abs = new RefinedAbstraction(imp);
	abs->Operation();

	delete abs;

    return 0; 
}