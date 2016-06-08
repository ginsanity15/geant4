// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: Em8PrimaryGeneratorMessenger.hh,v 1.1 2000/01/07 14:50:22 grichine Exp $
// GEANT4 tag $Name: geant4-01-01 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef Em8PrimaryGeneratorMessenger_h
#define Em8PrimaryGeneratorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class Em8PrimaryGeneratorAction;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class Em8PrimaryGeneratorMessenger: public G4UImessenger
{
  public:
    Em8PrimaryGeneratorMessenger(Em8PrimaryGeneratorAction*);
   ~Em8PrimaryGeneratorMessenger();
    
    void SetNewValue(G4UIcommand*, G4String);
    
  private:
    Em8PrimaryGeneratorAction* Em8Action; 
    G4UIcmdWithAString*        RndmCmd;
    G4UIcmdWithADoubleAndUnit* setxvertexCmd;
    G4UIcmdWithADoubleAndUnit* setyvertexCmd;
    G4UIcmdWithADoubleAndUnit* setzvertexCmd;
};

#endif
