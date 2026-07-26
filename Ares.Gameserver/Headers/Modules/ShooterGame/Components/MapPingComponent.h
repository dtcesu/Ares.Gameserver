#pragma once
#include "pch.h"

class MapPingComponent
{
public:
    static void Init();

private:
    static void CreateMapPing(UMapPingComponent* _this, FFrame& Stack);
};