//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: G4PSTrackLength.hh,v 1.5 2007/05/18 00:00:37 asaim Exp $
// GEANT4 tag $Name: geant4-09-00 $
//

#ifndef G4PSTrackLength_h
#define G4PSTrackLength_h 1

#include "G4VPrimitiveScorer.hh"
#include "G4THitsMap.hh"

////////////////////////////////////////////////////////////////////////////////
// (Description)
//   This is a primitive scorer class for scoring track length.
// 
//
// Created: 2005-11-14  Tsukasa ASO, Akinori Kimura.
// Modified: 2007-02-02 Tsukasa ASO, Add MultiolyKineticEnergy() 
//                                  and DivideByVelocity(). 
//
// 
///////////////////////////////////////////////////////////////////////////////

class G4PSTrackLength : public G4VPrimitiveScorer
{
 
 public: // with description
      G4PSTrackLength(G4String name, G4int depth=0);
      virtual ~G4PSTrackLength();

      inline void Weighted(G4bool flg=true) { weighted = flg; }
      // Multiply track weight

      inline void MultiplyKineticEnergy(G4bool flg=true) { multiplyKinE = flg; }
      // Multiply Kinetic Energy

      inline void DivideByVelocity(G4bool flg=true) { divideByVelocity = flg; }
      // Divide by velocity


  protected: // with description
      virtual G4bool ProcessHits(G4Step*,G4TouchableHistory*);

  public: 
      virtual void Initialize(G4HCofThisEvent*);
      virtual void EndOfEvent(G4HCofThisEvent*);
      virtual void clear();
      virtual void DrawAll();
      virtual void PrintAll();

  private:
      G4int HCID;
      G4THitsMap<G4double>* EvtMap;
      G4bool weighted;
      G4bool multiplyKinE;
      G4bool divideByVelocity;
};
#endif