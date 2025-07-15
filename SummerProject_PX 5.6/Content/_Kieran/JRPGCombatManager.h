#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JRPGCharacter.h"
#include "JRPGCombatManager.generated.h"

UCLASS()
class YOURGAME_API AJRPGCombatManager : public AActor
{
    GENERATED_BODY()

public:
    AJRPGCombatManager();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;   //creates turn based combat

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    TArray<AJRPGCharacter*> PlayerCharacters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    TArray<AJRPGCharacter*> EnemyCharacters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
    TArray<AJRPGCharacter*> TurnOrder;

    int32 CurrentTurnIndex;

    void StartCombat();  //start combat (for testing)
    void EndCombat();    //end combat (for testing)
    void HandleTurn();    //automates turn cycling
    bool IsCombatOver();  //checks game over conditions
    void DetermineTurnOrder();  //determines player/AI turn 
};
