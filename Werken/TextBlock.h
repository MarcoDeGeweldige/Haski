#pragma once
#include <SpriteBatch.h>
#include <DirectXMath.h>
#include <SimpleMath.h>

class TextBlock
{

    //SimpleMath::Vector2 m_fontPos;
    std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;


    // Create a DirectWrite text format object
    Microsoft::WRL::ComPtr<IDWriteTextFormat> textFormat;

};

