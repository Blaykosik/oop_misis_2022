#include <algorithm>

class Rectangle
{
public:
    Rectangle() = default;
    Rectangle(int _x1, int _x2, int _y1, int _y2);
    ~Rectangle() = default;
    int Width() const;
    int Height() const;
    int Perimetr() const;
    int Area() const;
    bool Intersect(const Rectangle& other) const;
    int IntersectArea(const Rectangle& other) const;


private:
    int x1;
    int x2;
    int y1;
    int y2;
};

Rectangle::Rectangle(int _x1, int _x2, int _y1, int _y2) {
    x1 = std::min(_x1, _x2);
    x2 = std::max(_x1, _x2);
    y1 = std::min(_y1, _y2);
    y2 = std::max(_y1, _y2);
}

int Rectangle::Width() const {
    return x2 - x1;
}

int Rectangle::Height() const {
    return y2 - y1;
}

int Rectangle::Perimetr() const {
    return (Width() + Height()) * 2;
}

int Rectangle::Area() const {
    return Width() * Height();
}


bool Rectangle::Intersect(const Rectangle& other) const {
    return (std::max(other.x2, x2) - std::min(x1, other.x1) < Width() + other.Width() &&
            std::min(x2, other.x2) - std::max(x1, other.x1) < std::min(Width(), other.Width()) ||
            std::max(other.y2, y2) - std::min(y1, other.y1) < Height() + other.Height() &&
            std::min(y2, other.y2) - std::max(y1, other.y1) < std::min(Height(), other.Height()));
}

int Rectangle::IntersectArea(const Rectangle& other) const {
    if (!Intersect(other)) return 0;
    return (std::min(x2, other.x2) - std::max(x1, other.x1)) * (std::min(y2, other.y2) - std::max(y1, other.y1));
}