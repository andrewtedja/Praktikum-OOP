#include "Agent.hpp"
#include "SuperAgent.hpp"

int main()
{
    SuperAgent agentX;
    // Start editing here :D
    Agent *ptrAgent = &agentX;
    ptrAgent->setID(1337);
    agentX.setID(9999);
    agentX.print();
    return 0;
}