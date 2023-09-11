#pragma once

extern "C"
{
	__declspec(dllimport) const char* GetCodename();
	__declspec(dllimport) double sumar(double a, double b);
}