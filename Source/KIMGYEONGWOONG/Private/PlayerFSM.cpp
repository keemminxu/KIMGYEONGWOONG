// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFSM.h"
#include "KIMGYEONGWOONGPlayer.h"
#include "GameFramework/Character.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.h"

// Sets default values for this component's properties
UPlayerFSM::UPlayerFSM()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPlayerFSM::BeginPlay()
{
	Super::BeginPlay();
	me = Cast<AKIMGYEONGWOONGPlayer>(GetOwner());
	if (me)
	{
		//playerVelocity = me->GetVelocity().Size();
		isShiftPressed = me->shiftpressing;
		isPlayerAttacking = me->isAttacking;
		isPlayerAvoiding = me->isAvoiding;
	}

	USkeletalMeshComponent* mesh = me->GetMesh();
	UAnimInstance* anim_instance = mesh->GetAnimInstance();

	anim = Cast<UPlayerAnimInstance>(anim_instance);

	m_state = EPlayerState::Idle;
	if (anim)
	{
		anim->state = m_state;
	}
}


// Called every frame
void UPlayerFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	playerVelocity = me->GetVelocity().Size();
	//UE_LOG(LogTemp, Warning, TEXT("playerVelocity: %f"), playerVelocity);
	//UE_LOG(LogTemp, Warning, TEXT("state: %d"), m_state);

	switch (m_state)
	{
	case EPlayerState::Idle:
		IdleState();
		break;
	case EPlayerState::Move:
		MoveState();
		break;
	case EPlayerState::Attack:
		AttackState();
		break;
	case EPlayerState::SpecialAttack:
		SpecialAttackState();
		break;
	case EPlayerState::Avoid:
		AvoidState();
		break;
	case EPlayerState::Damage:
		DamageState();
		break;
	case EPlayerState::Die:
		DieState();
		break;
	}
}

void UPlayerFSM::IdleState()
{
	anim->state = m_state;
	//UE_LOG(LogTemp, Warning, TEXT("IDLESTATE: %d"), m_state);
	//UE_LOG(LogTemp, Warning, TEXT("IDLEANIMSTATE: %d"), anim->state);
// Idle to Move : 플레이어 속도가 0 이상이면 상태 Move로 전환

	if (playerVelocity >= 50)
	{
		//UE_LOG(LogTemp, Warning, TEXT("VELOCITY UU"))
		m_state = EPlayerState::Move;
	}
// Idle to Attack : 가만히 공격하는 경우 Attack 
	//else if (me->isAttacking == true) // nullptr
	else
	{
		if (me->isAttacking == true)
		{
		// Idle to SpecialAttack : 강공
			if (isShiftPressed == true)
			{
				m_state = EPlayerState::SpecialAttack;
				//anim->state = m_state;
			}
			m_state = EPlayerState::Attack;
			//anim->state = m_state;
		}
//// Idle to Damage : 공격을 받으면
//	else if ()
//	{
//	}
// Idle to Avoid : 공격을 막으면
// else if (me->isAvoiding == true) // nullptr
		else if (me->isAvoiding == true)
		{
			m_state = EPlayerState::Avoid;
			//anim->state = m_state;
		}
	}
}

void UPlayerFSM::MoveState()
{
	anim->state = m_state;
	anim->state = m_state;
	//UE_LOG(LogTemp, Warning, TEXT("MOVESTATE: %d"), m_state);
	//UE_LOG(LogTemp, Warning, TEXT("MOVEANIMSTATE: %d"), anim->state);
	//// Move to Idle : 속도 멈추면 Idle로
	if (playerVelocity < 50)
	{
		//currentTime = 0;
		//currentTime += GetWorld()->DeltaTimeSeconds;
		//if (currentTime > delayTime)
		//{
			m_state = EPlayerState::Idle;
		//}
	}
	// Move to Attack : 공격이면
	else if (me->isAttacking == true)
	{
		if (me->shiftpressing == true)
		{
		// Move to SpecialAttack : 강공
			m_state = EPlayerState::SpecialAttack;
			//anim->state = m_state;
		}
		m_state = EPlayerState::Attack;
		//anim->state = m_state;
	}
	// Move to Damage : 공격을 받으면
	//else if ()
	//{
	//}
	// Move to Avoid : 공격을 막으면
	else if (me->isAvoiding == true)
	{
		m_state = EPlayerState::Avoid;
		//anim->state = m_state;
	}

}

void UPlayerFSM::AttackState()
{
	//UE_LOG(LogTemp, Warning, TEXT("me->isAttacking: %s"), me/isAttacking);
	anim->PlayAttackMontage();
	// 공격이 끝나야지만 상태 전환됨
	if (me->isAttacking == false)
	{
	// Attack to Idle : 속도 멈추면 Idle로
		if (playerVelocity < 100)
		{
			m_state = EPlayerState::Idle;
			//anim->state = m_state;
		}
	// Attack to Move : 속도 있으면 Move로
		else if (playerVelocity >= 100) {
			m_state = EPlayerState::Move;
			//anim->state = m_state;
		}
	}
	
}

void UPlayerFSM::SpecialAttackState()
{
	anim->PlaySpeicalAttackMontage();
	// 공격이 끝나야지만 상태 전환됨
	if (me->isAttacking == false)
	{
		// SpecialAttack to Idle : 속도 멈추면 Idle로
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
			//anim->state = m_state;
		}
		// SpecialAttack to Move : 속도 있으면 Move로
		else if (playerVelocity >= 50) {
			m_state = EPlayerState::Move;
			//anim->state = m_state;
		}
	}
}

void UPlayerFSM::AvoidState()
{
	anim->PlayDefenseMontage();
	// 회피가 끝나야지만 상태 전환됨
	if (me->isAvoiding == false)
	{
		// SpecialAttack to Idle : 속도 멈추면 Idle로
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
			anim->state = m_state;
		}
		// SpecialAttack to Move : 속도 있으면 Move로
		else if (playerVelocity >= 50) 
		{
			m_state = EPlayerState::Move;
			anim->state = m_state;
		}
	}
}

void UPlayerFSM::DamageState()
{
	FVector myPos = me->GetActorLocation();
	myPos = FMath::Lerp(myPos, knockbackPos, knockbackSpeed*GetWorld()->DeltaTimeSeconds);
	float distance = FVector::Dist(myPos, knockbackPos);
	if (distance<10.0f)
	{
		myPos = knockbackPos;
		me->isDamaging = false;
	}

	// 다친 게 끝나야지만 상태 전환됨
	if (me->isDamaging == false)
	{
		// Damage to Idle : 속도 멈추면 Idle로
		if (playerVelocity < 100)
		{
			m_state = EPlayerState::Idle;
			//anim->state = m_state;
		}
		// Damage to Move : 속도 있으면 Move로
		else if (playerVelocity >= 100) {
			m_state = EPlayerState::Move;
			//anim->state = m_state;
		}
		// Damage to Die : HP가 다 떨어지면 죽음
		else if (me->HP <= 0)
		{
			m_state = EPlayerState::Die;
			//anim->state = m_state;
		}
	}
	me->SetActorLocation(myPos);
}

void UPlayerFSM::DieState()
{
	
}

void UPlayerFSM::OnDamageProcess(FVector damagedDirection)
{
	me->HP = me->HP - 5;
	
	if (me->HP<=0)
	{
		m_state = EPlayerState::Die;
		anim->PlayDieMontage();
		me->Destroy();
		return;
	}
	
	damagedDirection.Z = 0;
	
	// 넉백되어 밀릴 위치
	knockbackPos = me->GetActorLocation() + damagedDirection*knockback;
	
	m_state = EPlayerState::Damage;
	anim->PlayHitMontage();
}
