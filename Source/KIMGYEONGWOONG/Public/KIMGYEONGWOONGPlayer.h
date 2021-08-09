// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KIMGYEONGWOONGPlayer.generated.h"

//
//DECLARE_MULTICAST_DELEGATE_OneParam(FPlayerInputDelegate, class UInputComponent*);


UCLASS(config=GamePlayer)
class KIMGYEONGWOONG_API AKIMGYEONGWOONGPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKIMGYEONGWOONGPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	// Called to bind functionality to input

public:
	UPROPERTY(EditAnywhere, Category = BodyMesh)
		class USkeletalMeshComponent* bodyMesh;

	//UPROPERTY(EditAnywhere, Category = ChildActor)
	//	class FName* righthandSocket;
	
	UPROPERTY(EditAnywhere, Category=ChildActor)
		class UChildActorComponent* childActor;

	UPROPERTY(EditAnywhere, Category=Sword)
		class USkeletalMeshComponent* sword;

	UPROPERTY(EditAnywhere, Category=Collision)
		class UBoxComponent* swordCollision;

	UPROPERTY(VisibleAnywhere, Category=PlayerMove)
		class UPlayerMove* playerMove;

	UPROPERTY(VisibleAnywhere, Category = PlayerAttack)
		class UPlayerAttack* playerAttack;

	//// 사용자 입력처리를 담당할 델리게이트
	//FPlayerInputDelegate OnInputDelegate;

public:
	// FSM transition 조건으로 쓸 것들, input과 맵핑됨
	// SHIFT키 누르고 있는지
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool shiftpressing = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerBehavior)
		bool isAttacking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerBehavior)
		bool isAvoiding = false;

	void ShiftPressed();
	void ShiftReleased();

	// HP, MP, Toxicity
	UPROPERTY(EditAnywhere, Category = Stats)
		float HP = 100.0f;
	UPROPERTY(EditAnywhere, Category = Stats)
		float MP = 100.0f;
	UPROPERTY(EditAnywhere, Category = Stats)
		float Stamina = 50.0f;

	// 상태머신
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FSM)
		class UPlayerFSM* playerFSM;

};
