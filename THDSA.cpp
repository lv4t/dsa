#include<iostream>
#include<string>
#include<stack>
using namespace std;

typedef struct Node
{
     string s;
     struct Node *left;
     struct Node *right;
}
tree;
typedef tree *cay;
tree *taonode(string s)
{
     tree *p=new tree;
     p->s = s;
     p->left = p->right = NULL;
     return p;
}
void taocay(cay &t)
{
     t=NULL;
}
int timdau(string s,int j)
{
     for(int i=j+1; i<s.size(); i++)
          if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='(')
               return i;
     return -1;
}
int timngoac(string s,int i)
{
    int j,dem=1; 
    for(j=i+1;j<s.size();j++)
    {
        if(s[j]=='(') dem++;
        else if(s[j]==')') dem--;
        if(dem==0) return j;
    }
    return -1;
}
void xulyngoac(string &s)
{
    if(s[0]=='(')
    {
        int i = timngoac(s,0);
        if(i == s.size()-1)
        {
            s.erase(0,1);
            s.erase(s.size()-1,1);
        }
    }
}
void doidau(string &c)
{
     int x=0;
     do{
          x=timdau(c,x);
          if(x!=-1)
          {
               if(c[x]=='(') x=timngoac(c,x);
               else if(c[x]=='-' && c[x-1]!='*' && c[x-1]!='/') c[x]='+';
               else if(c[x]=='+' && c[x-1]!='*' && c[x-1]!='/') c[x]='-';              
          }
     }while(x!=-1);
}
tree *xaydungcay(string s)
{
     xulyngoac(s);
     tree *p;
     int k,j,x;
     string a,b,c;
     int i=timdau(s,0);
     if(s[0]=='(') i=0;
     if(i==-1)// không dấu
     {
          p=taonode(s);
          return p;
     }
     else//có dấu, có 3 trường hợp
     {
          if(s[i]=='+' || s[i]=='-')      // dau =-
          {
               a=s[i];
               p=taonode(a);
               b=s.substr(0,i);
               xulyngoac(b);
               c=s.substr(i+1,s.size()-i-1);
               xulyngoac(c);
               //đổi dấu các số hạng phía sau nếu s[i] là dấu -
               if(s[i]=='-') doidau(c);
               p->left=xaydungcay(b);
               p->right=xaydungcay(c);
          }
          else if(s[i]=='*' || s[i]=='/')//dấu * hoặc /
          {
               k=i;
               //tìm vị trí dấu + hoặc - phía sau dấu ngoặc nhưng nằm ngoài dấu ngoặc
               do{
                    k=timdau(s,k);
                    if(k!=-1)
                    {
                         if(s[k]=='(') k=timngoac(s,k);
                         if(k>0 && (s[k]=='+' || s[k]=='-') && (s[k-1]!='*' && s[k-1]!='/')) break;
                    }
               }while(k!=-1);
               if(k==-1)//nếu không có 
               {
                    a=s[i];
                    p=taonode(a);
                    b=s.substr(0,i);
                    xulyngoac(b);
                    c=s.substr(i+1,s.size()-i-1);
                    xulyngoac(c);
                    p->left=xaydungcay(b);
                    p->right=xaydungcay(c); 
               }
               else//nếu tìm thấy 
               {
                    a=s[k];
                    p=taonode(a);
                    b=s.substr(0,k);
                    xulyngoac(b);
                    c=s.substr(k+1,s.size()-k-1);
                    xulyngoac(c);
                    //doi dau +-
                    if(s[k]=='-') doidau(c);
                    p->left=xaydungcay(b);
                    p->right=xaydungcay(c);
               }
          }
          else if(s[i]=='(')//dấu mở ngoặc (
          {
               j=timngoac(s,i);//tìm vị trí dấu đóng ngoặc
               
               if(s[j+1]=='+' || s[j+1]=='-')//sau dấu đóng ngoặc là dấu + hoặc - thì tree là dấu + hoặc -
               {
                    a=s[j+1];
                    p=taonode(a);
                    b=s.substr(0,j+1);
                    xulyngoac(b);
                    c=s.substr(j+2,s.size()-j-2);
                    xulyngoac(c);
                    //doi dau +-
                    if(s[j+1]=='-') doidau(c);
                    p->left=xaydungcay(b);
                    p->right=xaydungcay(c);
               }
               else if(s[j+1]=='*' || s[j+1]=='/')//nếu sau đóng ngoặc là * hoặc /
               {
                    k=j+1;
                    do{
                         k=timdau(s,k);
                         if(k!=-1)
                         {
                              if(s[k]=='(') k=timngoac(s,k);
                              if(k>0 && (s[k]=='+' || s[k]=='-') && (s[k-1]!='*' && s[k-1]!='/')) break;
                         }
                    }while(k!=-1);
                    if(k==-1)
                    {
                         a=s[j+1];
                         p=taonode(a);
                         b=s.substr(0,j+1);
                         xulyngoac(b);
                         c=s.substr(j+2,s.size()-j-2);
                         xulyngoac(c);
                         p->left=xaydungcay(b);
                         p->right=xaydungcay(c);
                    }
                    else
                    {
                         a=s[k];
                         p=taonode(a);
                         b=s.substr(0,k);
                         xulyngoac(b);
                         c=s.substr(k+1,s.size()-k-1);
                         xulyngoac(c);
                         //doi dau +-
                         if(s[j+1]=='-') doidau(c);
                         p->left=xaydungcay(b);
                         p->right=xaydungcay(c);
                    }
               }
          }
     }
     return p;
}

long chuyendoi(string s)
{
     long x=0,d=1;
     int j=0,k=0;
     if(s[0]=='+' || s[0]=='-')
     {
          j=1;
          if(s[0]=='-') k=1;
     }
     for(int i=s.size()-1;i>=j;i--)
     {
          switch(s[i])
          {
          case '0':x+=0*d;break;
          case '1':x+=1*d;break;
          case '2':x+=2*d;break;
          case '3':x+=3*d;break;
          case '4':x+=4*d;break;
          case '5':x+=5*d;break;
          case '6':x+=6*d;break;
          case '7':x+=7*d;break;
          case '8':x+=8*d;break;
          case '9':x+=9*d;break;
          }
          d*=10;
     }
     if(k==0)return x;
     return -x;
}
long tinh(cay t)
{
     long x;
     if(t)
     {
          if(t->s=="+") return tinh(t->left)+tinh(t->right);
          else if(t->s=="-") return tinh(t->left)-tinh(t->right);
          else if(t->s=="*") return tinh(t->left)*tinh(t->right);
          else if(t->s=="/") return tinh(t->left)/tinh(t->right);
          else return chuyendoi(t->s);
     }
     return 0;
}
void duyetLNR(Node* m) {
    if (m != NULL) {
        duyetLNR(m->left);
        cout << m->s << " ";
        duyetLNR(m->right);
    }
}
int main()
{
     cay t;
     taocay(t);
     string s;
     cout<<"nhap bieu thuc can tinh:\n";
     getline(cin,s);
     t=xaydungcay(s);
     cout<<"gia tri bieu thuc = "<<tinh(t)<<endl;
    Node* m = xaydungcay(s);
   /* cout << "Cay duoc tao thanh tu bieu thuc " << s << " là:" << endl;
    cout << "      " << s->s << endl;
    cout << "     / \\" << endl;
    cout << "    " << s->left->s << "   " << s->right->s << endl;
    cout << "   / \\  " << endl;
    cout << "  " << s->left->left->s << "   " << s->left->right->s << endl;
    return 0;*/
    cout << "Duyet cay nhi phan sau khi tao: ";
     duyetLNR(m);
            cout << endl;
system("pause");
}