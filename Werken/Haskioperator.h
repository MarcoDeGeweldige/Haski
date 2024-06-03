#pragma once
enum HOperation { Plus, Minus, Multiply, Devide };
//contains the functionality of an operator
class Haskioperator
{

	HOperation hoperator = HOperation::Plus;
public:

	Haskioperator(const HOperation& hoperator);

};


