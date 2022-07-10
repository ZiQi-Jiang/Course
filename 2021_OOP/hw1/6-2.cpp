Dog* clear()
{
  if(head==NULL)  return head;
	Dog* cur = head,*p=head->next,*r=NULL;
	while (p != NULL) {
		Dog* travel = p;
		while (travel != NULL && cur->no != travel->no) 
			travel = travel->next;
		if (travel != NULL) {
			if (cur == head) {
				delete(head);
				head = p;
				cur = head;
				p = p->next;
			}
			else {
				r->next = p;
				delete(cur);
				cur = p;
				p = p->next;
			}
		}
		else {
			r = cur;
			cur = cur->next;
			p = cur->next;
		}
	}
	return head;
}
Dog* insert(string& no, int age)
{
	Dog* newdog = new Dog;
	newdog->no = no;
	newdog->age = age;
	newdog->next = NULL;
	if (head == NULL) return newdog;
	Dog* cur = head,*p=NULL;
	while (cur != NULL && cur->age < newdog->age) {
		p = cur;
		cur = cur->next;
	}
	if (cur == head) {
		newdog->next = cur;
		return newdog;
	}
	newdog->next = cur;
	p->next = newdog;
	return head;
}
