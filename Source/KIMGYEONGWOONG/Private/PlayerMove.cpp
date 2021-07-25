// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "KIMGYEONGWOONGPlayer.h"
#include "KIMGYEONGWOONG.h"

// Sets default values for this component's properties
UPlayerMove::UPlayerMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bWantsInitializeComponent = true;

	// ...
}


// Called when the game starts
void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();



	// ...
	
}

void UPlayerMove::InitializeComponent()
{
	Super::InitializeComponent();

	me = Cast<AKIMGYEONGWOONGPlayer>(GetOwner());
	if (me)
	{
		//��������Ʈ�� �� �Լ��� ����ϰ� �ʹ�.

		me->OnInputDelegate.AddUObject(this, &UPlayerMove::SetupPlayerInputComponent);
		me->bUseControllerRotationPitch = true;

	}
}


// Called every frame
void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerMove::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &UPlayerMove::Vertical);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &UPlayerMove::Horizontal);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &UPlayerMove::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &UPlayerMove::LookUp);
	

}

void UPlayerMove::Horizontal(float value)
{
	FVector dir = me->GetControlRotation().Quaternion().GetRightVector();

	me->AddMovementInput(dir, value);
}

void UPlayerMove::Vertical(float value)
{
	FVector dir = me->GetControlRotation().Quaternion().GetForwardVector();
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



