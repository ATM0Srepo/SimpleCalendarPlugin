#include "MyCalendarUIBase.h"
#include "Misc/DateTime.h"
#include "Components/TextBlock.h"

void UMyCalendarUIBase::NativeConstruct()
{
    Super::NativeConstruct();

    FDateTime CurrentDateTime = FDateTime::Now();

    FString hour_now = FString::FormatAsNumber(CurrentDateTime.GetHour());
    FString minute_now = FString::FormatAsNumber(CurrentDateTime.GetMinute());

    if (hour_now.Len() < 2) {
        hour_now = "0" + hour_now;
    }
    if (minute_now.Len() < 2) {
        minute_now = "0" + minute_now;
    }
    else {
        minute_now = minute_now.Replace(TEXT(","), TEXT(""));
    }

    hour->SetText(FText::FromString(hour_now));
    minute->SetText(FText::FromString(minute_now));
}
