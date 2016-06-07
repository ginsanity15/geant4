// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4LETritonInelastic.hh,v 2.1 1998/07/13 17:34:08 fjones Exp $
// GEANT4 tag $Name: geant4-00 $
//
 // Hadronic Process: Low Energy Triton Inelastic Process
 // J.L. Chuma, TRIUMF, 25-Feb-1997
 // Last modified: 27-Mar-1997
 
#ifndef G4LETritonInelastic_h
#define G4LETritonInelastic_h 1
 
#include "G4InelasticInteraction.hh"
 
 class G4LETritonInelastic : public G4InelasticInteraction
 {
 public:
    
    G4LETritonInelastic() : G4InelasticInteraction()
    {
      SetMinEnergy( 0.0 );
      // SetMaxEnergy( 100.*MeV );  // NUCREC only worked for energies < 100MeV
      // Work around to avoid exception in G4EnergyRangeManager
      SetMaxEnergy( 10.*TeV );  // NUCREC only worked for energies < 100MeV
    }
    
    ~G4LETritonInelastic() { }
    
    G4VParticleChange *ApplyYourself( const G4Track &aTrack,
                                      G4Nucleus &targetNucleus );
 };
 
#endif
 