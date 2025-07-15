#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JRPGCharacter.generated.h"

UCLASS()
class YOURGAME_API AJRPGCharacter : public AActor
{
    GENERATED_BODY()

public:
    AJRPGCharacter();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;   //Calls tick to check stats and changes

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 Health;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 MaxHealth;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 Attack;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 Defense;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 Speed;

    virtual void Attack(AJRPGCharacter* Target);

    int32 GetSpeed() const { return Speed; }
};
