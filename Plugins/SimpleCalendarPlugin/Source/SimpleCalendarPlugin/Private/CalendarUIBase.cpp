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
        FLinearColor(1.0f, 1.0f, 1.0f, 0.8f)
    );

    toggle_prev_month->SetVisibility(ESlateVisibility::Collapsed);
    toggle_prev_month->OnClicked.AddDynamic(this, &UCalendarUIBase::ShowPrevMonth);
    toggle_next_month->SetVisibility(ESlateVisibility::Collapsed);
    toggle_next_month->OnClicked.AddDynamic(this, &UCalendarUIBase::ShowNextMonth);
    MonthButton->OnClicked.AddDynamic(this, &UCalendarUIBase::HandleMonthToggleButtonClick);

    // year
    InitializeYear(FDateTime::Now().GetYear());
    year->OnTextCommitted.AddDynamic(this, &UCalendarUIBase::HandleOnYearChanged);

    // month
    InitializeMonth(FDateTime::Now().GetMonth());

    GetWorld()->GetTimerManager().SetTimer(TickTimerHandle, this, &UCalendarUIBase::SetTime, TickInterval, true); 
}

void UCalendarUIBase::SetTime()
{
    FString hour_now = FString::FormatAsNumber(FDateTime::Now().GetHour());
    FString minute_now = FString::FormatAsNumber(FDateTime::Now().GetMinute());

    if (hour_now.Len() < 2) {
        hour_now = "0" + hour_now;
    }
    if (minute_now.Len() < 2) {
        minute_now = "0" + minute_now;
    }
   
    hour->SetText(FText::FromString(hour_now));
    minute->SetText(FText::FromString(minute_now));
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
}

void UCalendarUIBase::PreCalendarConfig(FLinearColor SelectedGridColor)
{
    color1 = SelectedGridColor;
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
                color1);
            ListViewCalendar->AddItem(CalendarRowInstance);
        }
    }
}

void UCalendarUIBase::SetYear(int y)
{
    InitializeYear(y);
    ListViewCalendar->ClearListItems();
    CreateCalendar();
}

void UCalendarUIBase::SetMonth(int m)
{
}



