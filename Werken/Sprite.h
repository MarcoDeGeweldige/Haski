#pragma once
#include <string>
#include <BitmapDrawer.h>
using namespace Microsoft::WRL;


class Sprite
{


public:


    // Structors
    //the sprite animation will be hard to reprogram but i am sure thigns will.......
    Sprite();
    Sprite(std::wstring& filePath,ID2D1DeviceContext2* d2dContext, IWICImagingFactory2* wicFactory);

    int get_width() { return m_Width; }
    int get_height() { return m_Height; }
    ComPtr<ID2D1Bitmap> d2dBitmap;


private:
    // Attributes
    int m_Width, m_Height, m_Pitch;


};

