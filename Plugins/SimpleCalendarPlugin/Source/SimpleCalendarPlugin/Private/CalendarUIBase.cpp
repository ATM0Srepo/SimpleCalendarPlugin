#include "CalendarUIBase.h"
#include "Misc/DateTime.h"
#include "Components/TextBlock.h"
#include "Containers/Map.h"
#include "CalendarRow.h"
#include "Components/ListView.h"


void UCalendarUIBase::NativeConstruct()
{
    Super::NativeConstruct();
    CurrentDateTime = FDateTime::Now();

    // year
    InitializeYear(CurrentDateTime.GetYear());
    year->OnTextCommitted.AddDynamic(this, &UCalendarUIBase::HandleOnTextCommitted);

    GetWorld()->GetTimerManager().SetTimer(TickTimerHandle, this, &UCalendarUIBase::SetTime, TickInterval, true); 
}

void UCalendarUIBase::SetTime()
{
    int32 month_now = CurrentDateTime.GetMonth();
    FString hour_now = FString::FormatAsNumber(CurrentDateTime.GetHour());
    FString minute_now = FString::FormatAsNumber(CurrentDateTime.GetMinute());

    if (hour_now.Len() < 2) {
        hour_now = "0" + hour_now;
    }
    if (minute_now.Len() < 2) {
        minute_now = "0" + minute_now;
    }
    
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

    month->SetText(FText::FromString(*MonthMap.Find(month_now)));
    hour->SetText(FText::FromString(hour_now));
    minute->SetText(FText::FromString(minute_now));
}

void UCalendarUIBase::InitializeYear(int y)
{
    year_now = FString::FormatAsNumber(y);
    year_now = year_now.Replace(TEXT(","), TEXT(""));
    year->SetText(FText::FromString(year_now));
}

void UCalendarUIBase::HandleOnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{
    if (CommitMethod == ETextCommit::OnEnter) {
        year_now = Text.ToString();
        ListViewCalendar->ClearListItems();
    }
}

void UCalendarUIBase::SetYear(int y)
{
    InitializeYear(y);
    ListViewCalendar->ClearListItems();
}

void UCalendarUIBase::CreateCalendar(FLinearColor SelectedGridColor)
{
    for (int32 i = 0; i <= 5; ++i)
    {
        UCalendarRow* CalendarRowInstance = NewObject<UCalendarRow>(this, UCalendarRow::StaticClass());
        if (CalendarRowInstance != nullptr)
        {
            CalendarRowInstance->Init(i, SelectedGridColor);
            ListViewCalendar->AddItem(CalendarRowInstance);
        }
    }
}



