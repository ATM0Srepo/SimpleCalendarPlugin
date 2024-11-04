// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLECALENDARPLUGIN_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	void WriteJsonFromFile(const FString& FilePath, FString& OutJson);
	UFUNCTION(BlueprintCallable, Category = "JSON")
	static bool ReadJsonFromFile(const FString& FilePath, FString& OutJson);
	
};