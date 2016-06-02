#pragma once

#include <iostream>
#include "jsValue.h"
#include "jsReference.h"

using namespace std;

jsValue* ToPrimitive(jsValue* input) {
	if (input->Type() == String || input->Type() == Number || input->Type() == Bool)
		return input;
	return NULL;
}

jsValue* GetValue(jsValue* V)
{
	//If Type(V) is not Reference, return V.
	jsReference *ref = dynamic_cast<jsReference*>(V);
	if (ref == NULL)
		return V;
	//Return base.[[Get]](GetReferencedName(V), GetThisValue(V)).
	return	ref->base->get(ref->name);
}

bool PutValue(jsValue* V, jsValue* W)
{
	//if Type(V) is not Reference, throw a ReferenceError exception.
	jsReference *ref = dynamic_cast<jsReference*>(V);
	if (ref == NULL)
		throw new std::exception("Reference error");
	//let succeeded be base.[[Set]](GetReferencedName(V), W, GetThisValue(V)).
	ref->base->set(ref->name, W);
	return true;
}

jsValue* Plus(jsValue* lref, jsValue* rref) {
	//Let lref be the result of evaluating AdditiveExpression.
	//Let lval be GetValue(lref).
	jsValue* lval = GetValue(lref);
	//ReturnIfAbrupt(lval).
	//Let rref be the result of evaluating MultiplicativeExpression.
	//Let rval be GetValue(rref).
	jsValue* rval = GetValue(rref);
	//ReturnIfAbrupt(rval).
	//Let lprim be ToPrimitive(lval).
	jsValue* lprim = ToPrimitive(lval);
	//ReturnIfAbrupt(lprim).
	//Let rprim be ToPrimitive(rval).
	jsValue* rprim = ToPrimitive(rval);
	//ReturnIfAbrupt(rprim).
	if (lprim->Type() == String || rprim->Type() == String) {
		/*If Type(lprim) is String or Type(rprim) is String, then
		Let lstr be ToString(lprim).
		ReturnIfAbrupt(lstr).
		Let rstr be ToString(rprim).
		ReturnIfAbrupt(rstr).
		Return the String that is the result of concatenating lstr and rstr.
		*/
		return new jsString(lprim->ToString()->value + rprim->ToString()->value);
	}
	else
		/*Let lnum be ToNumber(lprim).
		ReturnIfAbrupt(lnum).
		Let rnum be ToNumber(rprim).
		ReturnIfAbrupt(rnum).
		Return the result of applying the addition operation to lnum and rnum.See the Note below 12.7.5.
		*/
		return new jsNumber(lprim->ToNumber()->value + rprim->ToNumber()->value);
}

jsValue* Multiplication(jsValue* lref, jsValue* rref) {
//Let left be the result of evaluating MultiplicativeExpression.
//Let leftValue be GetValue(left).
jsValue* lval = GetValue(lref);
//ReturnIfAbrupt(leftValue).
//Let right be the result of evaluating UnaryExpression.
//Let rightValue be GetValue(right).
jsValue* rval = GetValue(rref);
//Let lnum be ToNumber(leftValue).

//ReturnIfAbrupt(lnum).
//Let rnum be ToNumber(rightValue).
//ReturnIfAbrupt(rnum).
//Return the result of applying the MultiplicativeOperator(*, / , or %) to lnum and rnum
return new jsNumber(lval->ToNumber()->value * rval->ToNumber()->value);
}

jsValue* Lessthan(jsValue* lref, jsValue* rref)
{
	//1.ReturnIfAbrupt(x).
	//2.ReturnIfAbrupt(y).
	//3.If the LeftFirst flag is true, then a.Let px be ToPrimitive(x, hint Number).
	//b.ReturnIfAbrupt(px).
	//c.Let py be ToPrimitive(y, hint Number).
	//d.ReturnIfAbrupt(py).

	//4.Else the order of evaluation needs to be reversed to preserve left to right evaluation a.Let py be ToPrimitive(y, hint Number).
	//b.ReturnIfAbrupt(py).
	//c.Let px be ToPrimitive(x, hint Number).
	//d.ReturnIfAbrupt(px).
	jsValue* lval = GetValue(lref);
	jsValue* rval = GetValue(rref);
	jsValue* lprim = ToPrimitive(lval);
	//ReturnIfAbrupt(lprim).
	//Let rprim be ToPrimitive(rval).
	jsValue* rprim = ToPrimitive(rval);

	if (lprim->Type() == String || rprim->Type() == String)
	{   //5. if both px and py are strings,then
		return new jsBoolean(lprim->ToString()->value < rprim->ToString()->value);
	}
	else
		return new jsBoolean(lprim->ToNumber()->value < rprim->ToNumber()->value);

}

jsValue* Greaterthan(jsValue* lref, jsValue* rref) {
	return Lessthan(rref, lref);
}

jsBoolean* And(jsBoolean* lprim, jsBoolean* rprim)
{
	if (lprim->ToBool() && rprim->ToBool())

	{
		if (lprim->ToBool() == false)
			return new jsBoolean(lprim->ToBool()->value);
		else
		{


			if (rprim->ToBool() == false)
				return new jsBoolean(rprim->ToBool()->value);
			else
			{
				return new jsBoolean(rprim->ToBool()->value);
			}
		}

	}
}


//Subtraction operator 
jsValue* Minus(jsValue* lref, jsValue* rref) {
	jsValue* lval = GetValue(lref);
	jsValue* rval = GetValue(rref);
	jsValue* lprim = ToPrimitive(lval);
	jsValue* rprim = ToPrimitive(rval);
	return new jsNumber(lprim->ToNumber()->value - rprim->ToNumber()->value);
}

//Increment operator
jsValue* Increment(jsValue* expr) {
	expr = expr->ToNumber();
	//TODO ReturnIfAbrupt(oldValue).
	expr = Plus(expr, new jsNumber(1));
	//TODO Let status be PutValue(expr, newValue).
	//TODO ReturnIfAbrupt(status).
	return expr;
}

//Decrement Operator
jsValue* Decrement(jsValue* expr) {
	expr = expr->ToNumber();
	expr = Minus(expr, new jsNumber(1));
	return expr;
}

//The unary + operator converts its operand to Number type.
jsValue* unaryPlus(jsValue* expr) {
	//The production UnaryExpression : +UnaryExpression is evaluated as follows :
	//1.Let expr be the result of evaluating UnaryExpression.
	if (expr->Type() == String) {
		return new jsString("please use integer value instead of a string or an integer string");
	}
	else if (expr->Type() == Bool) {
		return new jsString("A boolean type is not supported");
	}
	else {
		//2.Return ToNumber(GetValue(expr)).
		return new jsNumber(expr->ToNumber()->value);
	}
}


jsValue* Assign(jsValue* lref, jsValue* rref)
{
	//1.D Let rval be GetValue(rref)
	jsValue* rval = GetValue(rref);
	//1.F Let status be PutValue(lref, rval)
	bool status = PutValue(lref, rval);
	//1.G return rval
	return rval;
}

jsBoolean* Equals(jsValue* lref, jsValue* rref) {
	//Let lref be the result of evaluating EqualityExpression.
	//Let lval be GetValue(lref). -- Use lprim instead to work with the previously written codes.
	jsValue* lprim = GetValue(lref);
	//ReturnIfAbrupt(lval).
	//Let rref be the result of evaluating RelationalExpression.
	//Let rval be GetValue(rref). -- Use rprim instead to work with the previously written codes.
	jsValue* rprim = GetValue(rref);
	//ReturnIfAbrupt(rval).
	//Return the result of performing Abstract Equality Comparison rval == lval.
	//	1.	ReturnIfAbrupt(x).
	//		2.	ReturnIfAbrupt(y).
	//		3.	If Type(x) is the same as Type(y), then
	//		a.Return the result of performing Strict Equality Comparison    x == = y.

		if (lprim->Type() == rprim->Type()) {
			if (lprim->Type()==String )
				return new jsBoolean(lprim->ToString()->value == rprim->ToString()->value);
			else if (lprim->Type() == Number)
				return new jsBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value);
			else if (lprim->Type() == Bool)
				return new jsBoolean(lprim->ToBool()->value == rprim->ToBool()->value);
		}
		else {
			//		4.	If x is null and y is undefined, return   true.
			//		5.	If x is undefined and y is null, return    true.
			/*			if (lprim == NULL)

						return new jsNumber(lprim->ToNumber()->value + rprim->ToNumber()->value);
					//*/

					//		6.	If Type(x) is Number and Type(y) is   String,
					//		return the result of the comparison  x == ToNumber(y).
			if ((lprim->Type() == Number) && (rprim->Type() == String))
				return new jsBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value);

			//		7.	If Type(x) is String and Type(y) is   Number,
			//		return the result of the comparison ToNumber(x) == y.
			if ((lprim->Type() == String) && (rprim->Type() == Number))
				return new jsBoolean(lprim->ToNumber()->value == rprim->ToNumber()->value);

			//		8.	If Type(x) is Boolean, return the result of the comparison ToNumber(x) == y.
			//		9.	If Type(y) is Boolean, return the result of the comparison  x == ToNumber(y).
			//		10.	If Type(x) is either String, Number, or Symbol and Type(y) is Object, then return the result of the comparison  x == ToPrimitive(y).
			//		11.	If Type(x) is Object and Type(y) is either String, Number, or Symbol, then return the result of the comparison ToPrimitive(x) == y.
			//		12.	Return false.

		}

}


void consolelog(jsValue* x) {
	cout << x->ToString()->value << endl;
}