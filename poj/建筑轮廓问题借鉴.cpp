#include<iostream>
#include<stdio.h>
 using namespace std;
 class Link                   //�ڵ���
 {
 public:
     int l,r,h;
     Link *next;
     inline Link(int a,int b,int c,Link *v=NULL)
     {
         l=a;
         r=b;
         h=c;
         next=v;
     }
     inline Link(Link *v=NULL)
     {
         next=v;
     }
 };
 class lnkList                 //������
 {
 public:
     Link *head,*tail;           //ͷ��βָ��
     inline lnkList();
     inline bool append(int,int,int);          //�ڱ�β���һ��Ԫ��
     void hebin(Link *,Link *,Link *&);     //�ϲ���������
     //��kaishi��mowei�佨����������βָ�봫�ݵ������ã���ʹ������ά��
     void lunkuo(Link *h,int kaishi,int mowei,Link *&t);    
     void dayin(void);
 };
 inline lnkList::lnkList()
 {
     head=tail=new Link;
 }
 inline bool lnkList::append(int a,int b,int c)
 {
     Link *p;
     p=new Link(a,b,c);
     tail->next=p;
     tail=p;
     return true;
 }
 //�ϲ��������������еĺ�벿��middle��t�Ľ����ϲ���ǰ�벿��h��middle�У�Ȼ��ɾ����벿��
 void lnkList::hebin(Link *h,Link *middle,Link *&t)
 {
     Link *l,*r,*fl,*fr;        //ָ�뼰��ָ��
     Link *tem;
     fl=h;
     fr=middle;                //��ָ��
     l=fl->next;
     r=fr->next;
     Link *tt=new Link(t->l,t->r,r->h,t->next);
     while(l!=middle->next&&r!=tt->next)
     {
         //ö������������λ�ù�ϵ
         //������������ཻ����δ�ཻ���ֱ��һ���µĽ��������뵽�����У�ͬʱ��С��������
         //������������ǰ�����ϵ��ɾ���������Ľ���
         //��������������룬��ֱ�Ӹı������λ�ü���
         if(l->l==r->l)              //����������������
         {
             if(l->h>=r->h)
             {
                 if(l->r>=r->r)     //��һ��������ǰһ������
                 {
                     if(l->r==r->r){      
                         fl=fl->next;
                         l=fl->next;
                     }
                     fr->next=r->next;      //ɾ����һ������
                     delete r;
                     r=fr->next;
                 }
                 else                   //���������ཻ����С��һ������
                     r->l=l->r;
             }
             else
             {
                 if(r->r>=l->r)
                 {
                     l->h=r->h;
                     if(r->r==l->r){
                         fr->next=r->next;
                         delete r;
                         r=fr->next;
                     }
                     else
                         r->l=l->r;
                     fl=fl->next;
                     l=l->next;
                 }
                 else{
                     tem=new Link(r->l,r->r,r->h);
                     fl->next=tem;
                     fl=tem;
                     tem->next=l;
                     l->l=r->r;
                     fr->next=r->next;
                     delete r;
                     r=fr->next;
                 }
             }
         }
         else{
             if(l->l<r->l)                 //ǰһ����������߱Ⱥ�һ����С
             {
                 if(l->h>=r->h)
                 {
                     if(l->r<=r->l)
                     {
                         fl=fl->next;
                         l=fl->next;
                     }
                     else{
                         if(l->r>=r->r)
                         {
                             if(l->r==r->r)
                             {
                                 fl=fl->next;
                                 l=fl->next;
                             }
                             fr->next=r->next;
                             delete r;
                             r=fr->next;
                         }
                         else
                         {
                             r->l=l->r;
                             fl=fl->next;
                             l=fl->next;
                         }
                     }
                 }
                 else
                 {
                     if(l->r<=r->l)
                     {
                         fl=fl->next;
                         l=fl->next;
                     }
                     else
                     {
                         tem=new Link(l->l,r->l,l->h);  //��δ�ཻ���ֱ���µ�
                         fl->next=tem;                  //����������������
                         fl=tem;
                         tem->next=l;
                         l->l=r->l;
                     }
                 }
             }
             else                            //���¸����������������
             {
                 if(r->h>=l->h)
                 {
                     if(r->r<=l->l)
                     {
                         tem=new Link(r->l,r->r,r->h);
                         fl->next=tem;
                         fl=tem;
                         tem->next=l;
                         fr->next=r->next;
                         delete r;
                         r=fr->next;
                     }
                     else{
                         if(r->r<=l->r)
                         {
                             if(r->r<l->r)
                             {
                                 tem=new Link(r->l,r->r,r->h);
                                 fl->next=tem;
                                 fl=tem;
                                 tem->next=l;
                                 l->l=r->r;
                             }
                             else
                             {
                                 l->l=r->l;
                                 l->r=r->r;
                                 l->h=r->h;
                                 fl=fl->next;
                                 l=fl->next;
                             }
                             fr->next=r->next;
                             delete r;
                             r=fr->next;
                         }
                         else
                         {
                             tem=new Link(r->l,l->l,r->h);
                             fl->next=tem;
                             fl=tem;
                             tem->next=l;
                             r->l=l->l;
                         }
                     }
                 }
                 else
                 {
                     if(r->r<=l->l)
                     {
                         tem=new Link(r->l,r->r,r->h);
                         fl->next=tem;
                         fl=tem;
                         tem->next=l;
                         fr->next=r->next;
                         delete r;
                         r=fr->next;
                     }
                     else{
                         tem=new Link(r->l,l->l,r->h);
                         fl->next=tem;
                         fl=tem;
                         tem->next=l;
                         r->l=l->l;
                     }
                 }
             }
         }
     }
     if(r==tt->next)               //���βָ�뱻delete������ʹ�临ԭ������ָ��β��
         t=middle;
     delete tt;
     return ;
 }
 void lnkList::lunkuo(Link *h,int kaishi,int mowei,Link *&t)   
 {
     if(mowei>kaishi)
     {
         Link *middle=h;
         //ȷ���м佨�����ڵĽڵ�
         for(int i=kaishi;i<=(kaishi+mowei)/2;i++)
             middle=middle->next;
           //�ݹ����ǰ�벿�ֺͺ�벿�ֵĽ�������
         lunkuo(h,kaishi,(kaishi+mowei)/2,middle);
         lunkuo(middle,(kaishi+mowei)/2+1,mowei,t);
         hebin(h,middle,t);
           //�ϲ������и߶���ͬ����β�����Ľ���
         Link *p,*fp;
         fp=h->next;
         p=fp->next;
           while(p!=t->next)
         {
                if(fp->r==p->l&&fp->h==p->h)
             {
                 fp->r=p->r;
                 fp->next=p->next;
                     if(p==t)
                     t=fp;
                 delete p;
                 p=fp->next;
             }
                else
             {
                 fp=fp->next;
                 p=p->next;
             }
         }
         return ;
     }
 }
 void lnkList::dayin()
 {
     Link *p;
     p=head->next;
     printf("U %d\n",p->h);
     while(p->next!=NULL)
     {
         printf("R %d\n",p->r-p->l);
         if(p->r!=p->next->l)
         {
             printf("D %d\n",p->h);
             printf("R %d\n",p->next->l-p->r);
             printf("U %d\n",p->next->h);
         }
         else
         {
             if(p->next->h>p->h)
                 printf("U %d\n",p->next->h-p->h);
             else
                 printf("D %d\n",p->h-p->next->h);
         }
         p=p->next;
     }
     printf("R %d\n",p->r-p->l);
     printf("D %d\n",p->h);
     return ;
 }
 int main()
 {
     int a,b,c,i,n;
     lnkList biao;
     scanf("%d",&n);
     for(i=0;i<n;i++)            //��������
     {
         scanf("%d%d%d",&a,&b,&c);
         biao.append(a,b,c);
     }
     biao.lunkuo(biao.head,0,n-1,biao.tail); 
     biao.dayin();
     return 0;
 }
