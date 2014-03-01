#include<iostream>
#include<cmath>
using namespace std;

/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x){
	//the key feature is that MSB is 1 and other bits are 0
	return (!((x<<1)|0))&(((1<<31)&x)>>31);
	//return !(x^(~x+1))&(!!x);
}


/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void){
	//the MSB is 0 and other bits are 0
	return ~(1<<31);
}

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {                     	
	int tmp=(~0)+(1<<(n+(-1)));//the (n-1) lower bits is 1 and others are 0
	//for negative number, other than n-1 lower bits,should be all 1
	//for positive number, other than n-1 lower bits, should be all 0
	return (!(~(tmp|x)))|(!((~tmp)&x));
}

/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
	//very good~~
	return ((~x)+1)&x;
}

/* 
 * oddBits - return word with all odd-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int oddBits(void) {	
	int tmp=170;
	return tmp+(tmp<<8)+(tmp<<16)+(tmp<<24);
}

/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
	//left shift 31 bits will apply to 0 and negative numbers
	//and then design strategy for positive numbers
	int tmp1=!((1<<31)&x);
	int tmp2=!!((~0)&x);
	//return 0;
	return (x>>31)+(tmp1&tmp2);
}

/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
	//to calculate x-y using add 2's implement code
	int sum=x+((~y)+1);
	int tmp1=(~0)&sum;
	int tmp2=!((1<<31)&sum);
	return tmp1&tmp2;
}

/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {	
	int negativeY=(~y)+1;
	int sum=x+negativeY;	
	int con=1<<31;
	int tmp1=con&x;
	int tmp2=con&negativeY;
	int tmp3=con&sum;
	//cout<<(!!(con&y))<<endl;
	//cout<<(!((~con)&y))<<endl;
	//modify this can reduce one operator further more
	int tmp4=(!!tmp2)&(!((~con)&y));
	//cout<<"tmp4: "<<tmp4<<endl;
	//the adders should have same sign
	//but result has s different sign bit if overflow occurs
	return (tmp1^tmp2)|(!(tmp1^tmp3))|tmp4;

}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int invert=((!!x)<<31)>>31;
	//if x is zero, then invert is all 0s
	//if x is non zero, then invert is all 1s
	return ((~invert)&z)+(invert&y);
}

/* 
 * replaceByte(x,n,c) - Replace byte n in x with c
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: replaceByte(0x12345678,1,0xab) = 0x1234ab78
 *   You can assume 0 <= n <= 3 and 0 <= c <= 255
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 3
 */
int replaceByte(int x, int n, int c) {
	//to implement the function 4*n
	int shift=n<<3;
	int tmp1=c<<shift;
	//clear the corresponding bits
	int tmp2=(~(255<<shift))&x;
	return tmp1|tmp2;
}

/*
 * satMul3 - multiplies by 3, saturating to Tmin or Tmax if overflow
 *  Examples: satMul3(0x10000000) = 0x30000000
 *            satMul3(0x30000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0x70000000) = 0x7FFFFFFF (Saturate to TMax)
 *            satMul3(0xD0000000) = 0x80000000 (Saturate to TMin)
 *            satMul3(0xA0000000) = 0x80000000 (Saturate to TMin)
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 3
 */
int satMul3(int x) {
	int double_x=x<<1;
	int sum=double_x+x;
	//cout<<"x*2: "<<hex<<(x<<1)<<endl;
	//cout<<"sum: "<<hex<<sum<<endl;
	int testNumber=1<<31;
	//first type of overflow
	int tmp0=double_x&testNumber;
	int tmp1=testNumber&x;
	//second type of overflow
	int tmp2=testNumber&sum;
	//tmp3 is 1 indicate overflow occurs
	int tmp3=tmp1^tmp2;
	int tmp4=tmp0^tmp1;
	//either type occurs will result into an overflow
	int upOverflow=((tmp3&sum)|(tmp4&tmp0))>>31;
	int downOverflow=((tmp3&x)|(tmp4&x))>>31;
	int maximum=~testNumber;
	int minimum=testNumber;
	int case1=upOverflow&maximum;
	int case2=downOverflow&minimum;
	int case3=sum&(~(upOverflow|downOverflow));
	return case1+case2+case3;
}//24 operators ><


/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	int bitsNumber=0;
	//change the left most bit to 0
	int tmp=((1<<31)&x)>>31;
	x=tmp^x;
	//binary search process
	bitsNumber=(!!(x>>16))<<4;
	bitsNumber=bitsNumber+((!!(x>>(bitsNumber+8)))<<3);
	bitsNumber=bitsNumber+((!!(x>>(bitsNumber+4)))<<2);
	bitsNumber=bitsNumber+((!!(x>>(bitsNumber+2)))<<1);
	bitsNumber=bitsNumber+(!!(x>>(bitsNumber+1)));
	//for non zero bitsNumber, it should add 2
	//for zero bitsNumber, it should add 1
	bitsNumber=bitsNumber+(!!bitsNumber)+1;
	return bitsNumber;
}

/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned int float_i2f(int x) {	
	int signBit=0;
	int leftZeroCounter=0;
	unsigned int copyX=x;
	unsigned int lowerBits=0;
	unsigned int round;	
	int tail;
	int tailCounter;
	int exponent;
	//x is equal to zero
	if(x==0)
		return 0;
	//turn x to positive number
	if(x<0){
		signBit=(1<<31)&x;
		x=-x;
	}
	//while the MSB is not equal to 1
	while((copyX&(1<<31))==0){
		leftZeroCounter++;
		copyX=copyX<<1;
	}	
	//exponent=32-1-leftZeroCounter+127;
	exponent=158-leftZeroCounter;
	copyX=copyX<<1;
	tailCounter=32-leftZeroCounter-1;	
	if(tailCounter<=23){
		tail=copyX>>9;
	}
	//lose precision, we have to consider rounding problem
	else{
		lowerBits=(copyX<<23)>>(23+1+leftZeroCounter);
		round=1<<(tailCounter-23-1);
		tail=copyX>>(tailCounter-23+leftZeroCounter+1);

		//need to round to bigger number
		if(lowerBits>round)
			tail++;
		//round to nearest even number
		if(lowerBits==round){
			if(lowerBits&1)
				tail++;
		}

	}	
	return (signBit|(tail+(exponent<<23)));
}

int main(){	
	cout<<"here"<<endl;
	//cout<<(float)float_i2f(0)<<endl;
	cout<<hex<<float_i2f(20)<<endl;
	//cout<<howManyBits(12)<<endl;
    //cout<<howManyBits(298)<<endl;
    //cout<<howManyBits(-5)<<endl;
    //cout<<howManyBits(0)<<endl;
    //cout<<howManyBits(-1)<<endl;
    //cout<<howManyBits(0x80000000)<<endl;
	//cout<<hex<<satMul3(0x10000000)<<endl;
	//cout<<hex<<satMul3(0x30000000)<<endl;
	//cout<<hex<<satMul3(0x70000000)<<endl;
	//cout<<hex<<satMul3(0xD0000000)<<endl;
	//cout<<hex<<satMul3(0xA0000000)<<endl;
	//cout<<hex<<replaceByte(0x12345678,1,0xab)<<endl;
	//cout<<conditional(2,4,5)<<endl;
	//cout<<conditional(0,4,5)<<endl;
	//cout<<(int)0x80000000<<endl;
	//cout<<subOK(0x80000000,0x80000000)<<endl;
	//cout<<subOK(0x80000000,0x70000000)<<endl;
	//cout<<isGreater(4,5)<<endl;
	//cout<<isGreater(5,4)<<endl;
	//cout<<isGreater(6,6)<<endl;
	//cout<<!!(-1)<<endl;
	//cout<<isTmin((int)-pow(2.0,31))<<endl;
	//cout<<isTmin(10)<<endl;
	//cout<<(int)-pow(2.0,31)<<endl;
	//cout<<(int)(pow(2.0,31)-1)<<endl;
	//cout<<"tmax: "<<tmax()<<endl;
	//cout<<fitsBits(5,3)<<endl;
	//cout<<fitsBits(-4,3)<<endl;
	//cout<<leastBitPos(96)<<endl;
	//cout<<oddBits()<<endl;
	//cout<<((-23)>>31)<<endl;
	//cout<<sign(0)<<endl;
	//cout<<sign(130)<<endl;
	//cout<<sign(-23)<<endl;
	system("pause");
	return 0;
}
