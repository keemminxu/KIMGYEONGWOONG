// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "KIMGYEONGWOONGPlayer.h"
//#include "Components/InputComponent.h"
//#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
//#include "KIMGYEONGWOONG.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bWantsInitializeComponent = true;
}


// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();
}


void UPlayerMove::InitializeComponent()
{
	Super::InitializeComponent();

	me = Cast<AKIMGYEONGWOONGPlayer>(GetOwner());
	if (me)
	{
		//me->OnInputDelegate.AddUObject(this, &UPlayerMove::SetupPlayerInputComponent);

		//me->bUseControllerRotationPitch = true;
		me->GetCharacterMovement()->bOrientRotationToMovement =true;
		me->GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
		me->GetCharacterMovement()->JumpZVelocity = 600.f;
		me->GetCharacterMovement()->AirControl = 0.2f;
		me->GetCharacterMovement()->MaxWalkSpeed = initialWalkSpeed;
	}
	/*bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;*/
}

// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerMove::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &UPlayerMove::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &UPlayerMove::LookUp);
	PlayerInputComponent->BindAction(TEXT("UsePotion"), IE_Pressed, this, &UPlayerMove::UsePotion);
	PlayerInputComponent->BindAction(TEXT("Skill"), IE_Pressed, this, &UPlayerMove::Skill);
}

void UPlayerMove::Horizontal(float value)
{
	if (me->shiftpressing == true)
	{
		me->GetCharacterMovement()->MaxWalkSpeed = fastWalkSpeed;
	}
	else {
		me->GetCharacterMovement()->MaxWalkSpeed = initialWalkSpeed;
	}

	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Vertical(float value)
{
	FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();
	if (me->shiftpressing == true)
	{
		me->GetCharacterMovement()->MaxWalkSpeed = fastWalkSpeed;
	}
	else {
		me->GetCharacterMovement()->MaxWalkSpeed = initialWalkSpeed;
	}
	
	me->AddMovementInput(dir, value);
}

void UPlayerMove::Turn(float value)
{
	me->AddControllerYawInput(value);
}

void UPlayerMove::LookUp(float value)
{
	me->AddControllerPitchInput(value);
}

void UPlayerMove::UsePotion()
{
	
}

void UPlayerMove::Skill()
{

}

