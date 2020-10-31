// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/PawnBase.h"
#include "PawnTurret.generated.h"

/**
 * 
 */
class APawnTank;
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()
private:
	UPROPERTY(EDITANYWHERE, BLUEPRINTREADWRITE, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRate = 2.f;
	UPROPERTY(EDITANYWHERE, BLUEPRINTREADWRITE, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	float FireRange = 500;

	void CheckFireCondition();

	float ReturnDistanceToPlayer();

	FTimerHandle FireRateTimerHandle;

	APawnTank* PlayerPawn;

public:
			// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void HandleDestruction() override; 


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



};