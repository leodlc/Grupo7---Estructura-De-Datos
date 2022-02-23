#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <cwchar>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class pixel
{
private:
	cv::Mat _imagen{ 0 };
	int _type_process{ 0 };
	string ascii;

public:
	pixel(const std::string, const int);
	void mostrar();
	void console_font_size(int, int) noexcept;
	void escala_gris() noexcept;
	std::string char_ascii(int) noexcept;
	inline void intensidad();
	void tamano(int, int) noexcept;
	void archivo(std::string) noexcept;
};
