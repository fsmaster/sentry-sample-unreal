#pragma once

#include "Engine/GameInstance.h"
#include "SampleGameInstance.generated.h"

UCLASS()
class USampleGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
};
