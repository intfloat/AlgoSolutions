#include<iostream>
#include<stdio.h>
 using namespace std;
 class Link                   //节点类
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
 class lnkList                 //链表类
 {
 public:
     Link *head,*tail;           //头、尾指针
     inline lnkList();
     inline bool append(int,int,int);          //在表尾添加一个元素
     void hebin(Link *,Link *,Link *&);     //合并两个子链
     //求kaishi到mowei间建筑的轮廓。尾指针传递的是引用，以使它便于维护
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
 //合并函数。将链表中的后半部分middle到t的建筑合并到前半部分h到middle中，然后删除后半部分
 void lnkList::hebin(Link *h,Link *middle,Link *&t)
 {
     Link *l,*r,*fl,*fr;        //指针及父指针
     Link *tem;
     fl=h;
     fr=middle;                //父指针
     l=fl->next;
     r=fr->next;
     Link *tt=new Link(t->l,t->r,r->h,t->next);
     while(l!=middle->next&&r!=tt->next)
     {
         //枚举两个建筑的位置关系
         //如果两个建筑相交，将未相交部分变成一个新的建筑，插入到链表中，同时缩小两个建筑
         //如果两个建筑是包含关系，删除被包含的建筑
         //如果两个建筑相离，就直接改变其相对位置即可
         if(l->l==r->l)              //两个建筑的左边相等
         {
             if(l->h>=r->h)
             {
                 if(l->r>=r->r)     //后一个建筑被前一个覆盖
                 {
                     if(l->r==r->r){      
                         fl=fl->next;
                         l=fl->next;
                     }
                     fr->next=r->next;      //删除后一个建筑
                     delete r;
                     r=fr->next;
                 }
                 else                   //两个建筑相交，缩小后一个建筑
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
             if(l->l<r->l)                 //前一个建筑的左边比后一个的小
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
                         tem=new Link(l->l,r->l,l->h);  //将未相交部分变成新的
                         fl->next=tem;                  //建筑，插入链表中
                         fl=tem;
                         tem->next=l;
                         l->l=r->l;
                     }
                 }
             }
             else                            //以下各种情况与上面类似
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
     if(r==tt->next)               //如果尾指针被delete掉，则使其复原，依旧指向尾部
         t=middle;
     delete tt;
     return ;
 }
 void lnkList::lunkuo(Link *h,int kaishi,int mowei,Link *&t)   
 {
     if(mowei>kaishi)
     {
         Link *middle=h;
         //确定中间建筑所在的节点
         for(int i=kaishi;i<=(kaishi+mowei)/2;i++)
             middle=middle->next;
           //递归求解前半部分和后半部分的建筑轮廓
         lunkuo(h,kaishi,(kaishi+mowei)/2,middle);
         lunkuo(middle,(kaishi+mowei)/2+1,mowei,t);
         hebin(h,middle,t);
           //合并链表中高度相同且首尾相连的建筑
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
     for(i=0;i<n;i++)            //输入数据
     {
         scanf("%d%d%d",&a,&b,&c);
         biao.append(a,b,c);
     }
     biao.lunkuo(biao.head,0,n-1,biao.tail); 
     biao.dayin();
     return 0;
 }
