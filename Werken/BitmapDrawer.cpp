#include "pch.h"
#include "BitmapDrawer.h"



BitmapDrawer::BitmapDrawer(ID2D1DeviceContext2* d2dContext, IWICImagingFactory2* wicFactory) : m_d2dContext(d2dContext), m_wicFactory(wicFactory)
{
}

void BitmapDrawer::DrawBitmap(ComPtr<ID2D1Bitmap> bitmap, const D2D1_RECT_F& destinationRect)
{

    m_d2dContext->DrawBitmap(bitmap.Get(), destinationRect);
}

void BitmapDrawer::DrawBitmap(const std::wstring& filePath, const D2D1_RECT_F& destinationRect)
{
    ComPtr<IWICBitmapDecoder> decoder;
    DX::ThrowIfFailed(m_wicFactory->CreateDecoderFromFilename(
        filePath.c_str(),
        nullptr,
        GENERIC_READ,
        WICDecodeMetadataCacheOnDemand,
        decoder.GetAddressOf()));

    ComPtr<IWICBitmapFrameDecode> frame;
    DX::ThrowIfFailed(decoder->GetFrame(0, frame.GetAddressOf()));

    ComPtr<IWICFormatConverter> formatConverter;
    DX::ThrowIfFailed(m_wicFactory->CreateFormatConverter(formatConverter.GetAddressOf()));

    DX::ThrowIfFailed(formatConverter->Initialize(
        frame.Get(),
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        nullptr,
        0.f,
        WICBitmapPaletteTypeMedianCut));

    ComPtr<ID2D1Bitmap> d2dBitmap;
    DX::ThrowIfFailed(m_d2dContext->CreateBitmapFromWicBitmap(
        formatConverter.Get(),
        d2dBitmap.GetAddressOf()));

    m_d2dContext->DrawBitmap(d2dBitmap.Get(), destinationRect);
}

ComPtr<ID2D1Bitmap> BitmapDrawer::ReadAndSaveBitmap(std::wstring& filePath)
{
    ComPtr<IWICBitmapDecoder> decoder;
    DX::ThrowIfFailed(m_wicFactory->CreateDecoderFromFilename(
        filePath.c_str(),
        nullptr,
        GENERIC_READ,
        WICDecodeMetadataCacheOnDemand,
        decoder.GetAddressOf()));

    ComPtr<IWICBitmapFrameDecode> frame;
    DX::ThrowIfFailed(decoder->GetFrame(0, frame.GetAddressOf()));

    ComPtr<IWICFormatConverter> formatConverter;
    DX::ThrowIfFailed(m_wicFactory->CreateFormatConverter(formatConverter.GetAddressOf()));

    DX::ThrowIfFailed(formatConverter->Initialize(
        frame.Get(),
        GUID_WICPixelFormat32bppPBGRA,
        WICBitmapDitherTypeNone,
        nullptr,
        0.f,
        WICBitmapPaletteTypeMedianCut));

    ComPtr<ID2D1Bitmap> d2dBitmap;
    DX::ThrowIfFailed(m_d2dContext->CreateBitmapFromWicBitmap(
        formatConverter.Get(),
        d2dBitmap.GetAddressOf()));
    return d2dBitmap;
}


