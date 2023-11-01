// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	DisplayText->SetText(FText::FromString(TextToDisplay));
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;

	switch (LocalRole)
	{
	case ROLE_None:
		Role = FString("None");
		break;
	case ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;
	case ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;
	case ROLE_Authority:
		Role = FString("Authority");
		break;
	case ROLE_MAX:
		break;
	default:
		break;
	}

	FString LocalRoleString = FString::Printf(TEXT("LocalRole: %s"), *Role);
	SetDisplayText(LocalRoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
