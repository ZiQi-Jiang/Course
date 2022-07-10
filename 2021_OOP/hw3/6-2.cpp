  /* 6-2 学生排名表（析构函数） (10 分) */
  
    Student*Tmp= new Student("0",0);
    for(int i=0; i < count; i++)
      for(int j=0; j < count-i-1;j++)
        if(pS[j]->getRank() > pS[j+1]->getRank() )
        {
            Tmp = pS[j]; pS[j] = pS[j+1];pS[j+1]=Tmp;
        }
    for(int i=0; i<count; i++)  delete pS[i];