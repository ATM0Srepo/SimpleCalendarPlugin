#include "MyUserWidget.h"
#include "Misc/DateTime.h"
#include "Containers/Map.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


void UMyUserWidget::NativeConstruct()
{
    Super::NativeConstruct();
    HandleClickEvents();
}

void UMyUserWidget::HandleClickEvents()
{
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

void UMyUserWidget::DisableGrids()
{
    FLinearColor DisabledColor(0.0f, 0.0f, 0.0f, 1.0f);
    if ((day_0->GetText()).IsEmptyOrWhitespace())
    {
        Sunday->SetIsEnabled(false);
    }
    if ((day_1->GetText()).IsEmptyOrWhitespace())
    {
        Monday->SetIsEnabled(false);
    }
    if ((day_2->GetText()).IsEmptyOrWhitespace())
    {
        Tuesday->SetIsEnabled(false);
    }
    if ((day_3->GetText()).IsEmptyOrWhitespace())
    {
        Wednesday->SetIsEnabled(false);
    }
    if ((day_4->GetText()).IsEmptyOrWhitespace())
    {
        Thursday->SetIsEnabled(false);
    }
    if ((day_5->GetText()).IsEmptyOrWhitespace())
    {
        Friday->SetIsEnabled(false);
    }
    if ((day_6->GetText()).IsEmptyOrWhitespace())
    {
        Saturday->SetIsEnabled(false);
    }
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
    int32 Count = 0;

    for (int32 DayIndex = 0; DayIndex <= 6; DayIndex++)
    {
        if (!((RowIndex == 0) && (FirstDayOfWeek > DayIndex)))
        {
            SetDayText(DayIndex, Count);
        }
    }

    DisableGrids();
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
    int32 Date = Offset + Count;

    if (IsWithinMonth && !(Date == 0))
    {
        SetDayTextHelper(DayIndex, Date);
    }
    Count += 1;
}

void UMyUserWidget::SetDayTextHelper(int32 Selection, int32 Date)
{
    // Colors
    FLinearColor SelectedColor(1.0f, 1.0f, 1.0f, 0.7f);
    FLinearColor GridColor(0.45f, 0.2f, 0.1f, 0.7f);

    if (Selection == 0) {
        day_0->SetText(FText::AsNumber(Date));
        if (Date == FDateTime::Now().GetDay())
        {
            Sunday->WidgetStyle.Normal.TintColor = FSlateColor(SelectedColor);
            TodayButton = Sunday;
        }
        else
        {
            Sunday->WidgetStyle.Normal.TintColor = FSlateColor(GridColor);
        }
    }
    else if (Selection == 1) {
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
    else if (Selection == 3) {
        day_3->SetText(FText::AsNumber(Date));
        if (Date == FDateTime::Now().GetDay())
        {
            Wednesday->WidgetStyle.Normal.TintColor = FSlateColor(SelectedColor);
        }
        else
        {
            Wednesday->WidgetStyle.Normal.TintColor = FSlateColor(GridColor);
        }
    }
    else if (Selection == 4) {
        day_4->SetText(FText::AsNumber(Date));
        if (Date == FDateTime::Now().GetDay())
        {
            Thursday->WidgetStyle.Normal.TintColor = FSlateColor(SelectedColor);
        }
        else
        {
            Thursday->WidgetStyle.Normal.TintColor = FSlateColor(GridColor);
        }
    }
    else if (Selection == 5) {
        day_5->SetText(FText::AsNumber(Date));
        if (Date == FDateTime::Now().GetDay())
        {
            Friday->WidgetStyle.Normal.TintColor = FSlateColor(SelectedColor);
        }
        else
        {
            Friday->WidgetStyle.Normal.TintColor = FSlateColor(GridColor);
        }
    }
    else if (Selection == 6) {
        day_6->SetText(FText::AsNumber(Date));
        if (Date == FDateTime::Now().GetDay())
        {
            Saturday->WidgetStyle.Normal.TintColor = FSlateColor(SelectedColor);
        }
        else
        {
            Saturday->WidgetStyle.Normal.TintColor = FSlateColor(GridColor);
        }
    }

}

