#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

AMyCharacter::AMyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    BaseTurnRate = 45.f;
    BaseLookUpRate = 45.f;
    WalkSpeed = 600.f;
    SprintSpeed = 1200.f;

    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;

    USpringArmComponent* CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 300.0f;
    CameraBoom->bUsePawnControlRotation = true;

    UCameraComponent* FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
    FollowCamera->bUsePawnControlRotation = false;

    CharacterState = ECharacterState::ECS_Exploration;
}

void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (CharacterState == ECharacterState::ECS_Combat)
    {
        // Handle combat logic
    }
    else if (CharacterState == ECharacterState::ECS_Exploration)
    {
        // Handle exploration logic
    }
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
    PlayerInputComponent->BindAxis("TurnRate", this, &AMyCharacter::TurnAtRate);
    PlayerInputComponent->BindAxis("LookUpRate", this, &AMyCharacter::LookUpAtRate);

    PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::StartSprinting);
    PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AMyCharacter::StopSprinting);

    PlayerInputComponent->BindAction("StartCombat", IE_Pressed, this, &AMyCharacter::StartCombat);
    PlayerInputComponent->BindAction("EndCombat", IE_Pressed, this, &AMyCharacter::EndCombat);
    PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyCharacter::Attack);
}

void AMyCharacter::MoveForward(float Value)
{
    if (CharacterState == ECharacterState::ECS_Exploration && Value != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void AMyCharacter::MoveRight(float Value)
{
    if (CharacterState == ECharacterState::ECS_Exploration && Value != 0.0f)
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void AMyCharacter::TurnAtRate(float Rate)
{
    AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::LookUpAtRate(float Rate)
{
    AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMyCharacter::StartSprinting()
{
    GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AMyCharacter::StopSprinting()
{
    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AMyCharacter::StartCombat()
{
    SwitchToCombatMode();
}

void AMyCharacter::EndCombat()
{
    SwitchToExplorationMode();
}

void AMyCharacter::Attack()
{
    if (CharacterState == ECharacterState::ECS_Combat)
    {
        //implement attack logic here
    }
}

void AMyCharacter::SwitchToCombatMode()
{
    CharacterState = ECharacterState::ECS_Combat;
    GetCharacterMovement()->DisableMovement();
    //additional logic for entering combat mode
}

void AMyCharacter::SwitchToExplorationMode()
{
    CharacterState = ECharacterState::ECS_Exploration;
    GetCharacterMovement()->SetMovementMode(MOVE_Walking);
    //additional logic for exiting combat mode
}
