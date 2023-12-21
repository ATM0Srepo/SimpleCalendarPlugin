#include "CalendarUIBase.h"
#include "Misc/DateTime.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Containers/Map.h"
#include "CalendarRow.h"
#include "Components/ListView.h"


void UCalendarUIBase::NativeConstruct()
{
    Super::NativeConstruct();
    MonthMap2 = {
    {TEXT("Jan"), 1},
    {TEXT("Feb"), 2},
    {TEXT("Mar"), 3},
    {TEXT("Apr"), 4},
    {TEXT("May"), 5},
    {TEXT("Jun"), 6},
    {TEXT("Jul"), 7},
    {TEXT("Aug"), 8},
    {TEXT("Sep"), 9},
    {TEXT("Oct"), 10},
    {TEXT("Nov"), 11},
    {TEXT("Dec"), 12}
    };

    // style
    PreCalendarConfig(
        FLinearColor(1.0f, 1.0f, 1.0f, 0.8f),
        FLinearColor(0.0f, 0.0f, 0.0f, 1.0f),
        FLinearColor(0.45f, 0.2f, 0.1f, 0.7f)
    );

    toggle_prev_month->SetVisibility(ESlateVisibility::Collapsed);
    toggle_prev_month->OnClicked.AddDynamic(this, &UCalendarUIBase::ShowPrevMonth);
    toggle_next_month->SetVisibility(ESlateVisibility::Collapsed);
    toggle_next_month->OnClicked.AddDynamic(this, &UCalendarUIBase::ShowNextMonth);

    // year
    InitializeYear(FDateTime::Now().GetYear());
    year->OnTextCommitted.AddDynamic(this, &UCalendarUIBase::HandleOnYearChanged);

    // month
    InitializeMonth(FDateTime::Now().GetMonth());
    MonthButton->OnClicked.AddDynamic(this, &UCalendarUIBase::HandleMonthToggleButtonClick);

    // hour and minute
    hourDifference = FDateTime::Now() - FDateTime::Now();
    minuteDifference = FDateTime::Now() - FDateTime::Now();
    InitializeHour();
    GetWorld()->GetTimerManager().SetTimer(TickTimerHandle, this, &UCalendarUIBase::InitializeMinute, DefaultMinuteTickInterval, true);
    hour->OnTextCommitted.AddDynamic(this, &UCalendarUIBase::HandleOnHourCommitted);
    hour->OnTextChanged.AddDynamic(this, &UCalendarUIBase::HandleOnHourChanged);
    minute->OnTextCommitted.AddDynamic(this, &UCalendarUIBase::HandleOnMinuteCommitted);
    minute->OnTextChanged.AddDynamic(this, &UCalendarUIBase::HandleOnMinuteChanged);
}

void UCalendarUIBase::InitializeHour()
{
    hour_now = FString::FormatAsNumber((FDateTime::Now() - hourDifference).GetHour());

    if (hour_now.Len() < 2) {
        hour_now = "0" + hour_now;
    }

    hour->SetText(FText::FromString(hour_now));
}

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

void UCalendarUIBase::InitializeYear(int y)
{
    year_now = y;
    year->SetText(FText::FromString(FString::FormatAsNumber(y).Replace(TEXT(","), TEXT(""))));
}

void UCalendarUIBase::InitializeMonth(int m)
{
    TMap<int32, FString> MonthMap = {
    {1, TEXT("Jan")},
    {2, TEXT("Feb")},
    {3, TEXT("Mar")},
    {4, TEXT("Apr")},
    {5, TEXT("May")},
    {6, TEXT("Jun")},
    {7, TEXT("Jul")},
    {8, TEXT("Aug")},
    {9, TEXT("Sep")},
    {10, TEXT("Oct")},
    {11, TEXT("Nov")},
    {12, TEXT("Dec")}
    };
    month_now = m;
    month->SetText(FText::FromString(*MonthMap.Find(m)));
}

void UCalendarUIBase::SetCornerRadii(const FVector4& CalendarBorder, const FVector4& WeekdayHeaderRadii)
{
    calendar_background->WidgetStyle.Normal.OutlineSettings.CornerRadii = CalendarBorder;
    weekdays_background->WidgetStyle.Normal.OutlineSettings.CornerRadii = WeekdayHeaderRadii;
}

FDateTime UCalendarUIBase::GetTime()
{
    return FDateTime(year_now, month_now, FDateTime::Now().GetDay(), FCString::Atoi(*hour_now), FCString::Atoi(*minute_now), 0, 0);
}

void UCalendarUIBase::HandleOnYearChanged(const FText& Text, ETextCommit::Type CommitMethod)
{
    if (CommitMethod == ETextCommit::OnEnter) {
        
        year_now = FCString::Atoi(*Text.ToString());
        ListViewCalendar->ClearListItems();
        CreateCalendar();
    }
}

void UCalendarUIBase::HandleMonthToggleButtonClick()
{
    if (toggle_prev_month->IsVisible()) {
        toggle_prev_month->SetVisibility(ESlateVisibility::Collapsed);
        toggle_next_month->SetVisibility(ESlateVisibility::Collapsed
);
    }
    else {
        toggle_prev_month->SetVisibility(ESlateVisibility::Visible);
        toggle_next_month->SetVisibility(ESlateVisibility::Visible);
    }

}

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

void UCalendarUIBase::HandleOnHourChanged(const FText& Text)
{
    GetWorld()->GetTimerManager().ClearTimer(TickTimerHandle);
}

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

void UCalendarUIBase::HandleOnMinuteChanged(const FText& Text)
{
    GetWorld()->GetTimerManager().ClearTimer(TickTimerHandle);
}

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

void UCalendarUIBase::PreCalendarConfig(FLinearColor SelectedGridColor , FLinearColor EmptyGridColor, FLinearColor GridColor, FLinearColor CalendarBackgroundColor, FLinearColor CalendarBackgroundBorderColor, FLinearColor WeekdayHeadingColor)
{
    color1 = SelectedGridColor;
    color2 = EmptyGridColor;
    color3 = GridColor;
    calendar_background->WidgetStyle.Normal.TintColor = FSlateColor(CalendarBackgroundColor);
    calendar_background->WidgetStyle.Hovered.TintColor = FSlateColor(CalendarBackgroundColor);
    calendar_background->WidgetStyle.Pressed.TintColor = FSlateColor(CalendarBackgroundColor);
    calendar_background->WidgetStyle.Normal.OutlineSettings.Color = FSlateColor(CalendarBackgroundBorderColor);
    calendar_background->WidgetStyle.Hovered.OutlineSettings.Color = FSlateColor(CalendarBackgroundBorderColor);
    calendar_background->WidgetStyle.Pressed.OutlineSettings.Color = FSlateColor(CalendarBackgroundBorderColor);
    weekdays_background->WidgetStyle.Normal.TintColor = FSlateColor(WeekdayHeadingColor);
    weekdays_background->WidgetStyle.Hovered.TintColor = FSlateColor(WeekdayHeadingColor);
    weekdays_background->WidgetStyle.Pressed.TintColor = FSlateColor(WeekdayHeadingColor);
}



void UCalendarUIBase::CreateCalendar()
{
    for (int32 i = 0; i <= 5; ++i)
    {
        UCalendarRow* CalendarRowInstance = NewObject<UCalendarRow>(this, UCalendarRow::StaticClass());
        if (CalendarRowInstance != nullptr)
        {
            CalendarRowInstance->Init(
                i,
                year_now,
                month_now,
                color1,
                color2,
                color3
                );
            ListViewCalendar->AddItem(CalendarRowInstance);
        }
    }
}

void UCalendarUIBase::SetYear(int y)
{
    InitializeYear(y);
}

void UCalendarUIBase::SetMonth(int32 m)
{
    InitializeMonth(m);
    ListViewCalendar->ClearListItems();
    CreateCalendar();
}



