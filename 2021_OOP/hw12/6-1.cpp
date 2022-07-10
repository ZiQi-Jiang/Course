double division(int a, int b)
{
  const char *msg = "Divided by zero!";
  if (b == 0)
    throw msg;
  else
    return a / b;
}