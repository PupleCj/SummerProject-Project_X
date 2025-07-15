#include "MyGameMode.h"
#include "MyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyGameMode::AMyGameMode()
{
    //set default pawn class to custom character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_MyCharacter"));
    DefaultPawnClass = PlayerPawnClassFinder.Class;
}
