A A::operator+(A & a)
{
    return A(x+a.x,y+a.y);
}
A A::operator-(A & a)
{
    return A(x-a.x,y-a.y);
}