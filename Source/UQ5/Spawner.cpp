#include "Spawner.h"

#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	Timer = SpawnInterval;
}

void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!bActive) return;
	Timer += DeltaTime;
	
	if (Timer > SpawnInterval)
	{
		Timer = 0.0f;
		auto GameMode = Cast<AMyGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		
		if (!IsValid(GameMode))
		{
			UE_LOG(LogTemp, Error, TEXT("Game Mode Invalid"));
			return;
		}
		
		if (GameMode->SpawnCount > 0)
		{
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = this;
		
			if (IsValid(SpawnPawn))
			{
				auto SpawnedPawn = GetWorld()->SpawnActor<APawn>(SpawnPawn, GetActorLocation(), GetActorRotation(), SpawnInfo);
				UE_LOG(LogTemp, Log, TEXT("Spawn remains: %d"), --GameMode->SpawnCount);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("SpawnActor unassigned: %s"), *this->GetName());			
			}
		}
	}
}

