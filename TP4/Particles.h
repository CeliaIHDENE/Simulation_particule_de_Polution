
#ifndef TD_PARTICLES_H
#define TD_PARTICLES_H
#include <vector>
#include <iostream>
#include <fstream> 
#include <algorithm> 
#include "GasField.h"
#include "UnsteadyGasField.h"
#include <iostream>
using namespace std;

class Particles {

public :
    std::vector<double> x ;
 
    std::vector<double> v  ;
 

    int nbrparticule=200;
    double temps_initial =0.0 ;
    double pos = 0.0 ;
    double posI  ;
    double vitesseInitial =1.0 ;
    double pas =0.2;
    double position[200];
    double DeltaT =0.2 ;
public:

   
    void init(double time){
 try {
    std::cout << "--- init particles ---" << std::endl;
     
    
       v.resize(nbrparticule);
       
  posI=-1 ;
    for(int i=0 ; i<200 ;i++) 
     {  
       x.push_back(posI) ;
       posI= posI +0.0100502513 ;
      
     }
 

 //initialisation des vitesses
   std :: fill ( v. begin( ) , v. end( ) , 1 ) ;
 
  
     
   
    write(temps_initial);  
     
     
     
     
    //on verifie si les vecteurs sont vides  
      if(v.empty()  and x.empty() )
      
         {  throw std::string(" erreur d initialisation "); }
  
 
    
    }//endtry
      catch(std::string const& chaine)
   {
       std::cerr << chaine << std::endl;
   }    
        
        
      
      
  
  
  };
       

  
    void write(double time){
    
    std::string nameP ="particule_position" ;
    std::string nameV ="particule_velocite" ;
    std::string txt = ".txt";
    std::string namefichierP  = nameP +std::to_string(time) + txt  ;
    std::string namefichierV  = nameV +std::to_string(time) + txt  ;


   std::cout << "--- Export particles position at time t = " << time << " in file particles_positions" << std::endl;
    
      std::ofstream fichier {namefichierP};
        for (auto const & xi : x )
        { fichier << xi << std::endl;
        }
        fichier.close() ;
        
   std::cout << "--- Export particles velocities at time t = " << time << " in file particles_velocities" << std::endl; 
         std::ofstream fichier1 {namefichierV};
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
          //   write(time); 
  }
  
  //surcharge 
void computeEvolution(double time, UnsteadyGasField gas_feild )

{
  
 std::cout << "--- compute particle evolution at time : " << time << " ---" << std::endl;
 

    for (int i=0 ; i < nbrparticule ; i++) 
   
   {   v[i] =  gas_feild.velocity( x[i] ) ;} 
 
  
    for (int i=0 ; i < nbrparticule ; i++) 
   
   {   x[i] = x[i] + ( gas_feild.velocity( v[i] ) *DeltaT ) ;  } 
  
  
 

 
   
   
   
 write(time );

 

  
  
  };
  
  

  void print(double time) {
    std::cout << "--- print particle positions at time : " << time << " ---" << std::endl;
            //write(time);
  }
};

#endif // TD_PARTICLES_H
