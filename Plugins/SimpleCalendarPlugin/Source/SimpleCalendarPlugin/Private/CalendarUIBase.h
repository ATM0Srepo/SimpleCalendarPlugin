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
	/** Calendar Year (Editable TextBox) */
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

	/**
	* Manipulate Calendar style settings from blueprint
	* To be called before CreateCalendar Function
	*/
	UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
	void PreCalendarConfig(FLinearColor SelectedGridColor);

	/** Create Calendar */
	UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
	void CreateCalendar();

	/** Manipulate Calendar Year from blueprint
	* To be called before CreateCalendar Function
	*/
	UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
	void SetYear(int y);

	UFUNCTION()
	void HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	FTimerHandle TickTimerHandle;
	void SetTime();
	void InitializeYear(int y); // set year from c++ code

	// Specify the tick interval here, for example, 0.1f for 10 times per second
	const float TickInterval = 0.5f;

private:
	FDateTime CurrentDateTime;
	int32 year_now;
	FLinearColor color1;
};
