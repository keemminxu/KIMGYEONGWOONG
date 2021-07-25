// Fill out your copyright notice in the Description page of Project Settings.


#include "KIMGYEONGWOONGPlayer.h"
#include "KIMGYEONGWOONG.h"
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include "PlayerMove.h"



// Sets default values
AKIMGYEONGWOONGPlayer::AKIMGYEONGWOONGPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
	fpsCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	fpsCamera->SetupAttachment(GetCapsuleComponent());


	bodyMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BodyMesh"));
	bodyMesh->SetupAttachment(fpsCamera);

	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));

	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("SkeletalMesh'/Game/JWContent/Character/dreyar_m_aure.dreyar_m_aure'"));

	if (tempMesh.Succeeded())
	{
		bodyMesh->SetSkeletalMesh(tempMesh.Object);
	}


}

// Called when the game starts or when spawned
void AKIMGYEONGWOONGPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKIMGYEONGWOONGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKIMGYEONGWOONGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	OnInputDelegate.Broadcast(PlayerInputComponent);


}

