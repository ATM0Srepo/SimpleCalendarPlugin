// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CalendarRow.generated.h"

USTRUCT(BlueprintType)
struct FMyBaseSructure
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Row;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Year;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Month;

    UPROPERTY(BlueprintReadOnly)
    FLinearColor SelectedGridColor;

    UPROPERTY(BlueprintReadOnly)
    FLinearColor EmptyGridColor;
};

UCLASS(BlueprintType)
class UCalendarRow : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void Init(int32 RowValue, 
        int32 year, 
        int32 month,  
        FLinearColor color1,
        FLinearColor color2
    );

    UPROPERTY(BlueprintReadWrite, Category = "Atm0s Calendar Variables")
    FMyBaseSructure structure;

};

