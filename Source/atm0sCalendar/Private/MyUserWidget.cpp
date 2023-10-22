// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Components/Button.h"


void UMyUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

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

