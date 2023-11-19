// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CalendarRow.generated.h"

USTRUCT(BlueprintType)
struct FMyBaseSructure
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar Variables")
    int32 Row;
};

UCLASS(BlueprintType)
class UCalendarRow : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void Init(int32 RowValue);

    UPROPERTY(BlueprintReadWrite, Category = "Calendar Variables")
    FMyBaseSructure structure;

};
