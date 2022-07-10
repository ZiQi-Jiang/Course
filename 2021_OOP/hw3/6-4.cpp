/* 6-4 Tree类的构造函数和成员函数 (10 分) */
Tree::Tree()
{
    ages = 1;
}

void Tree::grow(int years)
{
    ages+=years;
}

void Tree::age()
{
    cout<<ages;
}