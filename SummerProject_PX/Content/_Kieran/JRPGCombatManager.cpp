#include "JRPGCombatManager.h"
#include "JRPGCharacter.h"

AJRPGCombatManager::AJRPGCombatManager()
{
    PrimaryActorTick.bCanEverTick = true;
    CurrentTurnIndex = 0;
}

void AJRPGCombatManager::BeginPlay()
{
    Super::BeginPlay();
    DetermineTurnOrder();
}

void AJRPGCombatManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!IsCombatOver())
    {
        HandleTurn();
    }
}

void AJRPGCombatManager::StartCombat()
{
    //initialize combat here
    DetermineTurnOrder();
}

void AJRPGCombatManager::EndCombat()
{
    //cleanup after combat
}

void AJRPGCombatManager::HandleTurn()
{
    if (CurrentCharacter)
    {
        //handle the current character's turn
        // ...

        //move to the next character's turn
        CurrentTurnIndex = (CurrentTurnIndex + 1) % (PlayerCharacters.Num() + EnemyCharacters.Num());
        CurrentCharacter = (CurrentTurnIndex < PlayerCharacters.Num()) ? PlayerCharacters[CurrentTurnIndex] : EnemyCharacters[CurrentTurnIndex - PlayerCharacters.Num()];
    }
}

void AJRPGCombatManager::DetermineTurnOrder()
{
    //determine the turn order based on character speed or other stats
    
}

bool AJRPGCombatManager::IsCombatOver()
{
    //check if all enemies or all players are defeated
    return EnemyCharacters.Num() == 0 || PlayerCharacters.Num() == 0;
}
