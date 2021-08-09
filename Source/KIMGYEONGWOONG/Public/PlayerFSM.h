// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerAnimInstance.h"
#include "PlayerFSM.generated.h"

// 사용할 상태 정의
UENUM(BlueprintType)
enum class EPlayerState : uint8
{
	Idle UMETA(DisplayName = "IDLE_STATE"),
	Move UMETA(DisplayName = "MOVE_STATE"),
	Attack UMETA(DisplayName = "ATTACK_STATE"),
	SpecialAttack UMETA(DisplayName = "SPECIALATTACK_STATE"),
	Avoid UMETA(DisplayName="AVOID_STATE"),
	Damage UMETA(DisplayName = "DAMAGE_STATE"),
	Die UMETA(DisplayName = "DIE_STATE")
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KIMGYEONGWOONG_API UPlayerFSM : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerFSM();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY()
		class AKIMGYEONGWOONGPlayer* me;

	UPROPERTY(EditAnywhere, Category=FSM, BlueprintReadWrite)
	EPlayerState m_state;


	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadWrite)
		float playerVelocity = 0;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadWrite)
		bool isShiftPressed = false;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadWrite)
		bool isPlayerAttacking = false;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadWrite)
		bool isPlayerAvoiding = false;

	UPROPERTY()
		class UPlayerAnimInstance* anim;

	void IdleState();
	void MoveState();
	void AttackState();
	void SpecialAttackState();
	void AvoidState();
	void DamageState();
	void DieState();

	// 피격시 처리
	void OnDamageProcess();
};
