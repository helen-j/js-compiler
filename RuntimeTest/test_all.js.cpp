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
jsValue* r8 = new jsReference(env, "x");
jsValue* r9 = new jsNumber(46.000000);
jsValue* r10 = Equals(r8,r9);
if (GetValue(r10)->ToBool()->value) {
jsValue* r11 = new jsReference(env, "y");
jsValue* r12 = new jsReference(env, "x");
jsValue* r13 = new jsNumber(5.000000);
jsValue* r14 = Plus(r12,r13);
jsValue* r15 = Assign(r11,r14);
}
else {
jsValue* r16 = new jsReference(env, "y");
jsValue* r17 = new jsNumber(0.000000);
jsValue* r18 = Assign(r16,r17);
}
jsValue* r19 = new jsReference(env, "x");
jsValue* r20 = new jsReference(env, "x");
jsValue* r21 = new jsNumber(1.000000);
jsValue* r22 = Minus(r20,r21);
jsValue* r23 = Assign(r19,r22);
consolelog(GetValue(r23));
//Manually add the following lines to print y
jsValue* r24 = new jsReference(env, "y");
consolelog(GetValue(r24));
}
