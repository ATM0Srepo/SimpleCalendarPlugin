#include "CalendarItemBase.h"
#include "Misc/DateTime.h"
#include "Containers/Map.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"


void UCalendarItemBase::NativeConstruct()
{
    Super::NativeConstruct();
    HandleCalendarItemClick();
}

void UCalendarItemBase::HandleCalendarItemClick()
{
    // click on calendar events
    if (Sunday)
    {
        Sunday->OnClicked.AddDynamic(this, &UCalendarItemBase::HandleSundayClick);
    }
    if (Monday)
    {
        Monday->OnClicked.AddDynamic(this, &UCalendarItemBase::HandleMondayClick);
    }
    if (Tuesday)
    {
        Tuesday->OnClicked.AddDynamic(this, &UCalendarItemBase::HandleTuesdayClick);
    }
    if (Wednesday)
    {
        Wednesday->OnClicked.AddDynamic(this, &UCalendarItemBase::HandleWednesdayClick);
    }
    if (Thursday)
    {
        Thursday->OnClicked.AddDynamic(this, &UCalendarItemBase::HandleThursdayClick);
    }
    if (Friday)
    {
        Friday->OnClicked.AddDynamic(this, &UCalendarItemBase::HandleFridayClick);
    }
    if (Saturday)
    {
        Saturday->OnClicked.AddDynamic(this, &UCalendarItemBase::HandleSaturdayClick);
    }
}


void UCalendarItemBase::HandleSundayClick()
{
   DaySelected = day_0;
   ClickedTime = Owner->GetTime();

   FString DayText = DaySelected->GetText().ToString();
   int32 DayValue = FCString::Atoi(*DayText);

   ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());

    OnDaySelected();
}

void UCalendarItemBase::HandleMondayClick()
{
    DaySelected = day_1;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

void UCalendarItemBase::HandleTuesdayClick()
{
    DaySelected = day_2;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

void UCalendarItemBase::HandleWednesdayClick()
{
    DaySelected = day_3;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

void UCalendarItemBase::HandleThursdayClick()
{
    DaySelected = day_4;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

void UCalendarItemBase::HandleFridayClick()
{
    DaySelected = day_5;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

void UCalendarItemBase::HandleSaturdayClick()
{
    DaySelected = day_6;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

void UCalendarItemBase::EnableGrids()
{
    Sunday->SetIsEnabled(true);
    Monday->SetIsEnabled(true);
    Tuesday->SetIsEnabled(true);
    Wednesday->SetIsEnabled(true);
    Thursday->SetIsEnabled(true);
    Friday->SetIsEnabled(true);
    Saturday->SetIsEnabled(true);
}

void UCalendarItemBase::DisableGrids()
{
    if ((day_0->GetText()).IsEmptyOrWhitespace())
    {
        Sunday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Sunday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Sunday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Sunday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Sunday->SetIsEnabled(false);
    }
    if ((day_1->GetText()).IsEmptyOrWhitespace())
    {
        Monday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Monday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Monday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Monday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Monday->SetIsEnabled(false);

    }
    if ((day_2->GetText()).IsEmptyOrWhitespace())
    {
        Tuesday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Tuesday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Tuesday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Tuesday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Tuesday->SetIsEnabled(false);

    }
    if ((day_3->GetText()).IsEmptyOrWhitespace())
    {
        Wednesday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Wednesday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Wednesday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Wednesday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Wednesday->SetIsEnabled(false);

    }
    if ((day_4->GetText()).IsEmptyOrWhitespace())
    {
        Thursday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Thursday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Thursday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Thursday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Thursday->SetIsEnabled(false);

    }
    if ((day_5->GetText()).IsEmptyOrWhitespace())
    {
        Friday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Friday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Friday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Friday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Friday->SetIsEnabled(false);

    }
    if ((day_6->GetText()).IsEmptyOrWhitespace())
    {
        Saturday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Saturday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Saturday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Saturday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Saturday->SetIsEnabled(false);

    }
}

void UCalendarItemBase::OnItemAdded(UObject* ListItemObjectRef)
{
    if (ListItemObjectRef)
    {
        UCalendarRow* CalendarRowInstance = Cast<UCalendarRow>(ListItemObjectRef);
        if (CalendarRowInstance)
        {
            InitializeCalendarRow(CalendarRowInstance->structure.Row, 
                CalendarRowInstance->structure.Year, 
                CalendarRowInstance->structure.Month, 
                CalendarRowInstance->structure.SelectedGridColor, 
                CalendarRowInstance->structure.EmptyGridColor, 
                CalendarRowInstance->structure.GridColor,
                CalendarRowInstance->Owner);
        }
    }
}

void UCalendarItemBase::InitializeCalendarRow(int32 RowIndex, int32 year, int32 month, FLinearColor SelectedGridColor, FLinearColor EmptyGridColor, FLinearColor GridColor, UCalendarUIBase* InOwner)
{
    EnableGrids();
    CalendarRow = RowIndex;
    sgc_color = SelectedGridColor;
    d_color = EmptyGridColor;
    g_color = GridColor;
    Year = year;
    Month = month;
    int32 Day = FDateTime::Now().GetDay();
    CurrentDateTime = FDateTime(Year, Month, Day);
    RowTimeHelper(RowIndex);
    Owner = InOwner;
}

void UCalendarItemBase::RowTimeHelper(int32 RowIndex)
{
    FDateTime FirstDayOfMonth(Year, Month, 1);
    FirstDayOfWeek = static_cast<int32>(FirstDayOfMonth.GetDayOfWeek());
    if (FirstDayOfWeek == 6) {
        FirstDayOfWeek = 0;
    }
    else {
        FirstDayOfWeek += 1;
    }
    Offset = CalculateOffset(RowIndex);
    int32 Count = 1;
    for (int32 DayIndex = 0; DayIndex <= 6; DayIndex++)
    {
        if (!((RowIndex == 0) && (FirstDayOfWeek > DayIndex)))
        {
            SetDayText(DayIndex, Count);
        }
        else {
            SetCalendarItemHelper(DayIndex, FText::FromString(TEXT("")));
        }
    }

    DisableGrids();
}

int32 UCalendarItemBase::CalculateOffset(int32 RowIndex)
{
    int32 CalculatedOffset = 0;
    if (RowIndex != 0)
    {
        CalculatedOffset = RowIndex * 7 - FirstDayOfWeek;
    }
    return CalculatedOffset;
}

void UCalendarItemBase::SetDayText(int32 DayIndex, int32& Count)
{
    bool IsWithinMonth = (Offset + Count) <= CurrentDateTime.DaysInMonth(Year, Month);
    int32 Date = Offset + Count;

    if (IsWithinMonth && !(Date == 0))
    {
        SetCalendarItemHelper(DayIndex, FText::AsNumber(Date));
    }
    else {
        SetCalendarItemHelper(DayIndex, FText::FromString(TEXT("")));
    }
    Count += 1;
}

void UCalendarItemBase::SetCalendarItemHelper(int32 Selection, FText Date)
{
    // Colors
    FLinearColor GridColor(0.45f, 0.2f, 0.1f, 0.7f);

    if (Selection == 0) {
        day_0->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Sunday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
            SelectedGridRow = CalendarRow;
        }
        else
        {
            Sunday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    else if ((Selection == 1)) {
        day_1->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Monday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
            SelectedGridRow = CalendarRow;
        }
        else
        {
            Monday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    else if (Selection == 2 ) {
        day_2->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Tuesday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
            SelectedGridRow = CalendarRow;
        }
        else
        {
            Tuesday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    else if (Selection == 3) {
        day_3->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Wednesday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
            SelectedGridRow = CalendarRow;
        }
        else
        {
            Wednesday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    else if (Selection == 4) {
        day_4->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Thursday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
            SelectedGridRow = CalendarRow;
        }
        else
        {
            Thursday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    else if (Selection == 5) {
        day_5->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Friday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
            SelectedGridRow = CalendarRow;
        }
        else
        {
            Friday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    else if (Selection == 6) {
        day_6->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Saturday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
            SelectedGridRow = CalendarRow;
        }
        else
        {
            Saturday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }

}


