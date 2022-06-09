#include "includes.h"

struct FileHeader 
{
    short bfType;
    int bfSize;
    short bfReserved1;
    short bfReserved2;
    int bfOffBits;
}
File;

struct PictureHeader 
{
    int biSize;
    int biWidth;
    int biHeight;
    short biPlanes;
    short biBitCount;
    int biCompression;
    int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    int biClrUsed;
    int biClrImportant;
}
Picture;

struct RGBColors {
    char R;
    char G;
    char B;
} Rgb;
int main(int arc, char* argv[]) {

    FILE* f; 
    f = fopen("test1.bmp", "rb");

    if (f == nullptr)
    {
        printf("\n\n Nie mozna otworzyc pliku");
        return -1;
    }
    else
    {
        printf("\n\n Plik f zostal otwarty!");
    }

    printf("\n informacje pliku BMP: \n\n");

    fread(&File.bfType, sizeof(File.bfType), 1, f);
    printf(" Typ: %x", File.bfType);

    fread(&File.bfSize, sizeof(File.bfSize), 1, f);
    printf("\n Rozmiar pliku: %d bajtow", File.bfSize);

    fread(&File.bfOffBits, sizeof(File.bfOffBits), 1, f);
    printf("\n Pozycja danych obrazkowych: %d", File.bfOffBits);

    printf("\n");

    fseek(f, 14, SEEK_SET);
    fread(&Picture.biSize, sizeof(Picture.biSize), 1, f);
    printf("\n Wielkosc naglowka informacyjnego: %d", Picture.biSize);

    fread(&Picture.biWidth, sizeof(Picture.biWidth), 1, f);
    printf("\n Szerokosc: %d pikseli", Picture.biWidth);

    fread(&Picture.biHeight, sizeof(Picture.biHeight), 1, f);
    printf("\n Wysokosc: %d pikseli", Picture.biHeight);

    fread(&Picture.biPlanes, sizeof(Picture.biPlanes), 1, f);
    printf("\n Liczba platow: %d", Picture.biPlanes);

    fread(&Picture.biBitCount, sizeof(Picture.biBitCount), 1, f);
    printf("\n Liczba bitow/piksel: %d (1, 4, 8, or 24)", Picture.biBitCount);

    fread(&Picture.biCompression, sizeof(Picture.biCompression), 1, f);
    printf("\n Kompresja: %d (0=none, 1=RLE-8, 2=RLE-4)", Picture.biCompression);

    fread(&Picture.biSizeImage, sizeof(Picture.biSizeImage), 1, f);
    printf("\n Rozmiar rysunku wynosi : %d", Picture.biSizeImage);

    fread(&Picture.biXPelsPerMeter, sizeof(Picture.biXPelsPerMeter), 1, f);
    printf("\n Rozdzielczosc - poziom: %d", Picture.biXPelsPerMeter);

    fread(&Picture.biYPelsPerMeter, sizeof(Picture.biYPelsPerMeter), 1, f);
    printf("\n Rozdzielczosc - pion: %d", Picture.biYPelsPerMeter);

    return 0;
}