// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerAttack.h"
#include "KIMGYEONGWOONGPlayer.h"

// Sets default values for this component's properties
UPlayerAttack::UPlayerAttack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	bWantsInitializeComponent = true;

}


// Called when the game starts
void UPlayerAttack::BeginPlay()
{
	Super::BeginPlay();

}


void UPlayerAttack::InitializeComponent()
{
	Super::InitializeComponent();

	me = Cast<AKIMGYEONGWOONGPlayer>(GetOwner());

}

// Called every frame
void UPlayerAttack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerAttack::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Attack"), IE_Pressed, this, &UPlayerAttack::Attack);
	PlayerInputComponent->BindAction(TEXT("SpecialAttack"), IE_Pressed, this, &UPlayerAttack::SpecialAttack);
	PlayerInputComponent->BindAction(TEXT("Roll"), IE_Pressed, this, &UPlayerAttack::Avoid);
	
}

void UPlayerAttack::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("Attack"));
	if (me->isAttacking ==false)
	{
		me->isAttacking = true;
	}
}

void UPlayerAttack::SpecialAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("SpecialAttack"));
	if (me->isAttacking == false)
	{
		me->isAttacking = true;
	}
}

void UPlayerAttack::Avoid()
{
	UE_LOG(LogTemp, Warning, TEXT("Avoid"));
	if (me->isAvoiding == false)
	{
		me->isAvoiding = true;
	}
}

