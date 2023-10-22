// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCalendarUIBase.generated.h"

/**
 * 
 */
UCLASS()
class UMyCalendarUIBase : public UUserWidget
{
	GENERATED_BODY()

private:
	int32 GetStartDayOfMonth(int32 Year, int32 Month);
	
};
