//必需检测每一个点和之前所有点,和之后的一个点
/*
	考虑如下case:
	3
	a 1     100
	b 2     10
	c 3     20
*/ 

Node* add(Node *head, Node *p)
{
    Node* Sentinel = new Node;
    Sentinel->next = head; // define a sentinel to simplify the cases
    
    Node* Ptr = Sentinel;
    while(Ptr->next)
    {
      if(p->start < Ptr->next->start)
      {
        p->next = Ptr->next;
        Ptr->next = p;
        break;
      }
       else  Ptr = Ptr->next;
       
    }
    if(Ptr->next == NULL)  Ptr->next = p;
    
    return Sentinel->next;
    
}

void display(Node *head)
{
	Node* Ptr1 = head,*Ptr2 = Ptr1->next;
	if(Ptr2 && Ptr1->end > Ptr2->start) cout<<"*";
	cout << head->name<<" "<<head->start<<" "<<head->end<<endl;
	while(Ptr2)
	{
		Ptr1 = head; 
		bool flag = false;
		Node* Ptr3 = Ptr2->next;
		if(Ptr3!=NULL && Ptr3->start<Ptr2->end)  flag = true;
		while(Ptr1 != Ptr2)
		{
			 if(Ptr1->end > Ptr2->start)
			 {
			 	flag = true;
			 	break;
			 }
			 Ptr1 = Ptr1->next;
		}
		if(flag)  cout<<"*";
		cout << Ptr2->name<<" "<<Ptr2->start \
		              <<" "<<Ptr2->end<<endl;
		Ptr1 = Ptr1->next;
		Ptr2 = Ptr2->next;
	}
	return ;
}