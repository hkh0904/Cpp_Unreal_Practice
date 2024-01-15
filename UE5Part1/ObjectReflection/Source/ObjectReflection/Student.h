// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
// 언리얼에서 include시 generated.h이 가장 밑에 include되어야함
#include "Person.h"
#include "Student.generated.h"

/**
 * 
 */
UCLASS()
class OBJECTREFLECTION_API UStudent : public UPerson
{
	GENERATED_BODY()
	
public:
	UStudent();

	virtual void DoLesson() override;

private:
	UPROPERTY()
	int32 Id;

};
