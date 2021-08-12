// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerFSM.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class KIMGYEONGWOONG_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FSM)
		bool attacking = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FSM)
		bool specialattacking = false;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FSM)
		bool isMoving = false;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadWrite)
		EPlayerState state;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadOnly)
		class UAnimMontage* attackMontage1;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadOnly)
		class UAnimMontage* attackMontage2;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadOnly)
		class UAnimMontage* specialAttackMontage;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadOnly)
		class UAnimMontage* damageMontage;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadOnly)
		class UAnimMontage* defenseMontage;

	UPROPERTY(EditAnywhere, Category = FSM, BlueprintReadOnly)
		class UAnimMontage* dieMontage;


	void PlayAttackMontage();
	void PlaySpeicalAttackMontage();
	void PlayHitMontage();
	void PlayDefenseMontage();
	void PlayDieMontage();

	//// 노티파이 이벤트 호출될때 처리할 함수
	//UFUNCTION(BlueprintCallable, Category = FSM)
	//	void OnNotifyTest();

	//// 몽타주 끝났을 때 호출될 이벤트 함수
	//UFUNCTION()
	//	void OnDieMontageEnded(UAnimMontage* animMontage, bool isEnd);
};
