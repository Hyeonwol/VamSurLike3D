// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystemInterface.h"
#include "AttributeSet.h"

#include "VS3DCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UCharacterAttributeSet;


UCLASS()
class VAMSURLIKE3D_API AVS3DCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AVS3DCharacter();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

public:

	//Input Action & Input Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	UInputMappingContext* CharacterMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	UInputAction* MoveAction;

	//움직임 관련 함수
	void Move(const FInputActionValue& Value);
	
	//Components
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> FollowCamera;

	//GAS 관련
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UCharacterAttributeSet> AttributeSet;

	//IAbilitySysyemInterface(어빌리티 시스템 컴포넌트 반환)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
