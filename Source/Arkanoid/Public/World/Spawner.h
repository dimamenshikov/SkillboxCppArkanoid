#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class UArrowComponent;

UCLASS()
class ARKANOID_API ASpawner : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneRoot = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Components, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* ForwardArrow=nullptr;
	
public:	
	ASpawner();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setting)
	TSubclassOf<AActor> SpawnedClass;
	AActor* SpawnBall;
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	void Spawner();
	UFUNCTION(BlueprintCallable)
	void BallDestroy(AActor* Ball);
};


