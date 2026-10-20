#include "SampleGameInstance.h"

#include "Engine/Engine.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"
#include "SentrySubsystem.h"

struct FInventorySlot
{
	int32 Count = 0;
};

// Pretend loot table lookup: slot 3 was never loaded, so we get nullptr back.
static FInventorySlot* FindSlot(TArray<FInventorySlot*>& Slots, int32 Index)
{
	return Slots.IsValidIndex(Index) ? Slots[Index] : nullptr;
}

static int32 AddLoot(TArray<FInventorySlot*>& Slots, int32 Index, int32 Amount)
{
	FInventorySlot* Slot = FindSlot(Slots, Index);
	Slot->Count += Amount; // access violation, nobody checked for nullptr
	return Slot->Count;
}

void USampleGameInstance::Init()
{
	Super::Init();

	// Started by CI as: SentrySample.exe -sentryrun=<id> -nullrhi -unattended
	FString Run;
	if (!FParse::Value(FCommandLine::Get(), TEXT("sentryrun="), Run))
	{
		return;
	}

	// Sentry starts by itself (InitAutomatically in DefaultEngine.ini).
	// Tags set before the crash are written into the minidump.
	USentrySubsystem* Sentry = GEngine->GetEngineSubsystem<USentrySubsystem>();
	Sentry->SetTag(TEXT("run_id"), Run);
	Sentry->AddBreadcrumbWithParams(TEXT("Loot dropped"), TEXT("game"), TEXT("default"), {}, ESentryLevel::Info);

	UE_LOG(LogTemp, Warning, TEXT("SentrySample: crashing on purpose, run %s"), *Run);
	TArray<FInventorySlot*> Slots;
	Slots.Init(nullptr, 4);
	AddLoot(Slots, 3, 10);
}
