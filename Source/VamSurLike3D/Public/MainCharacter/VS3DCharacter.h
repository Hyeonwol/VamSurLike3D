// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystemInterface.h"
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

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	//Enhanced Input 관련
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputMappingContext> CharacterMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input)
	TObjectPtr<UInputAction> MoveAction;

	//움직임 관련 함수
	void Move(const FInputActionValue& Value);
	
	//Components
	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> FollowCamera;

	//등장 애니메이션 재생 중인지 확인. 등장 애니메이션이 재생 중이라면, 이동 불가, 공격 애니메이션 재생 X
	UPROPERTY(BlueprintReadWrite, Category = "Animation")
	bool bIsPlayingIntroAnimation = true;
	
	//GAS 관련
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	TObjectPtr<UCharacterAttributeSet> AttributeSet;

	//IAbilitySysyemInterface(어빌리티 시스템 컴포넌트 반환)
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
