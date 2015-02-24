#include <client/View.h>

lae3::client::View::View()
{
    //ctor
}

lae3::client::View::~View()
{
    //dtor
}


/* static */ sf::FloatRect lae3::client::View::computeViewport(unsigned width, unsigned height)
{
    float w = static_cast<float>(width);
    float h = static_cast<float>(height);

    float r = w / h;

    sf::FloatRect vp;

    if (width < height)
    {
        vp.left = 0.0f;
        vp.width = 1.0;

        vp.top = (1 - r) / 2;
        vp.height = r;
    }
    else
    {
        vp.top = 0.0f;
        vp.height = 1.0f;

        vp.left = (1 - 1 / r) / 2;
        vp.width = 1 / r;
    }

    return vp;
}
