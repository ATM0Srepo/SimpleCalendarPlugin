// Fill out your copyright notice in the Description page of Project Settings.


#include "CalendarRow.h"

void UCalendarRow::Init(int32 RowValue, int32 year, int32 month, FLinearColor color1 = FLinearColor(1.0f, 1.0f, 1.0f, 0.8f), FLinearColor color2 = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f))
{
	structure.Row = RowValue;
	structure.Year = year;
	structure.Month = month;
	structure.SelectedGridColor = color1;
	structure.EmptyGridColor = color2;
}