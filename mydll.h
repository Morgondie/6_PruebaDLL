#pragma once
#include <string>

extern "C"
{
	__declspec(dllimport) const char* GetCodename();
	__declspec(dllimport) double sumar(double a, double b);
	_declspec(dllimport) std::string Concatenar(const std::string frase1, const std::string frase2);
}