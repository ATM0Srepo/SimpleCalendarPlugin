#include "MyCalendarUIBase.h"
#include "Misc/DateTime.h"
#include "Components/TextBlock.h"
#include "Containers/Map.h"
#include "Components/ListView.h"

void UMyCalendarUIBase::NativeConstruct()
{
    Super::NativeConstruct();

    FDateTime CurrentDateTime = FDateTime::Now();

    FString year_now = FString::FormatAsNumber(CurrentDateTime.GetYear());
    int32 month_now = CurrentDateTime.GetMonth();
    FString hour_now = FString::FormatAsNumber(CurrentDateTime.GetHour());
    FString minute_now = FString::FormatAsNumber(CurrentDateTime.GetMinute());

    if (hour_now.Len() < 2) {
        hour_now = "0" + hour_now;
    }
    if (minute_now.Len() < 2) {
        minute_now = "0" + minute_now;
    }
   
    year_now = year_now.Replace(TEXT(","), TEXT(""));
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
    
    year->SetText(FText::FromString(year_now));
    month->SetText(FText::FromString(*MonthMap.Find(month_now)));
    hour->SetText(FText::FromString(hour_now));
    minute->SetText(FText::FromString(minute_now));
}

