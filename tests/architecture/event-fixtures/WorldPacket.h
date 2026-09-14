#pragma once
#include <string>
#include "ObjectGuid.h"
struct WorldPacket {unsigned payload=0;WorldPacket()=default;WorldPacket(WorldPacket const&)=default;WorldPacket(WorldPacket&&)=default;WorldPacket& operator=(WorldPacket const&)=delete;WorldPacket& operator=(WorldPacket&&)=default;WorldPacket& operator<<(ObjectGuid const& g){payload=g.value;return *this;}};
