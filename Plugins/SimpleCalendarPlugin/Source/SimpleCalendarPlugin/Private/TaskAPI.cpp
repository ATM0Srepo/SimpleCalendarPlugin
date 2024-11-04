// Fill out your copyright notice in the Description page of Project Settings.


#include "TaskAPI.h"

void UTaskAPI::SetBrowserURL(const FString& Endpoint)
{
    if (WebBrowserWidget)
    {
        WebBrowserWidget->LoadURL(TEXT("http://127.0.0.1:5000/") + Endpoint);
    }
}