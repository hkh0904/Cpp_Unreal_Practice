// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameInstance.h"
// 합계 구하는 라이브러리
#include "Algo/Accumulate.h"

FString MakeRandomName()
{
    TCHAR FirstChar[] = TEXT("김이박최");
    TCHAR MiddleChar[] = TEXT("상혜지성");
    TCHAR LastChar[] = TEXT("수은원연");

    TArray<TCHAR> RandArray;
    RandArray.SetNum(3);
    RandArray[0] = FirstChar[FMath::RandRange(0, 3)];
    RandArray[1] = MiddleChar[FMath::RandRange(0, 3)];
    RandArray[2] = LastChar[FMath::RandRange(0, 3)];

    return RandArray.GetData();
}

void UMyGameInstance::Init()
{
    Super::Init();  // 부모 클래스의 Init 함수를 호출합니다.

    const int32 ArrayNum = 10;  // 배열의 크기를 정의합니다.
    TArray<int32> Int32Array;  // int32 타입의 동적 배열을 선언합니다.

    // 1부터 10까지의 숫자를 배열에 추가합니다.
    for (int32 ix = 1; ix <= ArrayNum; ++ix)
    {
        Int32Array.Add(ix);
    }

    // 배열에서 짝수를 제거합니다.
    Int32Array.RemoveAll(
        [](int32 Val)
        {
            return Val % 2 == 0;
        }
    );

    // 배열에 추가적으로 짝수를 포함한 숫자를 추가합니다.
    Int32Array += {2, 4, 6, 8, 10};

    TArray<int32> Int32ArrayCompare;  // 비교할 배열을 선언합니다.
    int32 CArray[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };  // 비교할 정적 배열을 선언합니다.
    Int32ArrayCompare.AddUninitialized(ArrayNum);  // 비교할 배열의 크기를 설정합니다.
    FMemory::Memcpy(Int32ArrayCompare.GetData(), CArray, sizeof(int32) * ArrayNum);  // 배열을 메모리로 복사합니다.

    ensure(Int32Array == Int32ArrayCompare);  // 두 배열이 동일한지 확인합니다.

    int Sum = 0;
    for (const int32& Int32Elem : Int32Array)
    {
        Sum += Int32Elem;
    }

    ensure(Sum == 55);

    int32 SumByAlgo = Algo::Accumulate(Int32Array, 0);
    ensure(Sum == SumByAlgo);

    TSet<int32> Int32Set;
    for (int32 ix = 1; ix <= ArrayNum; ++ix)
    {
        Int32Set.Add(ix);
    }

    // Array와 달리 제거하면 메모리에 빈틈이 생김
    // 채워넣을땐 마지막에 빠진 메모리부터 채워넣음
    // 결과는 { 1, 10, 3, 8, 5, 6, 7, 4, 9, 2 }
    Int32Set.Remove(2);
    Int32Set.Remove(4);
    Int32Set.Remove(6);
    Int32Set.Remove(8);
    Int32Set.Remove(10);
    Int32Set.Add(2);
    Int32Set.Add(4);
    Int32Set.Add(6);
    Int32Set.Add(8);
    Int32Set.Add(10);

    
    const int32 StudentNum = 300;
    for (int32 ix = 1; ix <= StudentNum; ++ix)
    {
        StudentsData.Emplace(FStudentData(MakeRandomName(), ix));
    }

    TArray<FString> AllStudentsNames;
    Algo::Transform(StudentsData, AllStudentsNames,
        [](const FStudentData& Val)
        {
            return Val.Name;
        }
    );

    UE_LOG(LogTemp, Log, TEXT("모든 학생 이름의 수 : %d"), AllStudentsNames.Num());

    TSet<FString> AllUniqueNames;
    Algo::Transform(StudentsData, AllUniqueNames,
        [](const FStudentData& Val)
        {
            return Val.Name;
        }
    );

    UE_LOG(LogTemp, Log, TEXT("중복 없는 학생 이름의 수 : %d"), AllUniqueNames.Num());

    Algo::Transform(StudentsData, StudentsMap,
        [](const FStudentData& Val)
        {
            return TPair<int32, FString>(Val.Order, Val.Name);
        }
    );

    UE_LOG(LogTemp, Log, TEXT("순번에 따른 학생 맵의 레코드 수 : %d"), StudentsMap.Num());

    TMap<FString, int32> StudentsMapByUniqueName;

    Algo::Transform(StudentsData, StudentsMapByUniqueName,
        [](const FStudentData& Val)
        {
            return TPair<FString, int32>(Val.Name, Val.Order);
        }
    );

    UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 맵의 레코드 수 : %d"), StudentsMapByUniqueName.Num());

    // 중복허용하는 map
    TMultiMap<FString, int32> StudentsMapByName;
    Algo::Transform(StudentsData, StudentsMapByName,
        [](const FStudentData& Val)
        {
            return TPair<FString, int32>(Val.Name, Val.Order);
        }
    );

    UE_LOG(LogTemp, Log, TEXT("이름에 따른 학생 멀티맵의 레코드 수 : %d"), StudentsMapByName.Num());

    const FString TargetName(TEXT("이혜은"));
    TArray<int32> AllOrders;
    StudentsMapByName.MultiFind(TargetName, AllOrders);

    UE_LOG(LogTemp, Log, TEXT("이름이 %s인 학생 수 : %d"), *TargetName, AllOrders.Num());

    TSet<FStudentData> StudentsSet;
    for (int32 ix = 1; ix <= StudentNum; ++ix)
    {
        StudentsSet.Emplace(FStudentData(MakeRandomName(), ix));
    }

}
