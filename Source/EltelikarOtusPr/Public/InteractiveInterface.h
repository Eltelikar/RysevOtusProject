// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractiveInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractiveInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ELTELIKAROTUSPR_API IInteractiveInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
		void OnInteract(AActor* Caller);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
		void StartFocus();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
		void EndFocus();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact|ToInteract")
		void InteractRequest(AActor* OtherActor);
};
