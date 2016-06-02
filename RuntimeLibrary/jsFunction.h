#pragma once
#include <iostream>
#include <codecvt>
#include "jsValue.h"
#include "jsReference.h"

using namespace std;

jsValue* ToPrimitive(jsValue* input) {
	//7.1.1 Table 9
	if (input->Type() == String || input->Type() == Number || input->Type() == Bool || input->Type()==Null || input->Type() == Undefined)
		return input;
	//TO DO
	/*
	else if (input->Type() == Object) {
		//1 Preferred type not passed set hint to "default"
		//2,3 Seperate function
		//4,5,6 is Ommitted
		//7 If hint is "default" let hint be "number" (from 1)
		string hint = "number";
		return OrdinaryToPrimitive(input, hint);
	}
	*/
	return NULL;
}

jsValue* Get(jsObject* obj, string key) {
	//1,2 ASSERT object and property exists
	//3 Return value
	return obj->get(key);
}

// 7.1.3 ToNumber()

jsNumber* ToNumber(jsValue* input) {
	if (input->Type() == Undefined) { return new jsNumber(NAN); }
	else if (input->Type() == Null) { return new jsNumber(+0); }
	else if (input->Type() == Bool) { if (input->ToBool()) { return new jsNumber(1); } else return new jsNumber(+0); }
	else if (input->Type() == String) {
		string s = ((jsString*)input)->value;
		try { double double_s = stof(s); return new jsNumber(double_s); }
		catch (exception e) { return new jsNumber(NAN); }
	}
	//Symbol and Object not included yet
}
// TO DO 
/*
jsValue* ToPrimitive(jsValue* input, string hint) {
	if (hint == "string")
	{
		return OrdinaryToPrimitive(input, hint);
	}
	else {return OrdinaryToPrimitive(input, "number");}
}

jsValue* OrdinaryToPrimitive(jsValue* input, string hint)
{
	//1,2 ASSERT CONDITIONS
	string methodNames[2] = { "toString","valueOf" };
	//3 If hint is "string" then methodNames is as is
	//4 If not, hint is "number" then
	if (hint != "string") { { methodNames[0] = "valueOf"; methodNames[1] = "toString"; }; }
	//5 For each method in methodNames do (in order):
	for (string name : methodNames) {
		jsValue* method = dynamic_cast<jsObject*>(input)->get(name);

	}
}
*/

jsValue* GetValue(jsValue* V)
{
	//1) ReturnIfAbrupt (NOT DONE)
	//2) If Type(V) is not Reference, return V.
	jsReference *ref = dynamic_cast<jsReference*>(V);
	if (ref == NULL)
		return V;
	//3) Let base be GetBase(V) (def)
	//4) IfIsUnresolvableReference 
	//5) Return base.[[Get]](GetReferencedName(V), GetThisValue(V)).
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
	return new jsNumber(lprim->ToNumber()->value- - rprim->ToNumber()->value);
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

						return new jsNumber(lprim->ToNumber()->value->value + rprim->ToNumber()->value->value);
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

//Strict Equality 7.2.13
jsBoolean* StrictEquality(jsValue* lprim, jsValue* rprim) {
	//1
	if (lprim->Type() != rprim->Type()) { return new jsBoolean(false); }
	else if (lprim->Type() == Undefined) { return new jsBoolean(true); }
	else if (lprim->Type() == Null) { return new jsBoolean(true); }
	else if (lprim->Type() == Number) {
		//a,b NaN omitted
		//c
	
		if (lprim->ToNumber()->value == rprim->ToNumber()->value) { return new jsBoolean(true); }
		else if ((lprim->ToNumber()->value == (+0)) && (rprim->ToNumber()->value == (-0))) { return new jsBoolean(true); }
		else if ((lprim->ToNumber()->value == (-0)) && (rprim->ToNumber()->value == (+0))) { return new jsBoolean(true); }
		else return new jsBoolean(false);
	}
	else if (lprim->Type() == String) { return new jsBoolean((lprim->ToString()->value == rprim->ToString()->value)); }
	else if (lprim->Type() == Bool) { return new jsBoolean(lprim->ToBool()->value == rprim->ToBool()->value); }
	//symbol not included
	else if (lprim->Type() == Object) {
		bool result = ((jsObject*)lprim)->property_table == ((jsObject*)rprim)->property_table;
		return new jsBoolean(result);
	}
	else return new jsBoolean(false);
}
//Abstract Equality 7.2.12
jsBoolean* AbstractEquality(jsValue* lprim, jsValue* rprim) {
	if (lprim->Type() == rprim->Type()) { return StrictEquality(lprim, rprim); }
	else if ((lprim->Type() == Null) && (rprim->Type() == Undefined)) { return new jsBoolean(true); }
	else if ((lprim->Type() == Undefined) && (rprim->Type() == Null)) { return new jsBoolean(true); }
	else if ((lprim->Type() == Number) && (rprim->Type() == String)) { return new jsBoolean(lprim->ToNumber()->value == ToNumber(rprim)->value); }
	else if ((lprim->Type() == String) && (rprim->Type() == Number)) { return new jsBoolean(ToNumber(lprim)->value == rprim->ToNumber()->value); }
	//Not exactly 8,9
	else if (lprim->Type() == Bool) { return new jsBoolean(ToNumber(lprim)->value == ToNumber(rprim)->value); }
	else if (rprim->Type() == Bool) { return new jsBoolean(ToNumber(lprim)->value == ToNumber(rprim)->value); }
	else if (lprim->Type() == String || lprim->Type() == Number) { return new jsBoolean(ToPrimitive(lprim) == ToPrimitive(rprim)); }
	else return new jsBoolean(false);
}

//Abstract Relational Comparison 7.2.11
jsBoolean* AbstractRelationalComparison(jsValue* lprim, jsValue* rprim, bool LeftFirst) {
	//3 without primative hint (call functions missing); wont work for objects
	jsValue* px;
	jsValue* py;
	if (LeftFirst) {
		 px = ToPrimitive(lprim);
		 py = ToPrimitive(rprim);
	}
	else {
		 py = ToPrimitive(rprim);
		 px = ToPrimitive(lprim);
	}
	if (px->Type() == String && py->Type() == String) {
		string spx = ((jsString*)px)->value;
		string spy = ((jsString*)py)->value;

		if (spx.size() > spy.size()) {
			bool result = spx.compare(0, spy.size(), spy);
			if (result) { return new jsBoolean(false); }
		}
		else if (spx.size() <= spy.size()) {
			bool result = spy.compare(0, spx.size(), spx);
			if (result) { return new jsBoolean(true); }
		}
		else {
			int diff_index = 0;
			bool finish = false;

			if (spx.size() >= spy.size()) {
				while (!finish) {
					if (spx.at(diff_index) != spy.at(diff_index)) { finish = true; }
					else { diff_index++; }
				}
			}
			else {
				while (!finish) {
					if (spy.at(diff_index) != spx.at(diff_index)) { finish = true; }
					else { diff_index++; }
				}
			}

			if (spx.at(diff_index) < spy.at(diff_index)) { return new jsBoolean(true); }
			else { return new jsBoolean(false); }
		}
	}
	else {
		jsNumber* nx = ToNumber(px);
		jsNumber* ny = ToNumber(py);
		if (nx->value == ny->value) { return new jsBoolean(false); }
		else if (nx->value == +0 && ny->value == -0) { return new jsBoolean(false); }
		else if (nx->value == -0 && ny->value == +0) { return new jsBoolean(false); }
		else if (nx->value == numeric_limits<double>::infinity()) { return new jsBoolean(false); }
		else if (ny->value == numeric_limits<double>::infinity()) { return new jsBoolean(true); }
		else if (ny->value == -1*numeric_limits<double>::infinity()) { return new jsBoolean(false); }
		else if (nx->value == -1*numeric_limits<double>::infinity()) { return new jsBoolean(true); }
		else if (nx->value<ny->value){ return new jsBoolean(true); }
		else { return new jsBoolean(false); }
	}
}





void consolelog(jsValue* x) {
	cout << x->ToString()->value << endl;
}