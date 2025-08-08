#include "World/Board.h"
#include "Camera/CameraComponent.h"

ABoard::ABoard()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	AutoPossessPlayer=EAutoReceiveInput::Type::Player0;
}