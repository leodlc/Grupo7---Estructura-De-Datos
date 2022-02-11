#pragma once
template<typename T>
class FuncionRecursiva
{
public:
	
	FuncionRecursiva();
	T factorial(T n);
	void setN(T n);
	
private:
	T n;
};

