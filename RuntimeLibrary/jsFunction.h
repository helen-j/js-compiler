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
/*
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
*/

	jsValue* lval = GetValue(lref);
	jsValue* rval = GetValue(rref);
	jsValue* lprim = ToPrimitive(lval);
	jsValue* rprim = ToPrimitive(rval);

		
	if (lprim->Type() == String || rprim->Type() == String) {
		jsValue* lprimValue = new jsBoolean(lprim->ToNumber()->value);
		jsValue* rprimValue = new jsBoolean(rprim->ToNumber()->value);

		if (lprimValue == NULL) {
			throw new std::exception("Reference error");
		}
		else if (rprimValue == NULL) {
			throw new std::exception("Reference error");
		}
		 else 
			return new jsNumber(lprim->ToNumber()->value * rprim->ToNumber()->value);

	}

	else if (lprim->Type() == Number || rprim->Type() == String) {
		jsValue* rprimValue = new jsBoolean(rprim->ToNumber()->value);
			if  (rprimValue == NULL) {
				throw new std::exception("Reference error");
		}
		else 
			return new jsNumber(lprim->ToNumber()->value * rprim->ToNumber()->value);
		
	}

	
	else if (lprim->Type() == String || rprim->Type() == Number) {
		jsValue* lprimValue = new jsBoolean(lprim->ToNumber()->value);
			if  (lprimValue == NULL) {
				throw new std::exception("Reference error");
			}
			else 
				return new jsNumber(lprim->ToNumber()->value * rprim->ToNumber()->value);
		
	}
	else if (lprim->Type() == Number || rprim->Type() == Number) {
		return new jsNumber(lprim->ToNumber()->value * rprim->ToNumber()->value);
	}

}

jsValue* Division(jsValue* lref, jsValue* rref) {
	/*Let left be the result of evaluating MultiplicativeExpression.
	Let leftValue be GetValue(left).
	ReturnIfAbrupt(leftValue).
	Let right be the result of evaluating UnaryExpression.
	Let rightValue be GetValue(right).
	Let lnum be ToNumber(leftValue).
	ReturnIfAbrupt(lnum).
	Let rnum be ToNumber(rightValue).
	ReturnIfAbrupt(rnum).
	Return the result of applying the MultiplicativeOperator(*, / , or %) to lnum and rnum as specified in 12.6.3.1, 12.6.3.2, or 12.6.3.3.*/
	
	jsValue* lval = GetValue(lref);
	jsValue* rval = GetValue(rref);
	jsValue* lprim = ToPrimitive(lval);
	jsValue* rprim = ToPrimitive(rval);
	jsValue* returnValue;
	
	if (lprim->Type() == String || rprim->Type() == String) {
		jsValue* lprimValue = new jsBoolean(lprim->ToNumber()->value);
		jsValue* rprimValue = new jsBoolean(rprim->ToNumber()->value);
		lprimValue == NULL || rprimValue == NULL ? throw new std::exception("Reference error") : returnValue = new jsNumber(lprim->ToNumber()->value / rprim->ToNumber()->value);
	}
	else if (lprim->Type() == Number && rprim->Type() == Number) {
		returnValue = new jsNumber(lprim->ToNumber()->value / rprim->ToNumber()->value);
	}
	return returnValue;
}

jsValue* Modulus(jsValue* lref, jsValue* rref) {
	/*Let left be the result of evaluating MultiplicativeExpression.
	Let leftValue be GetValue(left).
	ReturnIfAbrupt(leftValue).
	Let right be the result of evaluating UnaryExpression.
	Let rightValue be GetValue(right).
	Let lnum be ToNumber(leftValue).
	ReturnIfAbrupt(lnum).
	Let rnum be ToNumber(rightValue).
	ReturnIfAbrupt(rnum).
	Return the result of applying the MultiplicativeOperator(*, / , or %) to lnum and rnum as specified in 12.6.3.1, 12.6.3.2, or 12.6.3.3.*/

	jsValue* lval = GetValue(lref);
	jsValue* rval = GetValue(rref);
	jsValue* lprim = ToPrimitive(lval);
	jsValue* rprim = ToPrimitive(rval);
	jsValue* returnValue;

	if (lprim->Type() == String || rprim->Type() == String) {
		jsValue* lprimValue = new jsBoolean(lprim->ToNumber()->value);
		jsValue* rprimValue = new jsBoolean(rprim->ToNumber()->value);
		lprimValue == NULL || rprimValue == NULL ? throw new std::exception("Reference error") : returnValue = new jsNumber(lprim->ToNumber()->value / rprim->ToNumber()->value);
	}
	else if (lprim->Type() == Number && rprim->Type() == Number) {
		returnValue = new jsNumber(fmod(lprim->ToNumber()->value, rprim->ToNumber()->value));
		/*In C and C++, the remainder operator accepts only integral operands; in ECMAScript, it also accepts floating - point operands.
		The result of a floating - point remainder operation as computed by the % operator is not the same as the “remainder” operation defined by IEEE 754 - 2008. 
		The IEEE 754 - 2008 “remainder” operation computes the remainder from a rounding division, not a truncating division, and so its behaviour is not analogous to that of the usual integer remainder operator. 
		Instead the ECMAScript language defines % on floating - point operations to behave in a manner analogous to that of the Java integer remainder operator; 
		this may be compared with the C library function fmod.*/
	}
	return returnValue;
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
	jsValue* rprim = ToPrimitive(rval);

	if (lprim->Type() == String || rprim->Type() == String)
	{   //5. if both px and py are strings,then
		return new jsBoolean(lprim->ToString()->value < rprim->ToString()->value);
	}
	else
		return new jsBoolean(lprim->ToNumber()->value < rprim->ToNumber()->value);

}
jsValue* Greaterthan(jsValue* lref, jsValue* rref)
{
	

	//1.Let lref be the result of evaluating RelationalExpression.
        //2.Let lval be GetValue(lref).
        //3.ReturnIfAbrupt(lval).
        // 4.Let rref be the result of evaluating ShiftExpression.
        //5.Let rval be GetValue(rref).
        //6.Let r be the result of performing Abstract Relational Comparison rval < lval with LeftFirst              equal to false.
        //7.ReturnIfAbrupt(r).
        //8.If r is undefined, return false. Otherwise, return r
	jsValue* lval = GetValue(lref);
	jsValue* rval = GetValue(rref);
	jsValue* lprim = ToPrimitive(lval);
	jsValue* rprim = ToPrimitive(rval);

	if (lprim->Type() == String || rprim->Type() == String)
	{   //5. if both px and py are strings,then
		return new jsBoolean(lprim->ToString()->value > rprim->ToString()->value);
	}
	else
		return new jsBoolean(lprim->ToNumber()->value > rprim->ToNumber()->value);
	
}

jsValue* GreaterEQ(jsValue* lprim, jsValue* rprim)
{
	if (lprim->Type() == String || rprim->Type() == String)
	{   //5. if both px and py are strings,then
		return new jsBoolean(lprim->ToString()->value >= rprim->ToString()->value);
	}
	else
		return new jsBoolean(lprim->ToNumber()->value >= rprim->ToNumber()->value);
}

jsValue* LessEQ(jsValue* lprim, jsValue* rprim)
{
	if (lprim->Type() == String || rprim->Type() == String)
	{   //5. if both px and py are strings,then
		return new jsBoolean(lprim->ToString()->value <= rprim->ToString()->value);
	}
	else
		return new jsBoolean(lprim->ToNumber()->value <= rprim->ToNumber()->value);
}





jsValue* And(jsBoolean* lref, jsBoolean* rref)
{
	//1.Let lref be the result of evaluating LogicalANDExpression.
	//2.Let lval be GetValue(lref).
	jsValue* lval = GetValue(lref);
	//3.If ToBoolean(lval) is false, return lval.
	if (!lval->ToBool()->value) return lval;
	//4.Let rref be the result of evaluating BitwiseORExpression.
	//5.Return GetValue(rref).
	jsValue* rval = GetValue(rref);
	return rval;
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
//Let expr be the result of evaluating UnaryExpression.
//Let oldValue be ToNumber(GetValue(expr)).
	jsValue* oldValue = GetValue(expr)->ToNumber();
//ReturnIfAbrupt(oldValue).
//Let newValue be the result of adding the value 1 to oldValue, using the same rules as for the + operator (see 12.7.5).
	jsValue* newValue = Plus(oldValue, new jsNumber(1));
//Let status be PutValue(expr, newValue).
	bool status = PutValue(expr, newValue);
//ReturnIfAbrupt(status).
//Return newValue.
	return newValue;
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
	/*if (expr->Type() == String) {
		return new jsString("please use integer value instead of a string or an integer string");
	}
	else if (expr->Type() == Bool) {
		return new jsString("A boolean type is not supported");
	}
	else {*/
		//2.Return ToNumber(GetValue(expr)).
		return GetValue(expr);
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

jsBoolean* Equals(jsValue* lprim, jsValue* rprim) {
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

//unary - operator
jsValue* unaryMinus(jsValue* expr) {

/*	if (expr->Type() == String) {
		return new jsString("please use integer value instead of a string or an integer string");
	}
	else if (expr->Type() == Bool) {
		return new jsString("A boolean type is not supported");
	}
	else {
	*/
		return new jsNumber(GetValue(expr)->ToNumber()->value);
}

void consolelog(jsValue* x) {
	cout << x->ToString()->value << endl;
}