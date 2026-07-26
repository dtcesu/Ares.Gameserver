#include <pch.h>
#include <Headers/Modules/ShooterGame/Components/MapPingComponent.h>
INIT_MODULE(MapPingComponent);

void MapPingComponent::Init()
{
    Hooking::ExecHook(UMapPingComponent::StaticClass()->FindFunction("CreateMapPing"), CreateMapPing);
}

void MapPingComponent::CreateMapPing(UMapPingComponent* _this, FFrame& Stack)
{
    // const struct FVector& Location, EMapPingType PingType, int32 PingIndex

    FVector Location;
    EMapPingType PingType;
    int32 PingIndex;

    Stack.StepCompiledIn(&Location);
    Stack.StepCompiledIn(&PingType);
    Stack.StepCompiledIn(&PingIndex);
    Stack.IncrementCode();

    printf("marker x: %f\n", Location.X);
    printf("marker y: %f\n", Location.Y);
    printf("marker z: %f\n", Location.Z);

    printf("enum: %d\n", (int)PingType);

    FActivePingData Something;
    Something.PingLocation = Location;
    Something.PingEndTimestamp = 999999.f;
    // Something.PingData.

    _this->ActivePingData.Add(Something);
}