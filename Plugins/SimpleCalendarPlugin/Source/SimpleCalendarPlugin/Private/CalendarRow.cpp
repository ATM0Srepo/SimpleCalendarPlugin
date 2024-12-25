// Fill out your copyright notice in the Description page of Project Settings.

#include "CalendarRow.h"

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
void UCalendarRow::Init(
    int32 RowValue,
    int32 year, int32 month,
    FLinearColor color1,
    FLinearColor color2,
    FLinearColor color3,
    UCalendarUIBase* InOwner)
{
    structure.Row = RowValue;
    structure.Year = year;
    structure.Month = month;
    structure.SelectedGridColor = color1;
    structure.EmptyGridColor = color2;
    structure.GridColor = color3;
    Owner = InOwner;
}
