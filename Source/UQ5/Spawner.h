#pragma once

#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

UCLASS()
class UQ5_API ASpawner : public ATargetPoint
{
	GENERATED_BODY()
	
public:	
	ASpawner();

protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;
	/// スポーン間隔（秒）
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnInterval = 5;
	/// スポーンさせるポーン
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<APawn> SpawnPawn = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bActive = true;
	
private:
	float Timer = 0.0f;
};
