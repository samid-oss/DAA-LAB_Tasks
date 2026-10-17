#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
struct Node{
int data;
char ch;
struct Node *left,*right;
};
struct Node* newNode(int data,char ch){
struct Node* node=(struct Node*)malloc(sizeof(struct Node));
node-&gt;data=data;
node-&gt;ch=ch;
node-&gt;left=node-&gt;right=NULL;
return node;
}
void sort(struct Node* a[],int n){
int i,j;
struct Node* temp;
for(i=0;i&lt;n-1;i++)
for(j=0;j&lt;n-i-1;j++)
if(a[j]-&gt;data&gt;a[j+1]-&gt;data){
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
void printCodes(struct Node* root,int code[],int top){
int i;
if(root-&gt;left){
code[top]=0;
printCodes(root-&gt;left,code,top+1);
}
if(root-&gt;right){
code[top]=1;
printCodes(root-&gt;right,code,top+1);
}
if(!root-&gt;left&amp;&amp;!root-&gt;right){
printf(&quot;%c: &quot;,root-&gt;ch);
for(i=0;i&lt;top;i++)
printf(&quot;%d&quot;,code[i]);

printf(&quot;\n&quot;);
}
}
int main(){
int n,i,code[100];
char ch;
struct Node* a[100];
printf(&quot;Enter number of characters: &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Enter character and frequency:\n&quot;);
for(i=0;i&lt;n;i++){
scanf(&quot; %c%d&quot;,&amp;ch,&amp;code[i]);
a[i]=newNode(code[i],ch);
}
while(n&gt;1){
sort(a,n);
struct Node* left=a[0];
struct Node* right=a[1];
struct Node* parent=newNode(left-&gt;data+right-&gt;data,&#39;$&#39;);
parent-&gt;left=left;
parent-&gt;right=right;
a[0]=parent;
for(i=1;i&lt;n-1;i++)
a[i]=a[i+1];
n--;
}
printf(&quot;Huffman Codes:\n&quot;);
printCodes(a[0],code,0);
return 0;
}
