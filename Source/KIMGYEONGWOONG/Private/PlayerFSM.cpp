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
// Idle to Move : �÷��̾� �ӵ��� 0 �̻��̸� ���� Move�� ��ȯ
	if (playerVelocity > 0)
	{
		m_state = EPlayerState::Move;
	}
// Idle to Attack : ������ �����ϴ� ��� Attack 
	//else if (me->isAttacking == true) // nullptr
	else if (isPlayerAttacking == true)
	{
	// Idle to SpecialAttack : ����
		if (isShiftPressed == true)
		{
			m_state = EPlayerState::SpecialAttack;
		}
		m_state = EPlayerState::Attack;
	}
//// Idle to Damage : ������ ������
//	else if ()
//	{
//	}
// Idle to Avoid : ������ ������
// else if (me->isAvoiding == true) // nullptr
	else if (isPlayerAvoiding == true)
	{
		m_state = EPlayerState::Avoid;
	}

}

void UPlayerFSM::MoveState()
{
	// Move to Idle : �ӵ� ���߸� Idle��
	if (playerVelocity == 0)
	{
		m_state = EPlayerState::Idle;
		anim->isMoving = false;
	}
	// Move to Attack : �����̸�
	else if (me->isAttacking == true)
	{
		if (me->shiftpressing == true)
		{
		// Move to SpecialAttack : ����
			m_state = EPlayerState::SpecialAttack;
		}
		m_state = EPlayerState::Attack;
	}
	// Move to Damage : ������ ������
	//else if ()
	//{
	//}
	// Move to Avoid : ������ ������
	else if (me->isAvoiding == true)
	{
		m_state = EPlayerState::Avoid;
	}

}

void UPlayerFSM::AttackState()
{
	// ������ ���������� ���� ��ȯ��
	if (me->isAttacking == false)
	{
	// Attack to Idle : �ӵ� ���߸� Idle��
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
		}
	// Attack to Move : �ӵ� ������ Move��
		else if (playerVelocity > 0) {
			m_state = EPlayerState::Move;
		}
	}
	
}

void UPlayerFSM::SpecialAttackState()
{
	// ������ ���������� ���� ��ȯ��
	if (me->isAttacking == false)
	{
		// SpecialAttack to Idle : �ӵ� ���߸� Idle��
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
		}
		// SpecialAttack to Move : �ӵ� ������ Move��
		else if (playerVelocity > 0) {
			m_state = EPlayerState::Move;
		}
	}
}

void UPlayerFSM::AvoidState()
{
	// ȸ�ǰ� ���������� ���� ��ȯ��
	if (me->isAvoiding == false)
	{
		// SpecialAttack to Idle : �ӵ� ���߸� Idle��
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
		}
		// SpecialAttack to Move : �ӵ� ������ Move��
		else if (playerVelocity > 0) {
			m_state = EPlayerState::Move;
		}
	}
}

void UPlayerFSM::DamageState()
{
	// ��ģ �� ���������� ���� ��ȯ��-������ �ٲ���� ��
	if (me->isAttacking == false)
	{
		// Damage to Idle : �ӵ� ���߸� Idle��
		if (playerVelocity == 0)
		{
			m_state = EPlayerState::Idle;
		}
		// Damage to Move : �ӵ� ������ Move��
		else if (playerVelocity > 0) {
			m_state = EPlayerState::Move;
		}
		// Damage to Die : HP�� �� �������� ����
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

