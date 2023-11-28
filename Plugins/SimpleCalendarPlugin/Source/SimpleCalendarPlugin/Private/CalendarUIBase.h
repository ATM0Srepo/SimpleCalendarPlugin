#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableTextBox.h"
#include "CalendarUIBase.generated.h"

/**
 *
 */
UCLASS()
class UCalendarUIBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UEditableTextBox* year;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UTextBlock* month;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UTextBlock* hour;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UTextBlock* minute;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UListView* ListViewCalendar;

	FTimerHandle TickTimerHandle;
	void SetTime();

	// Specify your tick interval here, for example, 0.1f for 10 times per second
	const float TickInterval = 0.5f;

private:
	void CreateCalendar();
};
