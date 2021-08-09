// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFSM.h"
#include "KIMGYEONGWOONGPlayer.h"

// Sets default values for this component's properties
UPlayerFSM::UPlayerFSM()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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


// Called when the game starts
void UPlayerFSM::BeginPlay()
{
	Super::BeginPlay();
	//anim = Cast<UPlayerAnimInstance>(me->GetMesh()->GetAnimInstance());
}


void UPlayerFSM::InitializeComponent()
{
	Super::InitializeComponent();

	me = Cast<AKIMGYEONGWOONGPlayer>(GetOwner());
	if (me)
	{
		playerVelocity = me->GetVelocity().Size();
		isShiftPressed = me->shiftpressing;
		isPlayerAttacking = me->isAttacking;
		isPlayerAvoiding = me->isAvoiding;
	}
}

// Called every frame
void UPlayerFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerFSM::IdleState()
{
// Idle to Move : 플레이어 속도가 0 이상이면 상태 Move로 전환
	if (playerVelocity > 0)
	{
		m_state = EPlayerState::Move;
	}
// Idle to Attack : 가만히 공격하는 경우 Attack 
	//else if (me->isAttacking == true) // nullptr
	else if (isPlayerAttacking == true)
	{
	// Idle to SpecialAttack : 강공
		if (isShiftPressed == true)
		{
			m_state = EPlayerState::SpecialAttack;
		}
		m_state = EPlayerState::Attack;
	}
//// Idle to Damage : 공격을 받으면
//	else if ()
//	{
//	}
// Idle to Avoid : 공격을 막으면
// else if (me->isAvoiding == true) // nullptr
	else if (isPlayerAvoiding == true)
	{
		m_state = EPlayerState::Avoid;
	}

}

void UPlayerFSM::MoveState()
{
	// Move to Idle : 속도 멈추면 Idle로
	if (playerVelocity == 0)
	{
		m_state = EPlayerState::Idle;
		anim->isMoving = false;
	}
	// Move to Attack : 공격이면
	else if (me->isAttacking == true)
	{
		if (me->shiftpressing == true)
		{
		// Move to SpecialAttack : 강공
			m_state = EPlayerState::SpecialAttack;
		}
		m_state = EPlayerState::Attack;
	}
	// Move to Damage : 공격을 받으면
	//else if ()
	//{
	//}
	// Move to Avoid : 공격을 막으면
	else if (me->isAvoiding == true)
	{
		m_state = EPlayerState::Avoid;
	}

}

void UPlayerFSM::AttackState()
{
	// 공격이 끝나야지만 상태 전환됨
	if (me->isAttacking == false)
	{
	// Attack to Idle : 속도 멈추면 Idle로
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
		}
	// Attack to Move : 속도 있으면 Move로
		else if (playerVelocity > 0) {
			m_state = EPlayerState::Move;
		}
	}
	
}

void UPlayerFSM::SpecialAttackState()
{
	// 공격이 끝나야지만 상태 전환됨
	if (me->isAttacking == false)
	{
		// SpecialAttack to Idle : 속도 멈추면 Idle로
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
		}
		// SpecialAttack to Move : 속도 있으면 Move로
		else if (playerVelocity > 0) {
			m_state = EPlayerState::Move;
		}
	}
}

void UPlayerFSM::AvoidState()
{
	// 회피가 끝나야지만 상태 전환됨
	if (me->isAvoiding == false)
	{
		// SpecialAttack to Idle : 속도 멈추면 Idle로
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
		}
		// SpecialAttack to Move : 속도 있으면 Move로
		else if (playerVelocity > 0) {
			m_state = EPlayerState::Move;
		}
	}
}

void UPlayerFSM::DamageState()
{
	// 다친 게 끝나야지만 상태 전환됨-변수명 바꿔줘야 됨
	if (me->isAttacking == false)
	{
		// Damage to Idle : 속도 멈추면 Idle로
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
		}
		// Damage to Move : 속도 있으면 Move로
		else if (playerVelocity > 0) {
			m_state = EPlayerState::Move;
		}
		// Damage to Die : HP가 다 떨어지면 죽음
		else if (me->HP <= 0)
		{
			m_state = EPlayerState::Die;
		}
	}

}

void UPlayerFSM::DieState()
{
	
}

void UPlayerFSM::OnDamageProcess()
{
	me->HP = me->HP-3;

	if (me->HP<0)
	{
		m_state = EPlayerState::Die;
		me->Destroy();
		return;
	}

	m_state = EPlayerState::Damage;

}

