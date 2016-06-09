//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: Pers01PrimaryGeneratorAction.hh,v 1.1 2002/12/04 02:44:25 morita Exp $
// GEANT4 tag $Name: geant4-05-02-patch-01 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef Pers01PrimaryGeneratorAction_h
#define Pers01PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class Pers01DetectorConstruction;
class Pers01PrimaryGeneratorMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class Pers01PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    Pers01PrimaryGeneratorAction(Pers01DetectorConstruction*);    
   ~Pers01PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event*);
    void SetRndmFlag(G4String val) { rndmFlag = val;}

  private:
    G4ParticleGun*                particleGun;	  //pointer a to G4  class
    Pers01DetectorConstruction*    Pers01Detector;  //pointer to the geometry
    
    Pers01PrimaryGeneratorMessenger* gunMessenger; //messenger of this class
    G4String                      rndmFlag;	  //flag for a rndm impact point
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

