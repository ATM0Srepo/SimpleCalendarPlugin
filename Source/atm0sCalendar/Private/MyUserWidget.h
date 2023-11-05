#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FMyBaseSructure
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, Category = "Structures")
    int32 row;
};


UCLASS()
class UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UPROPERTY(BlueprintReadOnly, Category = "Calendar Variables")
    FString DaySelected;

    UPROPERTY(BlueprintReadOnly, Category = "Calendar Variables")
    FString StartDayOfMonth;

    UPROPERTY(BlueprintReadWrite, Category = "Calendar Variables")
    int32 Offset;

    UPROPERTY(BlueprintReadWrite, Category = "Calendar Variables")
    int32 LastDayOfMonth;

    // Function to Handle Day Clicks
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

    // Overridable event
    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnDaySelected();

    UFUNCTION(BlueprintCallable, Category = "Calendar Functions")
    void InitializeCalendarRow(int32 row);

    FDateTime CurrentDateTime;
    int32 Year;  // temp
    int32 Month;   // temp
    int32 FirstDayOfWeek;


protected:
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Sunday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Monday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Tuesday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Wednesday;
	
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Thursday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Friday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Saturday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UTextBlock* day_0;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UTextBlock* day_1;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UTextBlock* day_2;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    FMyBaseSructure structure;

private:
    void GetStartDayOfMonth(int32 Year, int32 Month);
    int32 CalculateOffset(int32 Row);
    void SetDayText(int32 Selection, int32& Count);
    void SetDayTextHelper(int32 Selection, int32& Count);
};
