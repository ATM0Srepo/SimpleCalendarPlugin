#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableTextBox.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "CalendarUIBase.generated.h"

/**
 * @class UCalendarUIBase
 * @brief A user interface class for managing calendar functionality.
 * 
 * This class provides various functions and properties for configuring,
 * displaying, and interacting with a calendar in Unreal Engine.
 */
UCLASS()
class UCalendarUIBase : public UUserWidget
{
    GENERATED_BODY()

public:
    /**
     * @brief Called after the widget is constructed.
     * 
     * Initializes calendar properties and binds events to UI elements.
     */
    virtual void NativeConstruct() override;

    /**
     * @brief Retrieves the current DateTime set on the calendar.
     * @return The current DateTime object.
     */
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    FDateTime GetTime();

protected:
    /** Editable text box for the calendar year. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UEditableTextBox* year;

    /** Text block for displaying the calendar month. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UTextBlock* month;

    /** Editable text box for the calendar hour. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UEditableTextBox* hour;

    /** Editable text box for the calendar minute. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UEditableTextBox* minute;

    /** Button to toggle to the previous month. */
    UPROPERTY(meta = (BindWidget))
    class UButton* toggle_prev_month;

    /** Button to toggle to the next month. */
    UPROPERTY(meta = (BindWidget))
    class UButton* toggle_next_month;

    /** Button for selecting a month. */
    UPROPERTY(meta = (BindWidget))
    class UButton* MonthButton;

    /** Button for selecting an hour. */
    UPROPERTY(meta = (BindWidget))
    class UButton* HourButton;

    /** Button for selecting a minute. */
    UPROPERTY(meta = (BindWidget))
    class UButton* MinuteButton;

    /** Background for weekday headers. */
    UPROPERTY(meta = (BindWidget))
    class UButton* weekdays_background;

    /** Background for the calendar. */
    UPROPERTY(meta = (BindWidget))
    class UButton* calendar_background;

    /** List view for displaying calendar items. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UListView* ListViewCalendar;

    /**
     * @brief Configures the calendar's style settings.
     * 
     * This function should be called before creating the calendar.
     * 
     * @param SelectedGridColor Color for selected calendar grid.
     * @param EmptyGridColor Color for empty calendar grid.
     * @param GridColor Default grid color.
     * @param CalendarBackground Background color for the calendar.
     * @param CalendarBackgroundBorder Border color for the calendar background.
     * @param WeekdayHeadingColor Color for weekday headers.
     */
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void PreCalendarConfig(
        FLinearColor SelectedGridColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.8f),
        FLinearColor EmptyGridColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f),
        FLinearColor GridColor = FLinearColor(0.45f, 0.2f, 0.1f, 0.7f),
        FLinearColor CalendarBackground = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f),
        FLinearColor CalendarBackgroundBorder = FLinearColor(0.45f, 0.2f, 0.1f, 0.7f),
        FLinearColor WeekdayHeadingColor = FLinearColor(0.0f, 0.0f, 0.0f, 1.0f)
    );

    /**
     * @brief Sets corner radii for calendar and weekday headers.
     * 
     * This function can be called before or after creating the calendar.
     * 
     * @param CalendarBorder Corner radii for the calendar border.
     * @param WeekdayHeaderRadii Corner radii for the weekday header.
     */
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void SetCornerRadii(const FVector4& CalendarBorder, const FVector4& WeekdayHeaderRadii);

    /**
     * @brief Creates the calendar UI.
     */
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void CreateCalendar();

    /**
     * @brief Sets the calendar year.
     * 
     * This function should be called before creating the calendar.
     * 
     * @param y The year to set.
     */
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void SetYear(int y);

    /**
     * @brief Sets the calendar month.
     * 
     * This function should be called before creating the calendar.
     * 
     * @param m The month to set (1-12).
     */
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void SetMonth(int32 m);

    // Event handlers for year, month, hour, and minute changes
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

    /**
     * @brief Shows the next month in the calendar.
     */
    UFUNCTION()
    void ShowNextMonth();

    /**
     * @brief Shows the previous month in the calendar.
     */
    UFUNCTION()
    void ShowPrevMonth();

    /** Timer handle for ticking events. */
    FTimerHandle TickTimerHandle;

    /** Initializes the hour text box. */
    void InitializeHour();

    /** Initializes the minute text box. */
    void InitializeMinute();

    /** Sets the year from code. */
    void InitializeYear(int y);

    /** Sets the month from code. */
    void InitializeMonth(int m);

    /** Default interval for minute ticks. */
    float DefaultMinuteTickInterval = 0.01f;

private:
    /** Current date and time. */
    FDateTime CurrentDateTime;

    /** Current year. */
    int32 year_now;

    /** Current month. */
    int32 month_now;

    /** Current hour as a string. */
    FString hour_now;

    /** Current minute as a string. */
    FString minute_now;

    /** Temporary hour value for calculations. */
    int32 td_hour = 0;

    /** Temporary minute value for calculations. */
    int32 td_min = 0;

    /** Difference in hours. */
    FTimespan hourDifference;

    /** Difference in minutes. */
    FTimespan minuteDifference;

    /** Primary grid color. */
    FLinearColor color1;

    /** Secondary grid color. */
    FLinearColor color2;

    /** Default grid color. */
    FLinearColor color3;

    /** Map of month names to their numerical representations. */
    TMap<FString, int32> MonthMap2;
};
