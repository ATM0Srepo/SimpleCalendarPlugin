// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CalendarUIBase.h"
#include "CalendarRow.generated.h"

/**
 * @struct FMyBaseSructure
 * @brief A structure containing properties of a calendar row.
 *
 * This structure holds data such as row index, year, month, and colors
 * for different grid states in the calendar.
 */
USTRUCT(BlueprintType)
struct FMyBaseSructure
{
    GENERATED_BODY()

    /** The row index in the calendar. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar Properties")
    int32 Row;

    /** The year associated with this calendar row. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar Properties")
    int32 Year;

    /** The month associated with this calendar row. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calendar Properties")
    int32 Month;

    /** The color used for selected grids in the calendar. */
    UPROPERTY(BlueprintReadOnly, Category = "Calendar Properties")
    FLinearColor SelectedGridColor;

    /** The color used for empty grids in the calendar. */
    UPROPERTY(BlueprintReadOnly, Category = "Calendar Properties")
    FLinearColor EmptyGridColor;

    /** The default color used for calendar grids. */
    UPROPERTY(BlueprintReadOnly, Category = "Calendar Properties")
    FLinearColor GridColor;
};

/**
 * @class UCalendarRow
 * @brief Represents a row in the calendar with associated properties and functionality.
 *
 * This class defines a calendar row, its initialization logic, and its owner widget.
 */
UCLASS(BlueprintType)
class UCalendarRow : public UObject
{
    GENERATED_BODY()

public:
    /**
     * @brief Initializes a calendar row with the specified parameters.
     *
     * @param RowValue The row index to initialize.
     * @param year The year associated with the row.
     * @param month The month associated with the row.
     * @param color1 The primary color for selected calendar grids.
     * @param color2 The secondary color for empty calendar grids.
     * @param color3 The default color for calendar grids.
     * @param InOwner A reference to the owning `UCalendarUIBase` object.
     */
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void Init(
        int32 RowValue,
        int32 year,
        int32 month,
        FLinearColor color1,
        FLinearColor color2,
        FLinearColor color3,
        UCalendarUIBase* InOwner
    );

    /** The structure containing properties for the calendar row. */
    UPROPERTY(BlueprintReadWrite, Category = "Atm0s Calendar Variables")
    FMyBaseSructure structure;

    /** A reference to the owner of this calendar row. */
    UPROPERTY(BlueprintReadOnly, Category = "Owner")
    UCalendarUIBase* Owner;
};
