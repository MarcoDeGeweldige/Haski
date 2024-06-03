#include "pch.h"
#include "Sprite.h"



Sprite::Sprite() {


}

//use the filepath to directly load this file,
//us numframes for cell animation
Sprite::Sprite(std::wstring& filePath,ID2D1DeviceContext2* d2dContext, IWICImagingFactory2* wicFactory) {

	BitmapDrawer bitDrawer(d2dContext, wicFactory);
	d2dBitmap = bitDrawer.ReadAndSaveBitmap(filePath);
	//test size
	auto test = d2dBitmap->GetSize();
	int stop = 0;


}


