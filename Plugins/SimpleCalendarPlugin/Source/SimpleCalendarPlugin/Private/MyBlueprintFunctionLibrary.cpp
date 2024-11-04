// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Misc/FileHelper.h"

bool UMyBlueprintFunctionLibrary::ReadJsonFromFile(const FString& FilePath, FString& OutJson)
{
    return FFileHelper::LoadFileToString(OutJson, *FilePath);
}
