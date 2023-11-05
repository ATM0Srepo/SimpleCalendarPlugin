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

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* year;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* month;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* hour;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* minute;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UListView* ListViewCalendar;

private:
	void CreateCalendar();
};
