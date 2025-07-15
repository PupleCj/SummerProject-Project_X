#include "JRPGCharacter.h"

AJRPGCharacter::AJRPGCharacter()
{
    PrimaryActorTick.bCanEverTick = true;   //sets stats for gameplay

    Health = 100;
    MaxHealth = 100;
    Attack = 10;
    Defense = 5;
    Speed = 10;
}

void AJRPGCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AJRPGCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AJRPGCharacter::Attack(AJRPGCharacter* Target)
{
    if (Target)
    {
        int32 Damage = FMath::Max(0, Attack - Target->Defense);    //checks for game over conditions
        Target->Health = FMath::Max(0, Target->Health - Damage);
    }
}
