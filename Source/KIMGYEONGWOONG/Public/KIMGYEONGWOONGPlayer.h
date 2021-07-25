// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KIMGYEONGWOONGPlayer.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FPlayerInputDelegate, class UInputComponent*);



UCLASS()
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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, Category = "FPSCamera")   
		class UCameraComponent* fpsCamera;

public:
	UPROPERTY(VisibleAnywhere, Category = BodyMesh)
		class USkeletalMeshComponent* bodyMesh;

public:

	UPROPERTY(VisibleAnywhere, Category = PlayerMove)
		class UPlayerMove* playerMove;


	FPlayerInputDelegate OnInputDelegate;


};
