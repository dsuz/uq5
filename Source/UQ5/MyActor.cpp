


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Colors.Add(FColor::Red);
	Colors.Add(FColor::Blue);
	Colors.Add(FColor::Green);
	Colors.Add(FColor::Emerald);
	Colors.Add(FColor::Magenta);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Timer += DeltaTime;
	
	if (Timer > Interval)
	{
		Timer = 0.0f;
		FColor Color = Colors[ColorIndex];
		ColorIndex = (ColorIndex + 1) % Colors.Num();
		GEngine->AddOnScreenDebugMessage(-1, 10, Color, TEXT("Hello"));	
	}
}

