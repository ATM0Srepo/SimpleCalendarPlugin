// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyCalendarRow.generated.h"

USTRUCT(BlueprintType)
struct FMyBaseSructure
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Row;
};

UCLASS(BlueprintType)
class UMyCalendarRow : public UObject
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void Init(int32 RowValue);

    UPROPERTY(BlueprintReadWrite)
    FMyBaseSructure structure;
	
};
