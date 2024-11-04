// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WebBrowser.h"
#include "TaskAPI.generated.h"

/**
 * 
 */
UCLASS()
class UTaskAPI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "TaskAPI")
	void SetBrowserURL(const FString& Endpoint);

	// Pointer to the Web Browser widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UWebBrowser* WebBrowserWidget;
	
};
