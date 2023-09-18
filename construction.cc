#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();
    G4Material * worldMat = nist->FindOrBuildMaterial("G4_AIR");
    G4Material * germaniumDetector = nist->FindOrBuildMaterial("G4_Ge");

    G4double energy[2]={1.239841939*eV/0.9,1.239841939*eV/0.2};
    G4double rindexWorld[2]={1.0,1.0};

    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld,2);
    worldMat->SetMaterialPropertiesTable(mptWorld);

    //G4Box(*name,*size)
    G4Box *solidWorld = new G4Box("solidWorld",0.5*m,0.5*m,0.5*m);
    G4Box *solidGermanium = new G4Box("solidGermanium", 0.05*m,0.05*m,0.05*m);
    G4Box *solidDetector = new G4Box("solidDetector",0.005*m,0.005*m,0.01*m);

    //G4LogicalVolume(*solidVolume,*material,*name)
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    G4LogicalVolume *logicGermanium = new G4LogicalVolume(solidGermanium, germaniumDetector, "logicGermanium");    
    logicDetector = new G4LogicalVolume(solidDetector, worldMat,"logicDetector");

    //G4PVPlacement(*Rotation,*Offset in Threevector,*logic Volume,*name,*Mothervolume,*boolean operation, *copynumber,*check for overlaps)
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),logicWorld,"physWorld",0,false,0,true);
    G4VPhysicalVolume *physGermanium = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.05*m),logicGermanium,"physGermanium",logicWorld,false,0,true);
    for(G4int i=0; i<100;i++)
    {
        for(G4int j=0; j<100;j++)
        {
            G4VPhysicalVolume *physDetector = new G4PVPlacement(0,G4ThreeVector(-0.5*m+(i+0.5)*m/100,-0.5*m+(j+0.5)*m/100,0.49*m),logicDetector,"physDetector",logicWorld,false,j+i*100,true);
        }
    }

    return physWorld;

}
void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

    logicDetector->SetSensitiveDetector(sensDet);
}
