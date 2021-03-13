
#ifndef TD_PARTICLES_H
#define TD_PARTICLES_H
#include <vector>
#include <iostream>
#include <fstream> 
#include <algorithm> 
#include "GasField.h"
class Particles {

public :
    std::vector<double> x ;
 
    std::vector<double> v ;

    double nbrparticule =200;
    double temps_initial =0.0 ;
    double pos = 0.0 ;
    double vitesseInitial = 1 ;
public:

  void init(double time){
 try {
    std::cout << "--- init particles ---" << std::endl;
    
       x.resize(nbrparticule);
       v.resize(nbrparticule);
       


    std :: fill ( x. begin( ) , x. end() , pos ) ;
 
        
   std :: fill ( v. begin( ) , v. end( ) , vitesseInitial ) ;
  
     
     
      if(v.empty()  and x.empty() )
      
         {  throw std::string(" erreur d initialisation "); }
  
 
    
    }//endtry
      catch(std::string const& chaine)
   {
       std::cerr << chaine << std::endl;
   }    
        
        
      
      
  
  
  };
  
  
  
    void write(double time){

    std::cout << "--- Export particles position at time t = " << time << " in file particles_positions" << std::endl;
    
      std::ofstream fichier {"particule_position.txt"};
        for (auto const & xi : x )
        { fichier << xi << std::endl;
        }
        fichier.close() ;
        
    std::cout << "--- Export particles velocities at time t = " << time << " in file particles_velocities" << std::endl; 
         std::ofstream fichier1 {"particule_velocite.txt"};
        for (auto const & vi :v )
        { fichier1 << vi << std::endl;
        }
        
          fichier1.close() ;
    
 
     }
  void computeEvolution(double time) {
   GasField::gas air ;
 
  
    std::cout << "--- compute particle evolution at time : " << time << " ---" << std::endl;
    
    std::fill(v.begin(),v.end(),air.vitesseAir );
    
     pos =  pos + (   air.vitesseAir * (time-temps_initial) ) ;
       
        std::fill(x.begin(),x.end(),pos );
           write(time);
  }
  
  


  void print(double time) {
    std::cout << "--- print particle positions at time : " << time << " ---" << std::endl;
             
  }
};

#endif // TD_PARTICLES_H
