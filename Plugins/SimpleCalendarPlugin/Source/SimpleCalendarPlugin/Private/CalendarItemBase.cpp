#include "CalendarItemBase.h"
#include "Misc/DateTime.h"
#include "Containers/Map.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

/**
 * @brief Initializes the calendar item and binds UI events.
 */
void UCalendarItemBase::NativeConstruct()
{
    Super::NativeConstruct();
    HandleCalendarItemClick();
}

/**
 * @brief Binds click handlers for all calendar day buttons.
 */
void UCalendarItemBase::HandleCalendarItemClick()
{
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

// Click Handlers for Days

/**
 * @brief Handles click events for Sunday.
 */
void UCalendarItemBase::HandleSundayClick()
{
    DaySelected = day_0;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());

    OnDaySelected();
}

/**
 * @brief Handles click events for Monday.
 */
void UCalendarItemBase::HandleMondayClick()
{
    DaySelected = day_1;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

/**
 * @brief Handles click events for Tuesday.
 */
void UCalendarItemBase::HandleTuesdayClick()
{
    DaySelected = day_2;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

/**
 * @brief Handles click events for Wednesday.
 */
void UCalendarItemBase::HandleWednesdayClick()
{
    DaySelected = day_3;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

/**
 * @brief Handles click events for Thursday.
 */
void UCalendarItemBase::HandleThursdayClick()
{
    DaySelected = day_4;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

/**
 * @brief Handles click events for Friday.
 */
void UCalendarItemBase::HandleFridayClick()
{
    DaySelected = day_5;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

/**
 * @brief Handles click events for Saturday.
 */
void UCalendarItemBase::HandleSaturdayClick()
{
    DaySelected = day_6;
    ClickedTime = Owner->GetTime();

    FString DayText = DaySelected->GetText().ToString();
    int32 DayValue = FCString::Atoi(*DayText);

    ClickedTime = FDateTime(ClickedTime.GetYear(), ClickedTime.GetMonth(), DayValue, ClickedTime.GetHour(), ClickedTime.GetMinute(), ClickedTime.GetSecond());
    OnDaySelected();
}

// Grid Management

/**
 * @brief Enables all day grid buttons.
 */
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

/**
 * @brief Disables day grids based on the presence of text in their corresponding blocks.
 */
void UCalendarItemBase::DisableGrids()
{
    if (day_0->GetText().IsEmptyOrWhitespace())
    {
        Sunday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Sunday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Sunday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Sunday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Sunday->SetIsEnabled(false);
    }
    if (day_1->GetText().IsEmptyOrWhitespace())
    {
        Monday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Monday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Monday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Monday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Monday->SetIsEnabled(false);
    }
    if (day_2->GetText().IsEmptyOrWhitespace())
    {
        Tuesday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Tuesday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Tuesday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Tuesday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Tuesday->SetIsEnabled(false);
    }
    if (day_3->GetText().IsEmptyOrWhitespace())
    {
        Wednesday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Wednesday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Wednesday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Wednesday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Wednesday->SetIsEnabled(false);
    }
    if (day_4->GetText().IsEmptyOrWhitespace())
    {
        Thursday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Thursday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Thursday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Thursday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Thursday->SetIsEnabled(false);
    }
    if (day_5->GetText().IsEmptyOrWhitespace())
    {
        Friday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Friday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Friday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Friday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Friday->SetIsEnabled(false);
    }
    if (day_6->GetText().IsEmptyOrWhitespace())
    {
        Saturday->WidgetStyle.Normal.TintColor = FSlateColor(d_color);
        Saturday->WidgetStyle.Hovered.TintColor = FSlateColor(d_color);
        Saturday->WidgetStyle.Pressed.TintColor = FSlateColor(d_color);
        Saturday->WidgetStyle.Disabled.TintColor = FSlateColor(d_color);
        Saturday->SetIsEnabled(false);
    }
}

/**
 * @brief Adds a calendar item to the UI.
 *
 * @param ListItemObjectRef A reference to the list item object.
 */
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

/**
 * @brief Initializes a calendar row with the specified properties.
 *
 * @param RowIndex The index of the row.
 * @param year The year of the calendar row.
 * @param month The month of the calendar row.
 * @param SelectedGridColor The color for selected grids.
 * @param EmptyGridColor The color for empty grids.
 * @param GridColor The default grid color.
 * @param InOwner The owning calendar UI.
 */
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

/**
 * @brief Calculates the time offset for a calendar row.
 *
 * @param RowIndex The index of the row.
 */
void UCalendarItemBase::RowTimeHelper(int32 RowIndex)
{
    FDateTime FirstDayOfMonth(Year, Month, 1);
    FirstDayOfWeek = static_cast<int32>(FirstDayOfMonth.GetDayOfWeek());
    if (FirstDayOfWeek == 6)
    {
        FirstDayOfWeek = 0;
    }
    else
    {
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
        else
        {
            SetCalendarItemHelper(DayIndex, FText::FromString(TEXT("")));
        }
    }

    DisableGrids();
}

/**
 * @brief Calculates the offset for a given row.
 *
 * @param RowIndex The index of the row.
 * @return The calculated offset.
 */
int32 UCalendarItemBase::CalculateOffset(int32 RowIndex)
{
    int32 CalculatedOffset = 0;
    if (RowIndex != 0)
    {
        CalculatedOffset = RowIndex * 7 - FirstDayOfWeek;
    }
    return CalculatedOffset;
}

/**
 * @brief Sets the text for a specific day in the calendar.
 *
 * @param DayIndex The index of the day.
 * @param Count The count for the day.
 */
void UCalendarItemBase::SetDayText(int32 DayIndex, int32& Count)
{
    bool IsWithinMonth = (Offset + Count) <= CurrentDateTime.DaysInMonth(Year, Month);
    int32 Date = Offset + Count;

    if (IsWithinMonth && !(Date == 0))
    {
        SetCalendarItemHelper(DayIndex, FText::AsNumber(Date));
    }
    else
    {
        SetCalendarItemHelper(DayIndex, FText::FromString(TEXT("")));
    }
    Count += 1;
}

/**
 * @brief Updates the display properties for a calendar item.
 *
 * @param Selection The selected day index.
 * @param Date The date text for the day.
 */
void UCalendarItemBase::SetCalendarItemHelper(int32 Selection, FText Date)
{
    if (Selection == 0)
    {
        day_0->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Sunday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
        }
        else
        {
            Sunday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    if (Selection == 1)
    {
        day_1->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Monday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
        }
        else
        {
            Monday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    if (Selection == 2)
    {
        day_2->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Tuesday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
        }
        else
        {
            Tuesday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    if (Selection == 3)
    {
        day_3->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Wednesday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
        }
        else
        {
            Wednesday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    if (Selection == 4)
    {
        day_4->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Thursday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
        }
        else
        {
            Thursday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    if (Selection == 5)
    {
        day_5->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Friday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
        }
        else
        {
            Friday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
    if (Selection == 6)
    {
        day_6->SetText(Date);
        if (Date.ToString() == FText::AsNumber(FDateTime::Now().GetDay()).ToString())
        {
            Saturday->WidgetStyle.Normal.TintColor = FSlateColor(sgc_color);
        }
        else
        {
            Saturday->WidgetStyle.Normal.TintColor = FSlateColor(g_color);
        }
    }
}
