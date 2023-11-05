#include "MyUserWidget.h"
#include "Misc/DateTime.h"
#include "Containers/Map.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


void UMyUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // click on calendar events
    if (Sunday)
    {
        Sunday->OnClicked.AddDynamic(this, &UMyUserWidget::HandleSundayClick);
    }
    if (Monday)
    {
        Monday->OnClicked.AddDynamic(this, &UMyUserWidget::HandleMondayClick);
    }
    if (Tuesday)
    {
        Tuesday->OnClicked.AddDynamic(this, &UMyUserWidget::HandleTuesdayClick);
    }
    if (Wednesday)
    {
        Wednesday->OnClicked.AddDynamic(this, &UMyUserWidget::HandleWednesdayClick);
    }
    if (Thursday)
    {
        Thursday->OnClicked.AddDynamic(this, &UMyUserWidget::HandleThursdayClick);
    }
    if (Friday)
    {
        Friday->OnClicked.AddDynamic(this, &UMyUserWidget::HandleFridayClick);
    }
    if (Saturday)
    {
        Saturday->OnClicked.AddDynamic(this, &UMyUserWidget::HandleSaturdayClick);
    }
}

void UMyUserWidget::HandleSundayClick()
{
    DaySelected = "Sunday";

    OnDaySelected();
}

void UMyUserWidget::HandleMondayClick()
{
    DaySelected = "Monday";
    OnDaySelected();
}

void UMyUserWidget::HandleTuesdayClick()
{
    DaySelected = "Tuesday";
    OnDaySelected();
}

void UMyUserWidget::HandleWednesdayClick()
{
    DaySelected = "Wednesday";
    OnDaySelected();
}

void UMyUserWidget::HandleThursdayClick()
{
    DaySelected = "Thursday";
    OnDaySelected();
}

void UMyUserWidget::HandleFridayClick()
{
    DaySelected = "Friday";
    OnDaySelected();
}

void UMyUserWidget::HandleSaturdayClick()
{
    DaySelected = "Saturday";
    OnDaySelected();
}

void UMyUserWidget::InitializeCalendarRow(int32 RowIndex)
{
    CurrentDateTime = FDateTime::Now();
    Year = CurrentDateTime.GetYear();  // temp
    Month = CurrentDateTime.GetMonth();   // temp
    FDateTime FirstDayOfMonth(Year, Month, 1);
    FirstDayOfWeek = static_cast<int32>(FirstDayOfMonth.GetDayOfWeek());
    Offset = CalculateOffset(RowIndex);
    int32 Day = CurrentDateTime.GetDay();

    LastDayOfMonth = CurrentDateTime.DaysInMonth(Year, Month);

  

    for (int32 DayIndex = 0; DayIndex <= 6; DayIndex++)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("The day index : %d"), DayIndex));
        }
        if (RowIndex != 0)
        {
            int32 Count = 0;
            SetDayText(DayIndex, Count);
        }
    }

 /*   if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("The integer value is: %d"), RowIndex));
    }*/
}

int32 UMyUserWidget::CalculateOffset(int32 RowIndex)
{
    int32 CalculatedOffset = 0;
    if (RowIndex != 0)
    {
        CalculatedOffset = RowIndex * 7 - FirstDayOfWeek;
    }
    return CalculatedOffset;
}

void UMyUserWidget::SetDayText(int32 DayIndex, int32& Count)
{
    bool IsWithinMonth = (Offset + Count) <= LastDayOfMonth;

    if (IsWithinMonth)
    {
        SetDayTextHelper(DayIndex, Count);
    }
}

void UMyUserWidget::SetDayTextHelper(int32 Selection, int32& Count)
{
    int32 Date = Offset + Count;
    // Colors
    FLinearColor DisabledColor(0.5f, 0.5f, 0.5f, 1.0f);
    FLinearColor SelectedColor(0.1f, 0.9f, 0.1f, 1.0f);
    FLinearColor GridColor(0.15f, 0.15f, 0.7f, 0.7f);

    if (Selection == 0) {
        day_0->SetText(FText::AsNumber(Date));
        if (Date == FDateTime::Now().GetDay())
        {
            Sunday->WidgetStyle.Normal.TintColor = FSlateColor(SelectedColor);
        }
        else
        {
            Sunday->WidgetStyle.Normal.TintColor = FSlateColor(GridColor);
        }
    }
    else if(Selection == 1){
        day_1->SetText(FText::AsNumber(Date));
        if (Date == FDateTime::Now().GetDay())
        {
            Monday->WidgetStyle.Normal.TintColor = FSlateColor(SelectedColor);
        }
        else
        {
            Monday->WidgetStyle.Normal.TintColor = FSlateColor(GridColor);
        }
    }
    else if (Selection == 2) {
        day_2->SetText(FText::AsNumber(Date));
        if (Date == FDateTime::Now().GetDay())
        {
            Tuesday->WidgetStyle.Normal.TintColor = FSlateColor(SelectedColor);
        }
        else
        {
            Tuesday->WidgetStyle.Normal.TintColor = FSlateColor(GridColor);
        }
    }
    Count += 1;
}

