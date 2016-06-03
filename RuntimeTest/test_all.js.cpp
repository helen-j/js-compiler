#include "jsValue.h"
#include "jsObject.h"
#include "jsFunction.h"
#include "jsReference.h"
int main(int argc, char* argv[])
{
jsObject* global = new jsObject();
jsObject* env = global;
jsValue* r0 = new jsReference(env, "x");
jsValue* r1 = new jsNumber(42.000000);
jsValue* r2 = Assign(r0,r1);
jsValue* r3 = new jsReference(env, "x");
jsValue* r4 = new jsReference(env, "x");
jsValue* r5 = new jsNumber(4.000000);
jsValue* r6 = Plus(r4,r5);
jsValue* r7 = Assign(r3,r6);
WhileLabel1:
jsValue* r8 = new jsReference(env, "x");
jsValue* r9 = new jsNumber(66.000000);
jsValue* r10 = Lessthan(r8,r9);
if (GetValue(r10)->ToBool()->value) {
jsValue* r11 = new jsReference(env, "x");
jsValue* r12 = new jsReference(env, "x");
jsValue* r13 = new jsNumber(5.000000);
jsValue* r14 = Plus(r12,r13);
jsValue* r15 = Assign(r11,r14);
goto WhileLabel1;
}
WhileLabel2:
jsValue* r16 = new jsReference(env, "x");
jsValue* r17 = new jsNumber(46.000000);
jsValue* r18 = Greaterthan(r16,r17);
if (GetValue(r18)->ToBool()->value) {
jsValue* r19 = new jsReference(env, "x");
jsValue* r20 = new jsReference(env, "x");
jsValue* r21 = new jsNumber(5.000000);
jsValue* r22 = Minus(r20,r21);
jsValue* r23 = Assign(r19,r22);
goto WhileLabel2;
}
jsValue* r24 = new jsReference(env, "x");
jsValue* r25 = new jsNumber(46.000000);
jsValue* r26 = Greaterthan(r24,r25);
if (GetValue(r26)->ToBool()->value) {
jsValue* r27 = new jsReference(env, "y");
jsValue* r28 = new jsReference(env, "x");
jsValue* r29 = new jsNumber(5.000000);
jsValue* r30 = Plus(r28,r29);
jsValue* r31 = Assign(r27,r30);
}
else {
jsValue* r32 = new jsReference(env, "y");
jsValue* r33 = new jsNumber(0.000000);
jsValue* r34 = Assign(r32,r33);
}
jsValue* r35 = new jsReference(env, "x");
jsValue* r36 = new jsReference(env, "x");
jsValue* r37 = new jsNumber(1.000000);
jsValue* r38 = Minus(r36,r37);
jsValue* r39 = Assign(r35,r38);
jsValue* r40 = new jsReference(env, "x");
jsValue* r41 = new jsReference(env, "x");
jsValue* r42 = new jsNumber(3.000000);
jsValue* r43 = Multiplication(r41,r42);
jsValue* r44 = Assign(r40,r43);
jsValue* r45 = new jsReference(env, "x");
jsValue* r46 = new jsReference(env, "x");
jsValue* r47 = new jsNumber(2.000000);
jsValue* r48 = Division(r46,r47);
jsValue* r49 = Assign(r45,r48);
jsValue* r50 = new jsReference(env, "x");
jsValue* r51 = new jsReference(env, "x");
jsValue* r52 = new jsNumber(4.000000);
jsValue* r53 = Modulus(r51,r52);
jsValue* r54 = Assign(r50,r53);
consolelog(GetValue(r54));
}
