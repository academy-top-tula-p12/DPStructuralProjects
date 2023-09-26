#include <iostream>

//#include "Adapter.h"
//void AdapterExample()
//{
//    Client* client = new Client();
//    client->ClientMethod();
//}

//#include "BridgeImplementation.h"
//void BridgeExample()
//{
//    StrategyGame* game = new StrategyGame(new KeyboradImplementation());
//
//    game->Setup();
//    game->Process();
//
//    std::cout << "game over\n";
//}

#include "Composite.h"
void CompositeExample()
{
    srand(time(nullptr));
    std::vector<UnitFactory*> factories;
    factories.push_back(new InfantryFactory());
    factories.push_back(new ArcherFactory());
    factories.push_back(new CavalryFactory());

    Unit* legion1 = new GroupUnit("Legion 1");
    for (int i = 0; i < 10; i++)
    {
        auto unit = factories[rand() % factories.size()]->Create();
        ((GroupUnit*)legion1)->Add(unit);
        ((GroupUnit*)legion1)->Add(new InfantryUnit());
    }

    Unit* legion2 = new GroupUnit("Legion 2");
    for (int i = 0; i < 5; i++)
    {
        auto unit = factories[rand() % factories.size()]->Create();
        ((GroupUnit*)legion2)->Add(unit);
    }

    Unit* falanga1 = new GroupUnit("Falanga 1");
    for (int i = 0; i < 5; i++)
    {
        auto unit = factories[rand() % factories.size()]->Create();
        ((GroupUnit*)falanga1)->Add(unit);
    }

    ((GroupUnit*)legion2)->Add(falanga1);

    Unit* army = new GroupUnit("Army");
    ((GroupUnit*)army)->Add(legion1);
    ((GroupUnit*)army)->Add(legion2);
    ((GroupUnit*)army)->Add(new InfantryUnit());

    std::cout << legion1->ToString() << "\n\n";
    std::cout << army->ToString() << "\n\n";

}

int main()
{
    //AdapterExample();
    //BridgeExample();
    
    CompositeExample();
}
