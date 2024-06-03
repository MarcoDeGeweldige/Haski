#pragma once
#include <HaskiValueMembers.h>
enum HData { Integer, Float, Double, Char };
//these  are container and can be integers floats etc
class HaskiDataType
{
	HData haskiDataType = HData::Integer;

	HaskiValueMembers c_Val;


public:

	HaskiDataType(const HData& haskiDataType);
	

};


