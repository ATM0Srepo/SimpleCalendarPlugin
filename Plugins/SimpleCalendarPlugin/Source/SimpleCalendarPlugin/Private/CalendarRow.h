// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CalendarUIBase.h"
#include "CalendarRow.generated.h"

USTRUCT(BlueprintType)
struct FMyBaseSructure
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar Properties")
    int32 Row;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar Properties")
    int32 Year;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar Properties")
    int32 Month;

    UPROPERTY(BlueprintReadOnly, Category = "Calendar Properties")
    FLinearColor SelectedGridColor;

    UPROPERTY(BlueprintReadOnly, Category = "Calendar Properties")
    FLinearColor EmptyGridColor;

    UPROPERTY(BlueprintReadOnly, Category = "Calendar Properties")
    FLinearColor GridColor;
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
        FLinearColor color2,
        FLinearColor color3,
        UCalendarUIBase* InOwner
    );

    UPROPERTY(BlueprintReadWrite, Category = "Atm0s Calendar Variables")
    FMyBaseSructure structure;

    UPROPERTY(BlueprintReadOnly, Category = "Owner")
    UCalendarUIBase* Owner;

};

