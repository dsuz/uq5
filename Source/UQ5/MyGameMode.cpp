#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"

AMyGameMode::AMyGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (IsStageClear) return;
	Timer += DeltaSeconds;
	
	if (Timer > CheckInterval)
	{
		Timer = 0.0f;
		
		if (CheckQualified())
		{
			UE_LOG(LogTemp, Log, TEXT("Detect Stage Clear. Broadcast..."));
			OnStageClear.Broadcast();
			IsStageClear = true;
		}
	}
}

/// 初期化
/// @param KillCountForStageClear クリアまでに倒す敵の数 
void AMyGameMode::Init(int32 KillCountForStageClear)
{
	// クリアまでに倒す数、スポーンさせる数など各変数を初期化する
	IsStageClear = false;
	EnemyKilledCount = 0;
	QualifyKillCount = KillCountForStageClear;
	UE_LOG(LogTemp, Log, TEXT("Set Qualify Kill Count: %d"), QualifyKillCount);
	auto OutActors = TArray<AActor*>();
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Enemy"), OutActors);
	int EnemyInTheMapCount = OutActors.Num();
	SpawnCount = QualifyKillCount - EnemyInTheMapCount;
	UE_LOG(LogTemp, Log, TEXT("%d enemies to be spawned later."), SpawnCount);
}

/// クリア条件を満たしているかチェックする
bool AMyGameMode::CheckQualified() const
{
	auto Message = FString::Printf(TEXT("Checking KillCount: %d, Qualify: %d"), EnemyKilledCount, QualifyKillCount);
	UKismetSystemLibrary::PrintString(GetWorld(), Message, true, false, FLinearColor::Yellow, 2.0f, "KillCount");
	
	if (EnemyKilledCount >= QualifyKillCount)
	{
		auto OutActors = TArray<AActor*>();
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Enemy"), OutActors);
		
		if (OutActors.Num() == 0)
		{
			return true;
		}
	}
	
	return false;
}
