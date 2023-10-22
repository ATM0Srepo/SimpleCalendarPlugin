// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void HandleSundayClick();

    UFUNCTION()
    void HandleMondayClick();

    UFUNCTION()
    void HandleTuesdayClick();

    UFUNCTION()
    void HandleWednesdayClick();

    UFUNCTION()
    void HandleThursdayClick();

    UFUNCTION()
    void HandleFridayClick();

    UFUNCTION()
    void HandleSaturdayClick();

    UFUNCTION(BlueprintImplementableEvent, Category = "Events")
    void OnDaySelected();

    UPROPERTY(BlueprintReadOnly, Category = "Calendar Variables")
    FString DaySelected;

protected:
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Sunday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Monday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Tuesday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Wednesday;
	
    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Thursday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Friday;

    UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
    class UButton* Saturday;
};
