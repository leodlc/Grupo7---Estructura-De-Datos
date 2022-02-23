#include "pixelatedImg.h"
#pragma warning(disable : 4996)

pixel::pixel(const std::string src, const int type_process)
	: _imagen(cv::imread(src)), _type_process(type_process)
{
}

void pixel::mostrar()
{
	pixel::intensidad();
}

void pixel::console_font_size(int x, int y) noexcept
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = x;
	cfi.dwFontSize.Y = y;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void pixel::escala_gris() noexcept
{
	cv::Mat _imagen_gris;
	cv::cvtColor(_imagen, _imagen_gris, cv::COLOR_BGR2GRAY);
	_imagen = _imagen_gris;
}

inline void pixel::intensidad()
{
	double unit = (256.0 + 1) / 68.0;
	int cn = _imagen.channels();
	std::string str;
	uint8_t* pixelPtr = (uint8_t*)_imagen.data;
	cv::Scalar_<uint8_t> bgrPixel;
	for (int i = 0; i < _imagen.rows; i++)
	{
		for (int j = 0; j < _imagen.cols; j++)
		{
			int R = pixelPtr[i * _imagen.cols * cn + j * cn + 2];
			int G = pixelPtr[i * _imagen.cols * cn + j * cn + 1];
			int B = pixelPtr[i * _imagen.cols * cn + j * cn + 0];
			int grayScaleValue = (B * 0.0722) + // B
				(G * 0.7152) + // G
				(R * 0.2126);	// R
			int intensidad = grayScaleValue / unit;
			str = char_ascii(intensidad);
			ascii += str;
			printf("\033[%d;2;%d;%d;%dm%c\033[0;00m", _type_process, R, G, B, str[0]);
		}
		ascii += "\n";
		std::cout << std::endl;
	}
}

void pixel::tamano(int x, int y) noexcept
{
	cv::Mat resizeImage;
	cv::resize(_imagen, resizeImage, cv::Size(x, y));
	_imagen = resizeImage;
}

void pixel::archivo(std::string nombre) noexcept
{
	std::ofstream file;
	file.open(nombre);
	if (file.is_open())
		file << ascii;

	file.close();
}


std::string pixel::char_ascii(int intensidad) noexcept
{
	std::vector<std::string> map{
		"$", "@", "B", "%", "8", "&", "W", "M", "#", "*", "o", "a", "h", "k", "b", "d", "p", "q", "w", "m", "Z",
		"O", "0", "Q", "L", "C", "J", "U", "Y", "X", "z", "c", "v", "u", "n", "x", "r", "j", "f", "t", "/", "\\",
		"|", "(", ")", "1", "{", "}", "[", "]", "?", "-", "_", "+", "~", "<", ">", "i", "!", "l",
		"I", ";", ":", "\"", "^", "`", "'", "." };
	return map[intensidad];
}