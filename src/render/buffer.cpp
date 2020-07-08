#include <fstream>
#include <iostream>

#include <render/buffer.hpp>

void render::Buffer::toPPM(const char *path, float gamma) // gamma=2.2f
{
    std::fstream f(path, std::ios::out);

    f << "P3" << std::endl;
    f << sizeX << ' ' << sizeY << " 255" << std::endl;

    for (int h = sizeY - 1; h >= 0; h--)
    {
        for (int w = 0; w < sizeX; w++)
        {
            vec::float4 color = pixel(w, h);
            vec::float4 colorCorrect = pow(color, 1.0f / gamma);
            vec::float4 clamped = clamp(colorCorrect, 0.0f, 1.0f) * 255.0f;

            for (int i = 0; i < 3; i++)
            {
                f << std::to_string((unsigned char)clamped[i]) << ' ';
            }
        }
        f << std::endl;
    }

    f.close();
}

render::Buffer render::Buffer::fromPPM(const char *path, float gamma) // gamma=2.2f
{
    std::fstream f(path, std::ios::in);

    char p;
    int type;
    f >> p >> type;

    if (p != 'P' || type != 3)
    {
        throw "Only capable of reading P3 format";
    }

    int width, height, max_;
    f >> width >> height >> max_;

    render::Buffer buffer(width, height);

    int r, g, b;
    for (int h = height - 1; h >= 0; h--)
    {
        for (int w = 0; w < width; w++)
        {
            f >> r >> g >> b;
            vec::float4 px(
                std::min(r, max_) / 255.0f,
                std::min(g, max_) / 255.0f,
                std::min(b, max_) / 255.0f,
                1.0f);
            buffer.arr[w + width * h] = pow(px, gamma);
        }
    }

    f.close();

    // TODO: move semantics
    return buffer;
}