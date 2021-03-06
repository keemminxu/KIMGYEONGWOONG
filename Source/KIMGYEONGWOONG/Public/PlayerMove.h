// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerMove.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KIMGYEONGWOONG_API UPlayerMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

	void Horizontal(float value);
	void Vertical(float value);
	// 회전시키기
	void Turn(float value);
	void LookUp(float value);
	// 구르기
	void UsePotion();
	void Skill();

public:
	// 필요속성 : 소유액터
	UPROPERTY()
		class AKIMGYEONGWOONGPlayer* me;

	UPROPERTY()
		float initialWalkSpeed = 600;
	UPROPERTY()
		float fastWalkSpeed = 900;
};
