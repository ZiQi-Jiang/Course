class Circle{
	double m_r;
	public:
	void setR(double r)
	{
		m_r = r;
	}
	double getR()
	{
		return m_r;
	}
	double getArea()
	{
		return 3.14159*m_r*m_r;
	}
};