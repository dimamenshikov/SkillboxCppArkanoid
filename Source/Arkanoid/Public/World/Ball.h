#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UArrowComponent;

USTRUCT(BlueprintType)
struct FParameters
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta=(ToolTip = "Начальная сила"))
	int32 Power;
	UPROPERTY(EditDefaultsOnly, meta=(ToolTip = "Начальная скорость"))
	float Speed;
	UPROPERTY(EditDefaultsOnly, meta=(ToolTip = "Максимальная скорость"))
	float MaxSpeed;
	UPROPERTY(EditDefaultsOnly, meta=(ToolTip = "Стартовый размер"))
	float Scale;

	FParameters()
	{
		Power = 100;
		Speed = 100.0f;
		MaxSpeed = 1000.0f;
		Scale = 1.0f;
	}
};

UCLASS()
class ARKANOID_API ABall : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* ForwardDirection = nullptr;
	
	int32 Power = 1;
	float Speed = 1.0f;
	FVector Direction = FVector::ZeroVector;
	bool Movement = false;

protected:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Setting")
	FParameters Parameters;

	/**
	 * Функция движения шара
	 * @param DeltaTime Время, прошедшее с последнего тика
	 */
	UFUNCTION(BlueprintCallable, Category = "Ball")
	void Move(const float DeltaTime);

public:
	ABall();
};
