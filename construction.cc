#include "construction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{
    fMessenger = new G4GenericMessenger(this,"/detector/", "Detector Construction");

    fMessenger->DeclareProperty("nCols", nCols, "Number of columns");
    fMessenger->DeclareProperty("nRows", nRows, "Number of rows");

    nCols=100;
    nRows=100;

    DefineMaterials();
}

MyDetectorConstruction::~MyDetectorConstruction()
{}

void MyDetectorConstruction::DefineMaterials()
{    
    G4NistManager *nist = G4NistManager::Instance();
    
    worldMat = nist->FindOrBuildMaterial("G4_AIR");
    germanium = nist->FindOrBuildMaterial("G4_Ge");
}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{


    G4double energy[2]={1.239841939*eV/0.9,1.239841939*eV/0.2};
    G4double rindexWorld[2]={1.0,1.0};

    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld,2);
    worldMat->SetMaterialPropertiesTable(mptWorld);
    G4double xWorld = 0.5*m;
    G4double yWorld = 0.5*m;
    G4double zWorld = 0.5*m;

    //G4Box(*name,*size)
    solidWorld = new G4Box("solidWorld",xWorld,yWorld,zWorld);
    solidGermanium = new G4Box("solidGermanium", 0.05*m,0.05*m,0.05*m);
    solidDetector = new G4Box("solidDetector",xWorld/nRows,yWorld/nCols,0.01*m);

    //G4LogicalVolume(*solidVolume,*material,*name)
    logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");
    logicGermanium = new G4LogicalVolume(solidGermanium, germanium, "logicGermanium");    
    logicDetector = new G4LogicalVolume(solidDetector, worldMat,"logicDetector");
    fScoringVolume = logicGermanium;

    //G4PVPlacement(*Rotation,*Offset in Threevector,*logic Volume,*name,*Mothervolume,*boolean operation, *copynumber,*check for overlaps)
    physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),logicWorld,"physWorld",0,false,0,true);
    physGermanium = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.05*m),logicGermanium,"physGermanium",logicWorld,false,0,true);
    for(G4int i=0; i<nRows;i++)
    {
        for(G4int j=0; j<nCols;j++)
        {
            physDetector = new G4PVPlacement(0,G4ThreeVector(-0.5*m+(i+0.5)*m/nRows,-0.5*m+(j+0.5)*m/nCols,0.49*m),logicDetector,"physDetector",logicWorld,false,j+i*nCols,true);
        }
    }

    return physWorld;

}
void MyDetectorConstruction::ConstructSDandField()
{
    MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

    logicDetector->SetSensitiveDetector(sensDet);
}
