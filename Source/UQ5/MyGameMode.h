#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStageClearSignature);
UCLASS()
class UQ5_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyGameMode();

	/// 倒した敵の数
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 EnemyKilledCount = 0;
	/// クリアに必要な倒す敵の数
	UPROPERTY(EditAnywhere)
	int32 QualifyKillCount = 0;
	/// クリア条件チェックルーチンを実行する間隔
	UPROPERTY(EditAnywhere)
	float CheckInterval = 1.0f;
	/// ステージクリア時に実行する処理
	UPROPERTY(BlueprintAssignable)
	FOnStageClearSignature OnStageClear;
	/// 残りスポーン数
	int SpawnCount = 0;
	/// ステージクリアフラグ
	bool IsStageClear = false;

	virtual void Tick(float DeltaSeconds) override;	
	UFUNCTION(BlueprintCallable)
	void Init(int32 KillCountForStageClear);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GameOver();
	
private:
	float Timer = 0.0f;
	bool CheckQualified() const;
};
