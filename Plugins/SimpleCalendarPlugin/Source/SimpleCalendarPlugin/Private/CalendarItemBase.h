#pragma once

#include "CoreMinimal.h"
#include "CalendarRow.h"
#include "Blueprint/UserWidget.h"
#include "CalendarUIBase.h"
#include "CalendarItemBase.generated.h"

/**
 * @class UCalendarItemBase
 * @brief A user interface widget for displaying and managing calendar items.
 *
 * This class handles user interactions with calendar items, such as selecting days
 * of the week, and manages the display of calendar data.
 */
UCLASS()
class UCalendarItemBase : public UUserWidget
{
    GENERATED_BODY()

public:
    /**
     * @brief Constructs the calendar item and binds UI events.
     */
    virtual void NativeConstruct() override;

    /**
     * @brief The currently selected day of the week (e.g., "Sunday", "Monday").
     */
    UPROPERTY(BlueprintReadOnly, Category = "Atm0s Calendar Variables")
    UTextBlock* DaySelected;

    // Functions to Handle Day Clicks

    /**
     * @brief Handles click events for Sunday.
     */
    UFUNCTION()
    void HandleSundayClick();

    /**
     * @brief Handles click events for Monday.
     */
    UFUNCTION()
    void HandleMondayClick();

    /**
     * @brief Handles click events for Tuesday.
     */
    UFUNCTION()
    void HandleTuesdayClick();

    /**
     * @brief Handles click events for Wednesday.
     */
    UFUNCTION()
    void HandleWednesdayClick();

    /**
     * @brief Handles click events for Thursday.
     */
    UFUNCTION()
    void HandleThursdayClick();

    /**
     * @brief Handles click events for Friday.
     */
    UFUNCTION()
    void HandleFridayClick();

    /**
     * @brief Handles click events for Saturday.
     */
    UFUNCTION()
    void HandleSaturdayClick();

    /**
     * @brief Event triggered when a calendar day is selected.
     */
    UFUNCTION(BlueprintImplementableEvent, Category = "Atm0s Calendar Events")
    void OnDaySelected();

    /**
     * @brief Called when a calendar item is added.
     *
     * @param ListItemObjectRef A reference to the list item object being added.
     */
    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void OnItemAdded(UObject* ListItemObjectRef);

    /** The current date and time being managed by the calendar. */
    FDateTime CurrentDateTime;

    /** The current year displayed in the calendar. */
    int32 Year;

    /** The current month displayed in the calendar. */
    int32 Month;

    /** The first day of the week for the current month. */
    int32 FirstDayOfWeek;

    /** Offset used for calculating grid positions in the calendar. */
    int32 Offset;

protected:
    /** Button for selecting Sunday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UButton* Sunday;

    /** Button for selecting Monday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UButton* Monday;

    /** Button for selecting Tuesday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UButton* Tuesday;

    /** Button for selecting Wednesday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UButton* Wednesday;

    /** Button for selecting Thursday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UButton* Thursday;

    /** Button for selecting Friday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UButton* Friday;

    /** Button for selecting Saturday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UButton* Saturday;

    /** Text block for Sunday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UTextBlock* day_0;

    /** Text block for Monday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UTextBlock* day_1;

    /** Text block for Tuesday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UTextBlock* day_2;

    /** Text block for Wednesday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UTextBlock* day_3;

    /** Text block for Thursday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UTextBlock* day_4;

    /** Text block for Friday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UTextBlock* day_5;

    /** Text block for Saturday. */
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Atm0s Calendar Variables")
    class UTextBlock* day_6;

private:
    /**
     * @brief Helper function for calculating row times in the calendar.
     *
     * @param RowIndex The index of the row being processed.
     */
    void RowTimeHelper(int32 RowIndex);

    /**
     * @brief Calculates the offset for a specific row.
     *
     * @param Row The row index.
     * @return The calculated offset.
     */
    int32 CalculateOffset(int32 Row);

    /** The current row index in the calendar. */
    int32 CalendarRow;

    /** The currently selected grid row in the calendar. */
    int32 SelectedGridRow;

    /** The color used for selected grids. */
    FLinearColor sgc_color;

    /** The color used for disabled grids. */
    FLinearColor d_color;

    /** The color used for general grids. */
    FLinearColor g_color;

    /**
     * @brief Sets the text for a specific day in the calendar.
     *
     * @param Selection The selected day.
     * @param Count The current count of the day.
     */
    void SetDayText(int32 Selection, int32& Count);

    /**
     * @brief Helper function to set calendar item properties.
     *
     * @param Selection The selected day index.
     * @param Date The date to set for the day.
     */
    void SetCalendarItemHelper(int32 Selection, FText Date);

    /**
     * @brief Binds click handlers for calendar items.
     */
    void HandleCalendarItemClick();

    /**
     * @brief Enables all calendar day grids.
     */
    void EnableGrids();

    /**
     * @brief Disables calendar grids that are empty or inactive.
     */
    void DisableGrids();

    /**
     * @brief Initializes a calendar row with the given properties.
     *
     * @param row The row index.
     * @param year The year for the calendar row.
     * @param month The month for the calendar row.
     * @param SelectedGridColor The color for selected grids.
     * @param EmptyGridColor The color for empty grids.
     * @param GridColor The default grid color.
     * @param InOwner The owner widget of the calendar row.
     */
    void InitializeCalendarRow(int32 row, int32 year, int32 month, FLinearColor SelectedGridColor, FLinearColor EmptyGridColor, FLinearColor GridColor, UCalendarUIBase* InOwner);

    /** The owner widget for this calendar item. */
    UCalendarUIBase* Owner;

    /** The time of the currently clicked day. */
    FDateTime ClickedTime;
};
