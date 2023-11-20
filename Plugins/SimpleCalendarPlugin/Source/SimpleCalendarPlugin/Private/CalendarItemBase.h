#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CalendarItemBase.generated.h"

/**
 * 
 */

UCLASS()
class UCalendarItemBase : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    /** The current selection of the day of week on Calendar (eg. "Sunday", "Monday", etc */
    UPROPERTY(BlueprintReadOnly, Category = "Atm0s Calendar Variables")
    FString DaySelected;

    /** The day of the week that month in view begins with */
  /*  UPROPERTY(BlueprintReadOnly, Category = "Atm0s Calendar Variables")
    FString StartDayOfMonth;*/

    // Functions to Handle Day Clicks
    UFUNCTION()
    void HandleSundayClick();

    UFUNCTION()
    void HandleMondayClick();

    UFUNCTION()
    void HandleTuesdayClick();

    UFUNCTION()
    void HandleWednesdayClick();

    UFUNCTION()
    void HandleThursdayClick();

    UFUNCTION()
    void HandleFridayClick();

    UFUNCTION()
    void HandleSaturdayClick();

    UFUNCTION()
    void DisableGrids();

    // Overridable event
    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnDaySelected();

    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void InitializeCalendarRow(int32 row);

    FDateTime CurrentDateTime;
    int32 Year;  // temp
    int32 Month;   // temp
    int32 FirstDayOfWeek;

    int32 Offset;


protected:
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UButton* Sunday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UButton* Monday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UButton* Tuesday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UButton* Wednesday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UButton* Thursday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UButton* Friday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UButton* Saturday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UTextBlock* day_0;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UTextBlock* day_1;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UTextBlock* day_2;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UTextBlock* day_3;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UTextBlock* day_4;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UTextBlock* day_5;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Variables")
    class UTextBlock* day_6;

private:
    int32 CalculateOffset(int32 Row);
    void SetDayText(int32 Selection, int32& Count);
    void SetDayTextHelper(int32 Selection, int32 Date);
    void HandleClickEvents();
};
