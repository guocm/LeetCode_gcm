#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
const int N = 100005;
typedef long long LL;
const LL INF = (LL)1<<61;

int a[N];

class Trie
{
  public:
  Trie *next[2];
  Trie()
  {
    memset(next,NULL,sizeof(next));
  }
};

Trie *root;

void Insert(LL n)
{
  Trie *p = root;
  for(int i=31;i>=0;i--)
  {
    int id = (n >> i) & 1;
    if(p->next[id] == NULL)
       p->next[id] = new Trie();
    p = p->next[id];
  }
}

void Delete(Trie *T)
{
  if(T == NULL) return;
  for(int i=0;i<2;i++)
    if(T->next[i] != NULL)
      Delete(T->next[i]);
}

LL Match(LL m)
{
  m = ~m;
  LL ans = 0;
  Trie *p = root;
  for(int i=31;i>=0;i--)
  {
    ans <<= 1;
    int bit = (m >> i) & 1;
    if(bit)
    {
      if(p->next[1])
      {
        p = p->next[1];
        ans++;
      }
      else
      {
        p = p->next[0];
      }
    }
    else
    {
      if(p->next[0])
      {
        p = p->next[0];
        ans++;
      }
      else
      {
        p = p->next[1];
      }
    }
  }
  return ans;
}

int main()
{
  int n;
  while(scanf("%d",&n)!=EOF)
  {
    root = new Trie();
    for(int i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      Insert(a[i]);
    }
    LL ans = -INF;
    for(int i=0;i<n;i++)
      ans = max(ans,Match(a[i]));
    printf("%lld\n",ans);
    Delete(root);
  }
  return 0;
}