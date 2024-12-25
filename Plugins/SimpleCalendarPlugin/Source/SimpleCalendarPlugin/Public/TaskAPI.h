// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WebBrowser.h"
#include "TaskAPI.generated.h"

/**
 * @class UTaskAPI
 * @brief A widget class that manages interactions with a web browser.
 *
 * This class provides functionality to update the URL of a web browser widget
 * embedded in the Unreal Engine User Interface.
 */
UCLASS()
class UTaskAPI : public UUserWidget
{
    GENERATED_BODY()

public:
    /**
     * @brief A pointer to the web browser widget used for rendering web content.
     *
     * The widget can be bound in the editor and configured to display web pages.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Calendar Properties")
    UWebBrowser* WebBrowserWidget;
};
