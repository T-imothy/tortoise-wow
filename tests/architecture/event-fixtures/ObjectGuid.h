#pragma once
struct ObjectGuid {unsigned value=0;ObjectGuid()=default;ObjectGuid(unsigned v):value(v){}bool operator<(ObjectGuid const&b)const{return value<b.value;}};
