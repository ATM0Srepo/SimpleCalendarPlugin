#include "CalendarUIBase.h"
#include "Misc/DateTime.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Containers/Map.h"
#include "CalendarRow.h"
#include "Components/ListView.h"
#include "TimerManager.h" 
#include "Engine/World.h"

/**
 * @brief Initializes the calendar widget and binds UI events.
 */
void UCalendarUIBase::NativeConstruct()
{
    Super::NativeConstruct();
    MonthMap2 = {
        {TEXT("Jan"), 1}, {TEXT("Feb"), 2}, {TEXT("Mar"), 3}, {TEXT("Apr"), 4},
        {TEXT("May"), 5}, {TEXT("Jun"), 6}, {TEXT("Jul"), 7}, {TEXT("Aug"), 8},
        {TEXT("Sep"), 9}, {TEXT("Oct"), 10}, {TEXT("Nov"), 11}, {TEXT("Dec"), 12}
    };

    PreCalendarConfig(
        FLinearColor(1.0f, 1.0f, 1.0f, 0.8f),
        FLinearColor(0.0f, 0.0f, 0.0f, 1.0f),
        FLinearColor(0.45f, 0.2f, 0.1f, 0.7f)
    );

    toggle_prev_month->SetVisibility(ESlateVisibility::Collapsed);
    toggle_prev_month->OnClicked.AddDynamic(this, &UCalendarUIBase::ShowPrevMonth);
    toggle_next_month->SetVisibility(ESlateVisibility::Collapsed);
    toggle_next_month->OnClicked.AddDynamic(this, &UCalendarUIBase::ShowNextMonth);

    InitializeYear(FDateTime::Now().GetYear());
    year->OnTextCommitted.AddDynamic(this, &UCalendarUIBase::HandleOnYearChanged);

    InitializeMonth(FDateTime::Now().GetMonth());
    MonthButton->OnClicked.AddDynamic(this, &UCalendarUIBase::HandleMonthToggleButtonClick);

    hourDifference = FDateTime::Now() - FDateTime::Now();
    minuteDifference = FDateTime::Now() - FDateTime::Now();
    InitializeHour();
    GetWorld()->GetTimerManager().SetTimer(TickTimerHandle, this, &UCalendarUIBase::InitializeMinute, DefaultMinuteTickInterval, true);
}

/**
 * @brief Initializes the hour text box with the current hour.
 */
void UCalendarUIBase::InitializeHour()
{
    hour_now = FString::FormatAsNumber((FDateTime::Now() - hourDifference).GetHour());

    if (hour_now.Len() < 2) {
        hour_now = "0" + hour_now;
    }

    hour->SetText(FText::FromString(hour_now));
}

/**
 * @brief Initializes the minute text box with the current minute.
 */
void UCalendarUIBase::InitializeMinute()
{
    minute_now = FString::FormatAsNumber((FDateTime::Now() - minuteDifference).GetMinute());

    if (minute_now.Len() < 2) {
        minute_now = "0" + minute_now;
    }
    minute->SetText(FText::FromString(minute_now));
    if (minute_now == "00") {
        InitializeHour();
    }
}

/**
 * @brief Sets the calendar year.
 * @param y The year to set.
 */
void UCalendarUIBase::InitializeYear(int y)
{
    year_now = y;
    year->SetText(FText::FromString(FString::FormatAsNumber(y).Replace(TEXT(","), TEXT(""))));
}

/**
 * @brief Sets the calendar month.
 * @param m The month to set (1-12).
 */
void UCalendarUIBase::InitializeMonth(int m)
{
    TMap<int32, FString> MonthMap = {
        {1, TEXT("Jan")}, {2, TEXT("Feb")}, {3, TEXT("Mar")}, {4, TEXT("Apr")},
        {5, TEXT("May")}, {6, TEXT("Jun")}, {7, TEXT("Jul")}, {8, TEXT("Aug")},
        {9, TEXT("Sep")}, {10, TEXT("Oct")}, {11, TEXT("Nov")}, {12, TEXT("Dec")}
    };
    month_now = m;
    month->SetText(FText::FromString(*MonthMap.Find(m)));
}

/**
 * @brief Configures corner radii for the calendar and weekday headers.
 *
 * @param CalendarBorder Corner radii for the calendar border.
 * @param WeekdayHeaderRadii Corner radii for the weekday headers.
 */
void UCalendarUIBase::SetCornerRadii(const FVector4& CalendarBorder, const FVector4& WeekdayHeaderRadii)
{
    FButtonStyle CalendarStyle = calendar_background->WidgetStyle;
    CalendarStyle.Normal.OutlineSettings.CornerRadii = CalendarBorder;
    CalendarStyle.Hovered.OutlineSettings.CornerRadii = CalendarBorder;
    CalendarStyle.Pressed.OutlineSettings.CornerRadii = CalendarBorder;
    calendar_background->SetStyle(CalendarStyle);

    FButtonStyle WeekdayStyle = weekdays_background->WidgetStyle;
    WeekdayStyle.Normal.OutlineSettings.CornerRadii = WeekdayHeaderRadii;
    WeekdayStyle.Hovered.OutlineSettings.CornerRadii = WeekdayHeaderRadii;
    WeekdayStyle.Pressed.OutlineSettings.CornerRadii = WeekdayHeaderRadii;
    weekdays_background->SetStyle(WeekdayStyle);
}

/**
 * @brief Retrieves the current DateTime set in the calendar.
 * @return The current DateTime object.
 */
FDateTime UCalendarUIBase::GetTime()
{
    return FDateTime(year_now, month_now, FDateTime::Now().GetDay(), FCString::Atoi(*hour_now), FCString::Atoi(*minute_now), 0, 0);
}

/**
 * @brief Handles changes to the year text box.
 *
 * @param Text The new year value.
 * @param CommitMethod The method of text commit.
 */
void UCalendarUIBase::HandleOnYearChanged(const FText& Text, ETextCommit::Type CommitMethod)
{
    if (CommitMethod == ETextCommit::OnEnter) {
        year_now = FCString::Atoi(*Text.ToString());
        ListViewCalendar->ClearListItems();
        CreateCalendar();
    }
}

/**
 * @brief Toggles the visibility of month navigation buttons.
 */
void UCalendarUIBase::HandleMonthToggleButtonClick()
{
    if (toggle_prev_month->IsVisible()) {
        toggle_prev_month->SetVisibility(ESlateVisibility::Collapsed);
        toggle_next_month->SetVisibility(ESlateVisibility::Collapsed);
    }
    else {
        toggle_prev_month->SetVisibility(ESlateVisibility::Visible);
        toggle_next_month->SetVisibility(ESlateVisibility::Visible);
    }
}

/**
 * @brief Configures calendar style settings.
 *
 * @param SelectedGridColor Color for selected grids.
 * @param EmptyGridColor Color for empty grids.
 * @param GridColor Default grid color.
 * @param CalendarBackground Background color for the calendar.
 * @param CalendarBackgroundBorder Border color for the calendar background.
 * @param WeekdayHeadingColor Color for weekday headers.
 */
void UCalendarUIBase::PreCalendarConfig(FLinearColor SelectedGridColor, FLinearColor EmptyGridColor, FLinearColor GridColor, FLinearColor CalendarBackgroundColor, FLinearColor CalendarBackgroundBorderColor, FLinearColor WeekdayHeadingColor)
{
    color1 = SelectedGridColor;
    color2 = EmptyGridColor;
    color3 = GridColor;

    FButtonStyle CalendarStyle = calendar_background->WidgetStyle;
    CalendarStyle.Normal.TintColor = FSlateColor(CalendarBackgroundColor);
    CalendarStyle.Hovered.TintColor = FSlateColor(CalendarBackgroundColor);
    CalendarStyle.Pressed.TintColor = FSlateColor(CalendarBackgroundColor);
    CalendarStyle.Normal.OutlineSettings.Color = FSlateColor(CalendarBackgroundBorderColor);
    CalendarStyle.Hovered.OutlineSettings.Color = FSlateColor(CalendarBackgroundBorderColor);
    CalendarStyle.Pressed.OutlineSettings.Color = FSlateColor(CalendarBackgroundBorderColor);
    calendar_background->SetStyle(CalendarStyle);

    FButtonStyle WeekdayStyle = weekdays_background->WidgetStyle;
    WeekdayStyle.Normal.TintColor = FSlateColor(WeekdayHeadingColor);
    WeekdayStyle.Hovered.TintColor = FSlateColor(WeekdayHeadingColor);
    WeekdayStyle.Pressed.TintColor = FSlateColor(WeekdayHeadingColor);
    weekdays_background->SetStyle(WeekdayStyle);
}

/**
 * @brief Creates the calendar UI by populating rows.
 */
void UCalendarUIBase::CreateCalendar()
{
    for (int32 i = 0; i <= 5; ++i) {
        UCalendarRow* CalendarRowInstance = NewObject<UCalendarRow>(this, UCalendarRow::StaticClass());
        if (CalendarRowInstance != nullptr) {
            CalendarRowInstance->Init(i, year_now, month_now, color1, color2, color3, this);
            ListViewCalendar->AddItem(CalendarRowInstance);
        }
    }
}

/**
 * @brief Updates the year and refreshes the calendar.
 * @param y The new year.
 */
void UCalendarUIBase::SetYear(int y)
{
    InitializeYear(y);
}

/**
 * @brief Updates the month and refreshes the calendar.
 * @param m The new month (1-12).
 */
void UCalendarUIBase::SetMonth(int32 m)
{
    InitializeMonth(m);
    ListViewCalendar->ClearListItems();
    CreateCalendar();
}

/**
 * @brief Handles the event when the hour is committed (e.g., user presses Enter).
 *
 * @param Text The new hour value entered.
 * @param CommitMethod The method of text commit (e.g., OnEnter).
 */
void UCalendarUIBase::HandleOnHourCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
    if (CommitMethod == ETextCommit::OnEnter) {
        hour_now = Text.ToString();
        if (hour_now.Len() <= 2) {
            FDateTime new_hour = FDateTime(FDateTime::Now().GetYear(), FDateTime::Now().GetMonth(), FDateTime::Now().GetDay(), FCString::Atoi(*hour_now), 0, 0, 0);
            hourDifference = FDateTime::Now() - new_hour;
        }
        GetWorld()->GetTimerManager().SetTimer(TickTimerHandle, this, &UCalendarUIBase::InitializeMinute, DefaultMinuteTickInterval, true);
    }
}
/**
 * @brief Handles changes to the hour text box.
 *
 * @param Text The new hour value entered by the user.
 */
void UCalendarUIBase::HandleOnHourChanged(const FText& Text)
{
    GetWorld()->GetTimerManager().ClearTimer(TickTimerHandle);
}
/**
 * @brief Handles the event when the minute is committed (e.g., user presses Enter).
 *
 * @param Text The new minute value entered by the user.
 * @param CommitMethod The method of text commit (e.g., OnEnter).
 */
void UCalendarUIBase::HandleOnMinuteCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
    if (CommitMethod == ETextCommit::OnEnter) {
        minute_now = Text.ToString();
        if (minute_now == "60") {
            FDateTime new_minute = FDateTime(FDateTime::Now().GetYear(), FDateTime::Now().GetMonth(), FDateTime::Now().GetDay(), 1, 0, 0, 0);
            minuteDifference = FDateTime::Now() - new_minute;
        }
        else if (minute_now.Len() <= 2) {
            FDateTime new_minute = FDateTime(FDateTime::Now().GetYear(), FDateTime::Now().GetMonth(), FDateTime::Now().GetDay(), 0, FCString::Atoi(*minute_now), 0, 0);
            minuteDifference = FDateTime::Now() - new_minute;
        }
        GetWorld()->GetTimerManager().SetTimer(TickTimerHandle, this, &UCalendarUIBase::InitializeMinute, DefaultMinuteTickInterval, true);
    }
}

/**
 * @brief Handles changes to the minute text box.
 *
 * @param Text The new minute value entered by the user.
 */
void UCalendarUIBase::HandleOnMinuteChanged(const FText& Text)
{
    GetWorld()->GetTimerManager().ClearTimer(TickTimerHandle);
}

/**
 * @brief Advances the calendar to the next month.
 */
void UCalendarUIBase::ShowNextMonth()
{
    FText m = month->GetText();
    int32 m2 = *MonthMap2.Find(m.ToString());
    if (m2 < 12) {
        m2 += 1;
    }
    else {
        m2 = 1;
    }
    InitializeMonth(m2);
    ListViewCalendar->ClearListItems();
    CreateCalendar();
}

/**
 * @brief Moves the calendar to the previous month.
 */
void UCalendarUIBase::ShowPrevMonth()
{
    FText m = month->GetText();
    int32 m2 = *MonthMap2.Find(m.ToString());
    if (m2 > 1) {
        m2 -= 1;
    }
    else {
        m2 = 12;
    }
    InitializeMonth(m2);
    ListViewCalendar->ClearListItems();
    CreateCalendar();
}
