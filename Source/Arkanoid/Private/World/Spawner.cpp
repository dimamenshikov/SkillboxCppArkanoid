#include "World/Spawner.h"
#include "Components/ArrowComponent.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	ForwardArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ForwardDirection"));
	ForwardArrow->SetupAttachment(SceneRoot);
	ForwardArrow->SetAbsolute(false,false,true);
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	Spawner();
}

void ASpawner::Spawner()
{
	if (const auto World = GetWorld(); SpawnedClass&&World)
	{
		SpawnBall=World->SpawnActor<AActor>(SpawnedClass,ForwardArrow->GetComponentLocation(),ForwardArrow->GetComponentRotation());
		SpawnBall->OnDestroyed.AddDynamic(this, &ASpawner::BallDestroy);
	}
}

void ASpawner::BallDestroy(AActor* Ball)
{
	Spawner();
}

