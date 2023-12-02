// Fill out your copyright notice in the Description page of Project Settings.


#include "CalendarRow.h"

void UCalendarRow::Init(int32 RowValue, FLinearColor color1)
{
	structure.Row = RowValue;
	structure.SelectedGridColor = color1;
}