// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "Animation/AnimMontage.h"


// �Ӱ��� ��Ÿ��
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

// ������ ��Ÿ��(360)
void UPlayerAnimInstance::PlaySpeicalAttackMontage()
{
	Montage_Play(specialAttackMontage);
	state = EPlayerState::Idle;
}


// �ǰݽ� ��Ÿ��(impact)
void UPlayerAnimInstance::PlayHitMontage()
{
	Montage_Play(damageMontage);
	state = EPlayerState::Idle;
}

// ���� ��Ÿ��(roll)
void UPlayerAnimInstance::PlayDefenseMontage()
{
	Montage_Play(defenseMontage);
	state = EPlayerState::Idle;
}

// �׾��� ��� ��Ÿ��(death)
void UPlayerAnimInstance::PlayDieMontage()
{
	Montage_Play(dieMontage);
}
