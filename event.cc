#include "event.hh"


MyEventAction::MyEventAction(MyRunAction*)
{
    fEdep = 0.;
}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{
    fEdep = 0.;
}

void MyEventAction::EndOfEventAction(const G4Event*)
{
    //G4cout << "Energy depostion: " << fEdep << G4endl;

    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->FillNtupleDColumn(1,0,fEdep); //FillNtupleDColumn(Ntuple Number, Entry Number, Entry)

    man->AddNtupleRow(1);
}
