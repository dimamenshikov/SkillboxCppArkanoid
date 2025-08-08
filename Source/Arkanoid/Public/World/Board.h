#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Board.generated.h"

class UCameraComponent;

UCLASS()
class ARKANOID_API ABoard : public APawn
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera = nullptr;

public:
	ABoard();
};
