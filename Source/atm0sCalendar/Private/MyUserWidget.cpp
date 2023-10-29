#include "MyUserWidget.h"
#include "Misc/DateTime.h"
#include "Containers/Map.h"
#include "Components/Button.h"


void UMyUserWidget::NativeConstruct()
{
    Super::NativeConstruct();


    FDateTime CurrentDateTime = FDateTime::Now();
    int32 Year = CurrentDateTime.GetYear() ;  // temp
    int32 Month = CurrentDateTime.GetMonth();   // temp
    int32 Day = CurrentDateTime.GetDay();
  

    FDateTime FirstDayOfMonth(Year, Month, 1);
    int32 DayOfWeek = static_cast<int32>(FirstDayOfMonth.GetDayOfWeek());
    int32 LastDayOfMonth = CurrentDateTime.DaysInMonth(Year, Month);

    // populate

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

void UMyUserWidget::OnListItemObjectSet(UObject* ListItemObject)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Your message here"));
    }

    //// 2. Cast the object to ACalendarRow.
    //ACalendarRow* CalendarRowObj = Cast<ACalendarRow>(ListItemObject);

    //// Check if the cast was successful.
    //if (CalendarRowObj)
    //{
    //    // 3. Break the struct and get the values.
    //    FBaseStructure BaseStruct = CalendarRowObj->YourStructMember; // Replace 'YourStructMember' with the actual member name in `ACalendarRow`.

    //    FString TextValue = BaseStruct.Text;  // Assuming Text is of type FString.
    //    int32 Num1Value = BaseStruct.Num1;    // Assuming Num1 is of type int32.

    //    // Do something with TextValue and Num1Value...
    //}
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

void UMyUserWidget::GetStartDayOfMonth(int32 Year, int32 Month)
{
    
}

