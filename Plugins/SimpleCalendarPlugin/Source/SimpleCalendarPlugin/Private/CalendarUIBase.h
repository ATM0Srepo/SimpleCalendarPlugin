// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CalendarUIBase.generated.h"

/**
 *
 */
UCLASS()
class UCalendarUIBase : public UUserWidget
{
	GENERATED_BODY()

public:
	void Start();
	
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
	class UTextBlock* year;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
	class UTextBlock* month;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
	class UTextBlock* hour;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
	class UTextBlock* minute;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
	class UListView* ListViewCalendar;

	FTimerHandle TickTimerHandle;
	void SetTime();

	// Specify your tick interval here, for example, 0.1f for 10 times per second
	const float TickInterval = 0.5f;

private:
	void CreateCalendar();
};
