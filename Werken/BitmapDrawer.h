#pragma once
#include <string>
#include <wrl.h>
#include <wrl/client.h>
#include <dxgi1_4.h>
#include <d3d11_3.h>
#include <d2d1_3.h>
#include <d2d1effects_2.h>
#include <dwrite_3.h>
#include <wincodec.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <memory>
#include <agile.h>
#include <concrt.h>
#include <string>
#include "..\Common\DeviceResources.h"
#include "..\Common\StepTimer.h"
#include <wincodec.h>
#include <Common/DirectXHelper.h>
using namespace Microsoft::WRL;



    class BitmapDrawer
    {
    public:

        /// Constructor for BitmapDrawer.
        /// \param d2dContext A pointer to the ID2D1DeviceContext2 interface.
        /// \param wicFactory A pointer to the IWICImagingFactory2 interface.
        BitmapDrawer(ID2D1DeviceContext2* d2dContext, IWICImagingFactory2* wicFactory);

        void DrawBitmap(ComPtr<ID2D1Bitmap> bitmap, const D2D1_RECT_F& destinationRect);

        /// Draws a bitmap onto the context at the specified destination rectangle.
        /// \param bitmap A smart pointer to the ID2D1Bitmap interface.
        /// \param destinationRect The rectangle area where the bitmap will be drawn.
        
        void DrawBitmap(const std::wstring& filePath, const D2D1_RECT_F& destinationRect);


        /// Reads a bitmap from a file, converts it to a Direct2D bitmap, and returns it.
        /// \param filePath The path to the bitmap file.
        /// \return A smart pointer to the ID2D1Bitmap interface.
        ComPtr<ID2D1Bitmap> ReadAndSaveBitmap(std::wstring& filePath);
    private:
        Microsoft::WRL::ComPtr<ID2D1DeviceContext2> m_d2dContext;
        Microsoft::WRL::ComPtr<IWICImagingFactory2> m_wicFactory;
    };