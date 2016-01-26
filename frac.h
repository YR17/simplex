#ifndef FRAC_H
	#define FRAC_H
	#include <iostream>
	#include <cmath>
	class Fraction{
		int denominator;
		int numerator;
		friend std::ostream &operator<<(std::ostream &output, const Fraction &ob);
	public:
		Fraction():numerator(0),denominator(1){};
		Fraction(int n):numerator(n), denominator(1){};
		Fraction(int n, int d):denominator(d), numerator(n){};
		int getNumerator(){
			return numerator;
		}
		int getDenominator(){
			return denominator;
		}
		operator int(){
			return numerator/denominator;
		}
		operator float(){
			return (float)numerator/denominator;
		}
		operator double(){
			return (double)numerator/denominator;
		}
		void operator =(Fraction ob){
			numerator = ob.getNumerator();
			denominator = ob.getDenominator();
		}
		void operator =(int num){
			numerator = num;
			denominator = 1;
		}
		void resume(){
			if(numerator%denominator==0){
				numerator/=denominator;
				denominator = 1;
				return;
			}
			else if(denominator%numerator==0){
				denominator/=numerator;
				numerator = 1;
				return;
			}
			int max = abs(numerator)>abs(denominator)?abs(denominator):abs(numerator);
			for(int c = max/2;c>0;c--){
				if(numerator%c==0&&denominator%c==0){
					numerator/=c;
					denominator/=c;
					return;
				}
			}
		}
		void operator +=(Fraction ob){
			if(!ob.getNumerator())return;
			if(denominator==ob.getDenominator())numerator+=ob.getNumerator();
			else{
				numerator*=ob.getDenominator();
				numerator+=ob.getNumerator()*denominator;
				denominator*=ob.getDenominator();
			}
			resume();
		}
		void operator +=(int num){
			Fraction f(num);
			(*this)+=f;
			resume();
		}
		void operator -=(Fraction ob){
			if(!ob.getNumerator())return;
			if(denominator==ob.getDenominator())numerator-=ob.getNumerator();
			else{
				numerator*=ob.getDenominator();
				numerator-=ob.getNumerator()*denominator;
				denominator*=ob.getDenominator();
			}
			resume();
		}
		void operator -=(int num){
			Fraction f(num);
			(*this)-=f;
			resume();
		}
		void operator *=(Fraction ob){
			numerator*=ob.getNumerator();
			denominator*=ob.getDenominator();
			resume();
		}
		void operator *=(int num){
			numerator*=num;
			resume();
		}
		void operator /=(Fraction ob){
			if(!ob.getNumerator())return;
			numerator*=ob.getDenominator();
			denominator*=ob.getNumerator();
			resume();
		}
		void operator /=(int num){
			if(!num)return;
			denominator*=num;
			resume();
		}
		Fraction operator +(Fraction ob){
			Fraction result;
			result+=(*this);
			result+=ob;
			return result;
		}
		Fraction operator +(int num){
			Fraction result;
			result+=(*this);
			result+=num;
			return result;
		}
		Fraction operator -(Fraction ob){
			Fraction result;
			result+=(*this);
			result-=ob;
			return result;
		}
		Fraction operator -(int num){
			Fraction result;
			result+=(*this);
			result-=num;
			return result;
		}
		Fraction operator *(Fraction ob){
			Fraction result;
			result+=(*this);
			result*=ob;
			return result;
		}
		Fraction operator *(int num){
			Fraction result;
			result+=(*this);
			result*=num;
			return result;
		}
		Fraction operator /(Fraction ob){
			Fraction result;
			result+=(*this);
			result/=ob;
			return result;
		}
		Fraction operator /(int num){
			Fraction result;
			result+=(*this);
			result/=num;
			return result;
		}
		bool operator >(int num){
			return (int)(*this)>num;
		}
		bool operator <(int num){
			return (int)(*this)<num;
		}
		bool operator >=(int num){
			return (int)(*this)>=num;
		}
		bool operator <=(int num){
			return (int)(*this)<=num;
		}
		bool operator ==(int num){
			return (int)(*this)==num;
		}
		bool operator >(Fraction ob){
			return (double)(*this)>(double)ob;
		}
		bool operator <(Fraction ob){
			return (double)(*this)<(double)ob;
		}
		bool operator >=(Fraction ob){
			return (double)(*this)>(double)ob;
		}
		bool operator <=(Fraction ob){
			return (double)(*this)<(double)ob;
		}
		bool operator ==(Fraction ob){
			return numerator==ob.getNumerator()&&denominator==ob.getDenominator();
		}
	};
	std::ostream &operator<<(std::ostream &output, const Fraction &ob){
    output<<ob.numerator;
    if(ob.denominator>1)output<<"/"<<ob.denominator;
    return output;
		}
#endif