#include "Simulator.h"
#include "SteadySimulator.h"
#include "UnsteadySimulator.h"
#include <ctype.h> 

enum class SimulationType {SteadyState, UnsteadyState};
	using namespace std;

Simulator* createSimulator(SimulationType simulation_type) {
 //std::unique_ptr<Simulator>
    Simulator* simulator = nullptr;


  
  switch (simulation_type)
  {
  case SimulationType::SteadyState:
    simulator = new SteadySimulator{};

  // unique_ptr<simulator> make_unique( );

    break;
  case SimulationType::UnsteadyState:
    simulator = new UnsteadySimulator{};
    break;
  }
  return simulator;
}



int main(int argc, char **argv){
 	
 	 int choix = *argv[1] ;
 	
  
  switch (choix )
  {
  case 1 : {
auto simulation_type = SimulationType::SteadyState;
 Simulator* simulator = createSimulator(simulation_type);
  simulator->compute();
 
 
    break;}
  case 2 :
  {
 auto simulation_type = SimulationType:: UnsteadyState ;
  Simulator* simulator = createSimulator(simulation_type);
  simulator->compute();
 
     break; }
  }
  

 
 

 



};
