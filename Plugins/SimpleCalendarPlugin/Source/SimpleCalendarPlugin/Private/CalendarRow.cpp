// Fill out your copyright notice in the Description page of Project Settings.


#include "CalendarRow.h"

void UCalendarRow::Init(int32 RowValue, int32 year, FLinearColor color1 = FLinearColor(1.0f, 1.0f, 1.0f, 0.8f))
{
	structure.Row = RowValue;
	structure.Year = year;
	structure.SelectedGridColor = color1;
}