/*R6-1 计算两点之间距离（友元函数） (10 分)  */
void pointDis( Point& p1, Point & p2)
{
    double x_2 = (p1.x-p2.x)*(p1.x-p2.x);
    double y_2 = (p1.y-p2.y)*(p1.y-p2.y);
    double dist = sqrt(x_2 + y_2);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<dist<<endl;
}