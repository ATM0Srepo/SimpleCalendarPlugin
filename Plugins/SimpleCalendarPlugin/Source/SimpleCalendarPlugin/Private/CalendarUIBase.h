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

	UFUNCTION(BlueprintImplementableEvent, Category = "Atm0s Calendar Events")
	void MyStupidEvent();

protected:
	/** Calendar Year (Editable TextBox) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UEditableTextBox* year;

	/** Calendar Month (TextBlock) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UTextBlock* month;

	/** Calendar Hour (Editable TextBox) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UEditableTextBox* hour;

	/** Calendar Minute (Editable TextBox) */
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UEditableTextBox* minute;

	UPROPERTY(meta = (BindWidget))
	class UButton* toggle_prev_month;

	UPROPERTY(meta = (BindWidget))
	class UButton* toggle_next_month;

	UPROPERTY(meta = (BindWidget))
	class UButton* MonthButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* HourButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* MinuteButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* weekdays_background;

	UPROPERTY(meta = (BindWidget))
	class UButton* calendar_background;



	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
	class UListView* ListViewCalendar;



	/**
	* Manipulate Calendar style settings from blueprint
	* To be called before CreateCalendar Function
	*/
	UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
	void PreCalendarConfig(FLinearColor SelectedGridColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.8f),
		FLinearColor EmptyGridColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f),
		FLinearColor GridColor = FLinearColor(0.45f, 0.2f, 0.1f, 0.7f),
		FLinearColor CalendarBackground = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f),
		FLinearColor CalendarBackgroundBorder = FLinearColor(0.45f, 0.2f, 0.1f, 0.7f),
		FLinearColor WeekdayHeadingColor = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f)
	);

	/**
	* Manipulate Corner Radii of Calendar, Weekday Heading Bar, and Calendar Grids
	* Can be called before or after CreateCalendar function
	*/
	UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
	void SetCornerRadii(const FVector4& CalendarBorder, const FVector4& WeekdayHeaderRadii);

	/** Create Calendar */
	UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
	void CreateCalendar();

	/** Manipulate Calendar Year from blueprint
	* To be called before CreateCalendar Function
	*/
	UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
	void SetYear(int y);

	/** Manipulate Calendar Month from blueprint
	* To be called before CreateCalendar Function
	*/
	UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
	void SetMonth(int32 m);

	UFUNCTION()
	void HandleOnYearChanged(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
	void HandleMonthToggleButtonClick();

	UFUNCTION()
	void HandleOnHourCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
	void HandleOnHourChanged(const FText& Text);

	UFUNCTION()
	void HandleOnMinuteCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UFUNCTION()
	void HandleOnMinuteChanged(const FText& Text);

	UFUNCTION()
	void ShowNextMonth();

	UFUNCTION()
	void ShowPrevMonth();

	FTimerHandle TickTimerHandle;
	void InitializeHour();
	void InitializeMinute();
	void InitializeYear(int y); // set year from c++ code
	void InitializeMonth(int m); // set month from c++ code

	// Specify the tick interval here, for example, 0.1f for 10 times per second
	const float DefaultMinuteTickInterval = 0.5f;

private:
	FDateTime CurrentDateTime;
	int32 year_now;
	int32 month_now;
	int32 td_hour = 0;
	int32 td_min = 0;
	FTimespan hourDifference = FDateTime::Now() - FDateTime::Now();
	FTimespan minuteDifference = FDateTime::Now() - FDateTime::Now();
	FLinearColor color1;
	FLinearColor color2;
	FLinearColor color3;
	TMap<FString, int32> MonthMap2;
};
