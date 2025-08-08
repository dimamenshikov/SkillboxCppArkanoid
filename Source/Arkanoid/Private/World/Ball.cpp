#include "World/Ball.h"
#include "Components/ArrowComponent.h"

ABall::ABall()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	SetRootComponent(StaticMesh);

	ForwardDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("Direction"));
	ForwardDirection->SetupAttachment(StaticMesh);
	ForwardDirection->SetAbsolute(false,false,true);
}

void ABall::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	
	SetActorScale3D(FVector(Parameters.Scale));
	Direction = GetActorForwardVector();
	Movement = true;
	Power = Parameters.Power;
	Speed = Parameters.Speed;
}

void ABall::BeginPlay()
{
	Super::BeginPlay();
}

void ABall::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Movement)
	{
		Move(DeltaTime);
	}
}

void ABall::Move(const float DeltaTime)
{
	const FVector Offset= Direction*Speed*DeltaTime;
	FHitResult HitResult;
	AddActorWorldOffset(Offset, true, &HitResult);

	if (HitResult.bBlockingHit)
	{
		Direction-=2*HitResult.Normal*(FVector::DotProduct(Direction, HitResult.Normal));
		Direction.Z=0.0f;
		Direction.Normalize();
		Speed = FMath::Min(Speed+Parameters.Speed/4, Parameters.MaxSpeed);
	}
	UE_LOG(LogTemp, Display, TEXT("Speed:%f"), Speed);
}