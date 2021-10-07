// Copyright 2020-2021 Rapyuta Robotics Co., Ltd.

#pragma once

#include <Msgs/ROS2OdometryMsg.h>
#include "CoreMinimal.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h"
#include "RobotVehicleMovementComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RCLUE_API URobotVehicleMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

private:

	UPROPERTY(Transient)
	FVector DesiredMovement;

	UPROPERTY(Transient)
	FQuat DesiredRotation;

public:
	URobotVehicleMovementComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Velocity)
	FVector AngularVelocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FROSOdometry OdomData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FrameId = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ChildFrameId = TEXT("");

	UPROPERTY(EditAnywhere)
	FTransform InitialTransform;

	UFUNCTION(BlueprintCallable)
	FTransform GetOdomTF();

	UFUNCTION(BlueprintCallable)
	virtual void InitMovementComponent();

protected:
	virtual void InitOdom();
	virtual void UpdateMovement(float DeltaTime);
	virtual void UpdateOdom(float DeltaTime);
	bool IsOdomInitialized = false;

	UPROPERTY(EditAnywhere)
	FTransform PreviousTransform;


	std::random_device Rng;
	std::mt19937 Gen;
	std::normal_distribution<> GaussianRNGPosition;
	std::normal_distribution<> GaussianRNGRotation;

    UPROPERTY(EditAnywhere, Category = "Noise")
    float NoiseMeanPos = 0.f;

    UPROPERTY(EditAnywhere, Category = "Noise")
    float NoiseVariancePos = 1.f;

    UPROPERTY(EditAnywhere, Category = "Noise")
    float NoiseMeanRot = 0.f;

    UPROPERTY(EditAnywhere, Category = "Noise")
    float NoiseVarianceRot = 5.f;

    UPROPERTY(EditAnywhere, Category = "Noise")
    bool WithNoise = true;
	
public:

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
};
