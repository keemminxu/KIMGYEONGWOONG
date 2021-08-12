// Fill out your copyright notice in the Description page of Project Settings.


#include "KIMGYEONGWOONGPlayer.h"
#include "KIMGYEONGWOONG.h"
#include <Camera/CameraComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Components/BoxComponent.h>
#include <Components/SceneComponent.h>
#include "PlayerMove.h"
#include "PlayerAttack.h"
#include "PlayerFSM.h"
#include "PlayerAnimInstance.h"
#include <Engine/SkeletalMesh.h>


// Sets default values
AKIMGYEONGWOONGPlayer::AKIMGYEONGWOONGPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	//ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh2(TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_HeroSword11/SK_Blade_HeroSword11.SK_Blade_HeroSword11'"));

	//if (tempMesh2.Succeeded())
	//{
	//	GetMesh()->SetSkeletalMesh(tempMesh2.Object);
	//}
	
	//childActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActor"));
	//sword = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Sword"));
	//swordCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("SwordCollision"));

	playerMove = CreateDefaultSubobject<UPlayerMove>(TEXT("PlayerMove"));

	playerAttack = CreateDefaultSubobject<UPlayerAttack>(TEXT("PlayerAttack"));

	playerFSM = CreateDefaultSubobject<UPlayerFSM>(TEXT("PlayerFSM"));


	ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh(TEXT("SkeletalMesh'/Game/JWContent/Character/dreyar_m_aure.dreyar_m_aure'"));
	if (tempMesh.Succeeded())
	{
		
		GetMesh()->SetSkeletalMesh(tempMesh.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
		GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	}
	//swordCollision->SetRelativeLocation(FVector(0, 0, 57));
	//swordCollision->SetRelativeScale3D(FVector(0.23f, 0.12f, 1.9f));

	//sword->SetupAttachment(childActor);
	//swordCollision->SetupAttachment(sword);
	//childActor->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("RightHandSocket"));

	//ConstructorHelpers::FObjectFinder<USkeletalMesh> tempMesh2(TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_HeroSword11/SK_Blade_HeroSword11.SK_Blade_HeroSword11'"));

	//if (tempMesh2.Succeeded())
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("SSUCCEEDD"))
	//	sword->SetSkeletalMesh(tempMesh2.Object);
	//	sword->SetRelativeLocation(FVector(36, 72, 0));
	//	sword->SetRelativeScale3D(FVector(7, 7, 7));


	//}


	/*sword->SetupAttachment(childActor);
	swordCollision->SetupAttachment(sword);
	childActor->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, TEXT("RightHandSocket"));*/

	//ConstructorHelpers::FClassFinder<UAnimInstance> tempAnim(TEXT("AnimBlueprint'/Game/GYEONG/Animations/ABP_Player.ABP_Player_C'"));
	//if (tempAnim.Succeeded())
	//{
	//	GetMesh()->SetAnimInstanceClass(tempAnim.Class);
	//}
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

	PlayerInputComponent->BindAction(TEXT("ShiftPressed"), IE_Pressed, this, &AKIMGYEONGWOONGPlayer::ShiftPressed);

	PlayerInputComponent->BindAction(TEXT("ShiftPressed"), IE_Released, this, &AKIMGYEONGWOONGPlayer::ShiftReleased);

	PlayerInputComponent->BindAction(TEXT("UsePotion"), IE_Released, this, &AKIMGYEONGWOONGPlayer::UsePotion);


	playerMove->SetupPlayerInputComponent(PlayerInputComponent);
	playerAttack->SetupPlayerInputComponent(PlayerInputComponent);

	//// 등록된 델리게이트 함수 모조리 실행해 주기
	//OnInputDelegate.Broadcast(PlayerInputComponent);
}

void AKIMGYEONGWOONGPlayer::ShiftPressed()
{
	shiftpressing = true;
	UE_LOG(LogTemp, Warning, TEXT("shiftpressing"));
}

void AKIMGYEONGWOONGPlayer::ShiftReleased()
{
	shiftpressing = false;
	UE_LOG(LogTemp, Warning, TEXT("shiftNOTpressing"));
}

void AKIMGYEONGWOONGPlayer::UsePotion()
{
	HP += 5;
}
