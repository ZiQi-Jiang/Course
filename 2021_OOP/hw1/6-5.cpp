
Task* getBatch(int m)   //接收一批任务，该批任务共有m项任务
{
    Task* p=NULL,*head = new Task,*tail = head;
    int K;
    cin >> K;
    while(m--)
    {
        p = new Task;
        cin >> p->ID>>p->load;
        p->key = K; p->next =NULL;
        tail->next = p;
        tail = tail->next;
    }
    p = head->next;
    delete head;
    return p;
}

Task* addBatch(Task *head, Task *h)//将h指向的小链表插入head指向的大链表，并返回新的大链表首指针。
{
    Task* sentinel = new Task;
    Task* h_head = h,*h_tail = h;
    while(h_tail->next)h_tail = h_tail->next;
    sentinel->next = head;
    Task* ptr = sentinel;
    while(ptr->next)
    {
        if(h_head->key <ptr->next->key) break;
        else ptr = ptr->next;
    }
    if(ptr->next==NULL) ptr->next = h;
    else
    {
        Task* ptr1 = ptr->next;
        ptr->next = h_head;
        h_tail->next = ptr1;
    }
    return sentinel->next;
}
void display(Task *head, int m)//输出第m项任务的信息，或者输出OK
{
    int count = 1;
    while(count++<m && head)  head = head->next;
    if(head==NULL)  cout<<"OK"<<endl;
    else
    cout<<head->ID<<" "<<head->key<<" "<<head->load<<endl;
    return;
}
Task* study(Task*head, int mi, int ma, int load)
{
    Task* sentinel = new Task;
    sentinel->next = head;
    Task* ptr = sentinel;
    while(ptr->next)
    {
        if(ptr->next->load >= mi && ptr->next->load<=ma &&
            load >= ptr->next->load)
        { 
            
            load-=ptr->next->load;
            Task* tmp = ptr->next;
            ptr->next = ptr->next->next;
            delete tmp;
            
        }
        else
        ptr = ptr->next;
    }
    return sentinel->next;
}
        
//mi是本次学习过程中，所学习的各个单项任务的最短持续时间约束，ma是单项任务的最长持续时间约束, load是本次学习过程的最长持续时间