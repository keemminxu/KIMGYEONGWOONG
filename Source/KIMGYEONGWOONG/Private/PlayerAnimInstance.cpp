// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "Animation/AnimMontage.h"


// 加傍矫 根鸥林
void UPlayerAnimInstance::PlayAttackMontage()
{

	int num = FMath::RandRange(0,100);
	if (num > 50)
	{
		Montage_Play(attackMontage1);
	}
	else
	{
		Montage_Play(attackMontage2);
	}
	state = EPlayerState::Idle;

}

// 碍傍矫 根鸥林(360)
void UPlayerAnimInstance::PlaySpeicalAttackMontage()
{
	Montage_Play(specialAttackMontage);
	state = EPlayerState::Idle;
}


// 乔拜矫 根鸥林(impact)
void UPlayerAnimInstance::PlayHitMontage()
{
	Montage_Play(damageMontage);
	state = EPlayerState::Idle;
}

// 规绢矫 根鸥林(roll)
void UPlayerAnimInstance::PlayDefenseMontage()
{
	Montage_Play(defenseMontage);
	state = EPlayerState::Idle;
}

// 磷菌阑 版快 根鸥林(death)
void UPlayerAnimInstance::PlayDieMontage()
{
	Montage_Play(dieMontage);
}
