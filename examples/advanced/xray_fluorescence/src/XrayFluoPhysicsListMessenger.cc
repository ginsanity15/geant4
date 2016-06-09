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
// $Id: XrayFluoPhysicsListMessenger.cc
// GEANT4 tag $Name: xray_fluo-V04-01-03
//
// Author: Elena Guardincerri (Elena.Guardincerri@ge.infn.it)
//
// History:
// -----------
// 28 Nov 2001 Elena Guardincerri     Created
//
// -------------------------------------------------------------------

#include "XrayFluoPhysicsListMessenger.hh"
#include "XrayFluoPhysicsList.hh"

#include "G4UIdirectory.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

XrayFluoPhysicsListMessenger::XrayFluoPhysicsListMessenger(XrayFluoPhysicsList * List)
:XrayFluoList(List)
{

  lowEnDir = new G4UIdirectory("/lowenergy/");
  lowEnDir->SetGuidance("LowEnergy commands");

  cutSecPhotCmd = new G4UIcmdWithADoubleAndUnit("/lowenergy/secphotcut",this);
  cutSecPhotCmd->SetGuidance("Set production threshold for secondary Gamma.");
  cutSecPhotCmd->SetParameterName("energy",true);
  cutSecPhotCmd->SetDefaultValue(5e-5);
  cutSecPhotCmd->SetDefaultUnit("MeV");
  cutSecPhotCmd->AvailableForStates(G4State_Idle);

  cutSecElecCmd = new G4UIcmdWithADoubleAndUnit("/lowenergy/seceleccut",this);
  cutSecElecCmd->SetGuidance("Set production threshold for secondary e-");
  cutSecElecCmd->SetParameterName("energy",true);
  cutSecElecCmd->SetDefaultValue(5e-5);
  cutSecElecCmd->SetDefaultUnit("MeV");
  cutSecElecCmd->AvailableForStates(G4State_Idle);

  cutGCmd = new G4UIcmdWithADoubleAndUnit("/lowenergy/cutG",this);
  cutGCmd->SetGuidance("Set cut values by RANGE for Gamma.");
  cutGCmd->SetParameterName("range",true);
  cutGCmd->SetDefaultValue(1.);
  cutGCmd->SetDefaultUnit("mm");
  cutGCmd->AvailableForStates(G4State_Idle);

  cutECmd = new G4UIcmdWithADoubleAndUnit("/lowenergy/cutE",this);
  cutECmd->SetGuidance("Set cut values by RANGE for e-.");
  cutECmd->SetParameterName("range",true);
  cutECmd->SetDefaultValue(1.);
  cutECmd->SetDefaultUnit("mm");
  cutECmd->AvailableForStates(G4State_Idle);

  cutPCmd = new G4UIcmdWithADoubleAndUnit("/lowenergy/cutP",this);
  cutPCmd->SetGuidance("Set cut values by RANGE for proton and others.");
  cutPCmd->SetParameterName("cutP",false);
  cutPCmd->SetRange("cutP>0.");
  cutPCmd->SetUnitCategory("Length");    
  cutPCmd->AvailableForStates(G4State_Idle);
 
  eCmd = new G4UIcmdWithADoubleAndUnit("/lowenergy/cutEnergy",this);
  eCmd->SetGuidance("Set cut values by ENERGY for charged particles.");
  eCmd->SetParameterName("cutenergy",false);
  eCmd->SetRange("cutenergy>0.");
  eCmd->SetUnitCategory("Energy");   
  eCmd->AvailableForStates(G4State_Idle);

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

XrayFluoPhysicsListMessenger::~XrayFluoPhysicsListMessenger()
{
  delete cutSecElecCmd;
  delete cutSecPhotCmd;
  delete cutGCmd;
  delete cutECmd;
  delete cutPCmd;
  delete eCmd;

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
  
void XrayFluoPhysicsListMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{
  if(command == cutSecPhotCmd)
    { XrayFluoList->SetLowEnSecPhotCut(cutSecPhotCmd->GetNewDoubleValue(newValue));}

  if(command == cutSecElecCmd)
    { XrayFluoList->SetLowEnSecElecCut(cutSecElecCmd->GetNewDoubleValue(newValue));}

  if(command == cutGCmd)
    { XrayFluoList->SetGammaCut(cutGCmd->GetNewDoubleValue(newValue));}

  if(command == cutECmd)
    { XrayFluoList->SetElectronCut(cutECmd->GetNewDoubleValue(newValue));}

 if(command == cutPCmd)
    { XrayFluoList->SetProtonCut(cutPCmd->GetNewDoubleValue(newValue));}

 if(command == eCmd)
    { XrayFluoList->SetCutsByEnergy(eCmd->GetNewDoubleValue(newValue));}

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....





