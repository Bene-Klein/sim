#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh" 
#include "G4GenericMessenger.hh"

#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public: 
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }

    virtual G4VPhysicalVolume *Construct();
private: 
    virtual void ConstructSDandField();

    G4int nCols, nRows;

    G4Box *solidWorld, *solidGermanium, *solidDetector;
    G4LogicalVolume *logicWorld, *logicGermanium, *logicDetector;
    G4VPhysicalVolume *physWorld, *physGermanium, *physDetector;

    G4Material *worldMat, *germanium;
    G4GenericMessenger *fMessenger;

    void DefineMaterials();

    G4LogicalVolume *fScoringVolume;

    //G4int nRows, nCols;
};
#endif
